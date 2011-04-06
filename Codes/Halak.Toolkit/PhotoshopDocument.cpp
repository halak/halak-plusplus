#include <TH/Documents/Adobe/PhotoshopDocument.h>
#include <TH/Documents/Adobe/PhotoshopDocumentReader.h>
#include <TH/Documents/Adobe/PhotoshopLayers.h>
#include <TH/Documents/Adobe/PhotoshopImageResources.h>
#include <Halak/FOURCC.h>
#include <Halak/MemoryTexture2D.h>
#include <stack>
using namespace Halak;

namespace TH
{
    namespace Documents
    {
        namespace Adobe
        {
            PhotoshopDocument::PhotoshopDocument(const String& filename)
                : filename(filename),
                  channels(0),
                  width(0),
                  height(0),
                  bitsPerPixel(0),
                  colorMode(PhotoshopColorMode::Grayscale),
                  importingElements(PhotoshopDocumentElements::All)
            {
                Reload();
            }

            PhotoshopDocument::PhotoshopDocument(const String& filename, PhotoshopDocumentElements::E importingElements)
                : filename(filename),
                  channels(0),
                  width(0),
                  height(0),
                  bitsPerPixel(0),
                  colorMode(PhotoshopColorMode::Grayscale),
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

                // PSD���� �˻��մϴ�.
                {
                    const uint32 signature = reader.ReadFOURCC();
                    if (signature != HKMakeFOURCC('8', 'B', 'P', 'S'))
                        throw std::runtime_error("�ùٸ� PSD File�� �ƴմϴ�.");

                    const short version = reader.ReadInt16();
                    if (version != 1)
                        throw std::runtime_error("�о�� �� ���� Version�Դϴ�.");
                }

                // Header�� �о�ɴϴ�.
                {
                    reader.Seek(6); // �����

                    channels = reader.ReadInt16();
                    height   = reader.ReadInt32();
                    width    = reader.ReadInt32();
                    bitsPerPixel = reader.ReadInt16();
                    colorMode = static_cast<PhotoshopColorMode::E>(reader.ReadInt16());

                    if (colorMode != PhotoshopColorMode::RGB)
                        throw std::runtime_error("RGB Color Format�� �о�� �� �ֽ��ϴ�.");
                    if (bitsPerPixel != 8)
                        throw std::runtime_error("�� Channel�� Pixel�� 1Byte�� �о�� �� �ֽ��ϴ�.");
                }

                // ColorModeData�� �о�ɴϴ�. (�ѱ�ϴ�)
                if (const unsigned int sectionSize = reader.ReadUInt32())
                {
                    const unsigned int sectionEndPosition = reader.GetPosition() + sectionSize;
                    if (GetImportingElements() & PhotoshopDocumentElements::ColorModeData)
                    {
                    }
                    reader.SetPosition(sectionEndPosition);
                }

                // ImageResource���� �о�ɴϴ�.
                imageResources.clear();
                if (const unsigned int sectionSize = reader.ReadUInt32())
                {
                    const unsigned int sectionEndPosition = reader.GetPosition() + sectionSize;
                    if (GetImportingElements() & PhotoshopDocumentElements::ImageResource)
                    {
                        while (reader.GetPosition() < sectionEndPosition)
                        {
                            const uint32 signature = reader.ReadFOURCC();
                            if (signature != HKMakeFOURCC('8', 'B', 'I', 'M') && signature != HKMakeFOURCC('M', 'e', 'S', 'a'))
                                throw std::runtime_error("�ùٸ��� ���� ImageResource�� �����մϴ�.");

                            const PhotoshopImageResourceID::E id = static_cast<PhotoshopImageResourceID::E>(reader.ReadInt16());
                            const String name = reader.ReadPascalString();
                            const unsigned int size = reader.ReadUInt32();
                            const unsigned int endPosition = reader.GetPosition() + size;
                            if (size > 0)
                            {
                                if (PhotoshopImageResourcePtr resource = PhotoshopImageResource::Create(id, name, size, reader))
                                    imageResources.push_back(resource);
                            }

                            // ��ġ�� ¦���� ����ϴ�.
                            if (endPosition % 2 == 0)
                                reader.SetPosition(endPosition);
                            else
                                reader.SetPosition(endPosition + 1);
                        }
                    }
                    reader.SetPosition(sectionEndPosition);
                }

                // Layer�� Mask ������ �о�ɴϴ�.
                layers.clear();
                if (const unsigned int sectionSize = reader.ReadUInt32())
                {
                    const unsigned int sectionEndPosition = reader.GetPosition() + sectionSize;
                    if (GetImportingElements() & PhotoshopDocumentElements::Layer)
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

                            // Layer���� �⺻ ������ �о �����մϴ�.
                            for (short i = 0; i < numberOfLayers; i++)
                                layers.push_back(PhotoshopLayerPtr(new PhotoshopLayer(reader)));

                            // Layer���� Pixel ������ �о�ɴϴ�.
                            for (std::vector<PhotoshopLayerPtr>::iterator it = layers.begin(); it != layers.end(); it++)
                                (*it)->ReadPixelData(bitsPerPixel, reader);

                            // Group���� �����մϴ�.
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

                        // Layer Global Mask ������ �о�ɴϴ�. (�����մϴ�)
                    }
                    reader.SetPosition(sectionEndPosition);
                }

                // PSD �������� �ִ� ������ Image�� �о�ɴϴ�.
                if (GetImportingElements() & PhotoshopDocumentElements::MergedImage)
                {
                    const PhotoshopCompression::E compression = static_cast<PhotoshopCompression::E>(reader.ReadInt16());

                    mergedImage.resize(channels);

                    switch (compression)
                    {
                        case PhotoshopCompression::RawData:
                            for (std::vector<ByteVector>::iterator it = mergedImage.begin(); it != mergedImage.end(); it++)
                                (*it) = reader.ReadRawPixelData(width, height, bitsPerPixel);
                            break;
                        case PhotoshopCompression::RLECompression:
                            // �ະ�� ���� ���̰� ��ϵǾ� �ֽ��ϴٸ� �����մϴ�.
                            reader.Seek(height * channels * 2);
                            for (std::vector<ByteVector>::iterator it = mergedImage.begin(); it != mergedImage.end(); it++)
                                (*it) = reader.ReadRLECompressedPixelData(width, height, bitsPerPixel);
                            break;
                        default:
                            throw std::runtime_error("�������� �ʴ� ��������");
                    }
                }
                else
                    mergedImage.clear();
            }

            const Halak::String& PhotoshopDocument::GetFilename() const
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

            PhotoshopColorMode::E PhotoshopDocument::GetColorMode() const
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

            PhotoshopDocumentElements::E PhotoshopDocument::GetImportingElements() const
            {
                return importingElements;
            }

            void PhotoshopDocument::SetImportingElements(PhotoshopDocumentElements::E value)
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
}