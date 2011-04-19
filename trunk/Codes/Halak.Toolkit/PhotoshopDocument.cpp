#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/PhotoshopDocument.h>
#include <Halak.Toolkit/PhotoshopDocumentReader.h>
#include <Halak.Toolkit/PhotoshopLayers.h>
#include <Halak.Toolkit/PhotoshopImageResources.h>
#include <Halak/MemoryTexture2D.h>
#include <stack>

namespace Halak
{
    namespace Toolkit
    {
        PhotoshopDocument::PhotoshopDocument(const String& filename)
            : filename(filename),
              channels(0),
              width(0),
              height(0),
              bitsPerPixel(0),
              colorMode(GrayscaleColor),
              importingElements(AllElements)
        {
            Reload();
        }

        PhotoshopDocument::PhotoshopDocument(const String& filename, Elements importingElements)
            : filename(filename),
              channels(0),
              width(0),
              height(0),
              bitsPerPixel(0),
              colorMode(GrayscaleColor),
              importingElements(importingElements)
        {
            Reload();
        }

        PhotoshopDocument::~PhotoshopDocument()
        {
        }

        void PhotoshopDocument::Reload()
        {
            PhotoshopDocumentReader reader(filename);

            // PSD인지 검사합니다.
            {
                const uint32 signature = reader.ReadFOURCC();
                if (signature != HKMakeFOURCC('8', 'B', 'P', 'S'))
                    throw std::runtime_error("올바른 PSD File이 아닙니다.");

                const short version = reader.ReadInt16();
                if (version != 1)
                    throw std::runtime_error("읽어올 수 없는 Version입니다.");
            }

            // Header를 읽어옵니다.
            {
                reader.Seek(6); // 예약분

                channels = reader.ReadInt16();
                height   = reader.ReadInt32();
                width    = reader.ReadInt32();
                bitsPerPixel = reader.ReadInt16();
                colorMode = static_cast<ColorMode>(reader.ReadInt16());

                if (colorMode != RGBColor)
                    throw std::runtime_error("RGB Color Format만 읽어올 수 있습니다.");
                if (bitsPerPixel != 8)
                    throw std::runtime_error("한 Channel의 Pixel이 1Byte만 읽어올 수 있습니다.");
            }

            // ColorModeData를 읽어옵니다. (넘깁니다)
            if (const unsigned int sectionSize = reader.ReadUInt32())
            {
                const unsigned int sectionEndPosition = reader.GetPosition() + sectionSize;
                if (GetImportingElements() & ColorModeDataElement)
                {
                }
                reader.SetPosition(sectionEndPosition);
            }

            // ImageResource들을 읽어옵니다.
            imageResources.clear();
            if (const unsigned int sectionSize = reader.ReadUInt32())
            {
                const unsigned int sectionEndPosition = reader.GetPosition() + sectionSize;
                if (GetImportingElements() & ImageResourceElement)
                {
                    while (reader.GetPosition() < sectionEndPosition)
                    {
                        const uint32 signature = reader.ReadFOURCC();
                        if (signature != HKMakeFOURCC('8', 'B', 'I', 'M') && signature != HKMakeFOURCC('M', 'e', 'S', 'a'))
                            throw std::runtime_error("올바르지 않은 ImageResource가 존재합니다.");

                        const PhotoshopImageResource::Type type = static_cast<PhotoshopImageResource::Type>(reader.ReadInt16());
                        const String name = reader.ReadPascalString();
                        const unsigned int size = reader.ReadUInt32();
                        const unsigned int endPosition = reader.GetPosition() + size;
                        if (size > 0)
                        {
                            if (PhotoshopImageResourcePtr resource = PhotoshopImageResource::Create(type, name, size, reader))
                                imageResources.push_back(resource);
                        }

                        // 위치는 짝수로 맞춥니다.
                        if (endPosition % 2 == 0)
                            reader.SetPosition(endPosition);
                        else
                            reader.SetPosition(endPosition + 1);
                    }
                }
                reader.SetPosition(sectionEndPosition);
            }

            // Layer와 Mask 정보를 읽어옵니다.
            layers.clear();
            if (const unsigned int sectionSize = reader.ReadUInt32())
            {
                const unsigned int sectionEndPosition = reader.GetPosition() + sectionSize;
                if (GetImportingElements() & LayerElement)
                {
                    if (const unsigned int layersSize = reader.ReadUInt32())
                    {
                        const unsigned int layersEndPosition = reader.GetPosition() + layersSize;

                        bool  absoluteAlpha  = false;
                        short numberOfLayers = reader.ReadInt16();
                        if (numberOfLayers < 0)
                        {
                            absoluteAlpha  = true;
                            numberOfLayers = -numberOfLayers;
                        }

                        // Layer들의 기본 정보를 읽어서 보관합니다.
                        for (short i = 0; i < numberOfLayers; i++)
                            layers.push_back(PhotoshopLayerPtr(new PhotoshopLayer(reader)));

                        // Layer들의 Pixel 정보를 읽어옵니다.
                        for (std::vector<PhotoshopLayerPtr>::iterator it = layers.begin(); it != layers.end(); it++)
                            (*it)->ReadPixelData(bitsPerPixel, reader);

                        // Group들을 정리합니다.
                        std::stack<PhotoshopLayerPtr> layerStack;
                        for (int i = static_cast<int>(layers.size()) - 1; i >= 0; i--)
                        {
                            PhotoshopLayerPtr item = layers[i];
                            const bool isEndLayerSetTag = item->GetName() == "</Layer set>" ||
                                                          item->GetName() == "</Layer group>";

                            if (layerStack.empty() == false && isEndLayerSetTag == false)
                                layerStack.top()->AddSubLayer(item);

                            if (item->IsGroup())
                            {
                                if (isEndLayerSetTag == false)
                                    layerStack.push(item);
                                else
                                {
                                    layerStack.pop();
                                    layers.erase(layers.begin() + i);
                                }
                            }
                        }

                        for (std::vector<PhotoshopLayerPtr>::iterator it = layers.begin(); it != layers.end();)
                        {
                            if ((*it)->GetGroup().IsAlive())
                                it = layers.erase(it);
                            else
                                it++;
                        }

                        reader.SetPosition(layersEndPosition);
                    }

                    // Layer Global Mask 정보를 읽어옵니다. (무시합니다)
                }
                reader.SetPosition(sectionEndPosition);
            }

            // PSD 마지막에 있는 합쳐진 Image를 읽어옵니다.
            if (GetImportingElements() & MergedImageElement)
            {
                const CompressionMode compression = static_cast<CompressionMode>(reader.ReadInt16());

                mergedImage.resize(channels);

                switch (compression)
                {
                    case NoCompression:
                        for (std::vector<ByteVector>::iterator it = mergedImage.begin(); it != mergedImage.end(); it++)
                            (*it) = reader.ReadRawPixelData(width, height, bitsPerPixel);
                        break;
                    case RLECompression:
                        // 행별로 열의 길이가 기록되어 있습니다만 무시합니다.
                        reader.Seek(height * channels * 2);
                        for (std::vector<ByteVector>::iterator it = mergedImage.begin(); it != mergedImage.end(); it++)
                            (*it) = reader.ReadRLECompressedPixelData(width, height, bitsPerPixel);
                        break;
                    default:
                        throw std::runtime_error("지원하지 않는 압축포맷");
                }
            }
            else
                mergedImage.clear();
        }

        const String& PhotoshopDocument::GetFilename() const
        {
            return filename;
        }

        int PhotoshopDocument::GetNumberOfChannels() const
        {
            return channels;
        }

        int PhotoshopDocument::GetWidth() const
        {
            return width;
        }
        
        int PhotoshopDocument::GetHeight() const
        {
            return height;
        }
        
        int PhotoshopDocument::GetBitsPerPixel() const
        {
            return bitsPerPixel;
        }

        PhotoshopDocument::ColorMode PhotoshopDocument::GetColorMode() const
        {
            return colorMode;
        }

        const std::vector<PhotoshopImageResourcePtr> PhotoshopDocument::GetImageResources() const
        {
            return imageResources;
        }
        
        const std::vector<PhotoshopLayerPtr> PhotoshopDocument::GetLayers() const
        {
            return layers;
        }

        PhotoshopDocument::Elements PhotoshopDocument::GetImportingElements() const
        {
            return importingElements;
        }

        void PhotoshopDocument::SetImportingElements(PhotoshopDocument::Elements value)
        {
            if (GetImportingElements() != value)
            {
                importingElements = value;
                Reload();
            }
        }

        Texture2DPtr PhotoshopDocument::ToTexture(GraphicsDevice* graphicsDevice) const
        {
            if (mergedImage.size() == 3)
                return Texture2DPtr(new MemoryTexture2D(graphicsDevice, width, height, width, mergedImage[0], mergedImage[1], mergedImage[2]));
            else if (mergedImage.size() >= 4)
                return Texture2DPtr(new MemoryTexture2D(graphicsDevice, width, height, width, mergedImage[0], mergedImage[1], mergedImage[2], mergedImage[3]));
            else
                return nullptr;
        }
    }
}