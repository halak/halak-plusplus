#include <Halak.Toolkit/PCH.h>
#include <Halak.Toolkit/PhotoshopLayers.h>
#include <Halak.Toolkit/PhotoshopDocument.h>
#include <Halak.Toolkit/PhotoshopDocumentReader.h>
#include <Halak/Assert.h>
#include <Halak/Exception.h>
#include <Halak/MemoryTexture2D.h>
#include <algorithm>

namespace Halak
{
    namespace Toolkit
    {
        PhotoshopChannel::PhotoshopChannel(ID id, unsigned int size)
            : id(id),
              size(size),
              width(0),
              height(0),
              bitsPerPixel(0)
        {
        }

        PhotoshopChannel::~PhotoshopChannel()
        {
        }

        void PhotoshopChannel::ReadPixelData(int width, int height, int bitsPerPixel, PhotoshopDocumentReader& reader)
        {
            this->width        = width;
            this->height       = height;
            this->bitsPerPixel = bitsPerPixel;

            const PhotoshopDocument::CompressionMode compression = (PhotoshopDocument::CompressionMode)reader.ReadInt16();

            if (width == 0 || height == 0)
                return;

            switch (compression)
            {
                case PhotoshopDocument::NoCompression:
                    bitmap = reader.ReadRawPixelData(width, height, bitsPerPixel);
                    break;
                case PhotoshopDocument::RLECompression:
                    reader.Seek(height * 2);
                    bitmap = reader.ReadRLECompressedPixelData(width, height, bitsPerPixel);
                    break;
                default:
                    throw std::runtime_error("compression");
            }
        }

        PhotoshopChannel::ID PhotoshopChannel::GetID() const
        {
            return id;
        }

        unsigned int PhotoshopChannel::GetSize() const
        {
            return size;
        }

        int PhotoshopChannel::GetWidth() const
        {
            return width;
        }

        int PhotoshopChannel::GetHeight() const
        {
            return height;
        }

        int PhotoshopChannel::GetBitsPerPixel() const
        {
            return bitsPerPixel;
        }

        const std::vector<byte>& PhotoshopChannel::GetBitmap() const
        {
            return bitmap;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        PhotoshopLayer::PhotoshopLayer(PhotoshopDocumentReader& reader)
            : name(),
              rectangle(Rectangle::Empty),
              opacity(0),
              blendMode(),
              clipping(false),
              transparencyProtected(false),
              visible(false),
              isGroup(false)
        {
            rectangle = reader.ReadRectangle();

            unsigned short numberOfChannels = reader.ReadUInt16();
            if (numberOfChannels)
            {
                channels.reserve(numberOfChannels);
                for (unsigned short i = 0; i < numberOfChannels; i++)
                {
                    const PhotoshopChannel::ID id = (PhotoshopChannel::ID)reader.ReadInt16();
                    const unsigned int size = reader.ReadUInt32();
                    channels.push_back(PhotoshopChannelPtr(new PhotoshopChannel(id, size)));
                }
            }

            // Layer의 기본 정보를 읽어옵니다.
            const uint32 signature = reader.ReadFOURCC();
            if (signature != HKMakeFOURCC('8', 'B', 'I', 'M'))
                throw std::runtime_error("Channel 정보가 올바르지 않습니다.");

            blendMode = reader.ReadChars(4);
            opacity   = reader.ReadByte();
            clipping  = reader.ReadByte() != 0;

            const byte flags = reader.ReadByte();
            transparencyProtected = (flags & (0x01 << 0)) != 0x00;
            visible = (flags & (0x01 << 1)) == 0x00;
            isGroup = (flags & (0x01 << 4)) != 0x00;

            reader.Seek(1); // 한 byte 건너뛰기

            // Layer의 추가 정보를 읽어옵니다.
            if (const unsigned int extraDataSize = reader.ReadUInt32())
            {
                const unsigned int extraDataEndPosition = reader.GetPosition() + extraDataSize;

                // Mask 정보
                if (const unsigned int maskSize = reader.ReadUInt32())
                {
                    const unsigned int maskEndPosition = reader.GetPosition() + maskSize;

                    const Rectangle maskRectangle = reader.ReadRectangle();
                    const byte maskDefaultColor   = reader.ReadByte();
                    const byte maskFlags          = reader.ReadByte();

                    const bool positionRelativeToLayer = (maskFlags & (0x01 << 0)) != 0x00;
                    const bool maskDisabled            = (maskFlags & (0x01 << 1)) != 0x00;
                    const bool maskInvertWhenBlending  = (maskFlags & (0x01 << 2)) != 0x00;

                    mask = PhotoshopMaskPtr(new PhotoshopMask(maskRectangle,
                                                              maskDefaultColor,
                                                              positionRelativeToLayer,
                                                              maskDisabled,
                                                              maskInvertWhenBlending));

                    reader.SetPosition(maskEndPosition);
                }

                // Blend Range 정보 (필요한 정보가 없으므로 건너뜁니다.)
                if (const unsigned int blendRangeSize = reader.ReadUInt32())
                {
                    const unsigned int blendRangeEndPosition = reader.GetPosition() + blendRangeSize;
                    reader.SetPosition(blendRangeEndPosition);
                }

                // Layer 이름
                {
                    const unsigned int namePosition = reader.GetPosition();
                    name = reader.ReadPSDString();
                    reader.SetPosition(reader.GetPosition() + (reader.GetPosition() - namePosition) % 4);
                }

                // Adjustment 정보 (필요한 정보가 없으므로 건너뜁니다.)
                if (const unsigned int adjustmentSize = reader.ReadUInt32())
                {
                    const unsigned int adjustmentEndPosition = reader.GetPosition() + adjustmentSize;
                    
                    for (;;)
                    {
                        uint32 signature = reader.ReadFOURCC();
                        if (signature != HKMakeFOURCC('8', 'B', 'I', 'M'))
                        {
                            // 이유는 아직 모르겠음
                            reader.SetPosition(reader.GetPosition() - 6);
                            signature = reader.ReadFOURCC();
                        }

                        if (signature == HKMakeFOURCC('8', 'B', 'I', 'M'))
                        {
                            const uint32 key = reader.ReadFOURCC();
                            const uint additionalLayerInfoSize = reader.ReadUInt32();
                            const uint additionalLayerEndPosition = reader.GetPosition() + additionalLayerInfoSize;

                            switch (key)
                            {
                                case HKMakeFOURCC('l', 'f', 'x', '2'):
                                    {
                                        const uint32 objectBasedEffectversion = reader.ReadUInt32();
                                        const uint32 descriptorVersion = reader.ReadUInt32();
                                        const String name = reader.ReadUnicodeString();
                                        const uint32 classIDLength = reader.ReadUInt32();
                                        if (classIDLength == 0)
                                        {
                                            String c = reader.ReadChars(4);
                                            c =c ;
                                        }
                                        else
                                        {
                                            String c = reader.ReadPSDString();
                                            c = c;
                                        }
                                        const uint numberOfDescriptors = reader.ReadUInt32();
                                        for (uint i = 0; i < numberOfDescriptors; i++)
                                        {
                                            const uint32 keyLength = reader.ReadUInt32();
                                            if (keyLength == 0)
                                            {
                                                String c = reader.ReadChars(4);
                                                c =c ;
                                            }
                                            else
                                            {
                                                //reader.SetPosition(reader.GetPosition() - 4);
                                                String c = reader.ReadChars(keyLength);
                                                c = c;
                                            }

                                            const uint32 osTypeKey = reader.ReadFOURCC();
                                            switch (osTypeKey)
                                            {
                                                case HKMakeFOURCC('o', 'b', 'j', ' '):
                                                    reader.SetPosition(reader.GetPosition() + 0);
                                                    break;
                                                case HKMakeFOURCC('O', 'b', 'j', 'c'):
                                                    reader.SetPosition(reader.GetPosition() + 0);
                                                    break;
                                                case HKMakeFOURCC('V', 'l', 'L', 's'):
                                                    reader.SetPosition(reader.GetPosition() + 0);
                                                    break;
                                                case HKMakeFOURCC('d', 'o', 'u', 'b'):
                                                    reader.SetPosition(reader.GetPosition() + 0);
                                                    break;
                                                case HKMakeFOURCC('U', 'n', 't', 'F'):
                                                    reader.SetPosition(reader.GetPosition() + 12);
                                                    break;
                                                case HKMakeFOURCC('T', 'E', 'X', 'T'):
                                                    reader.SetPosition(reader.GetPosition() + 0);
                                                    break;
                                                case HKMakeFOURCC('e', 'n', 'u', 'm'):
                                                    reader.SetPosition(reader.GetPosition() + 0);
                                                    break;
                                                case HKMakeFOURCC('l', 'o', 'n', 'g'):
                                                    reader.SetPosition(reader.GetPosition() + 0);
                                                    break;
                                                case HKMakeFOURCC('b', 'o', 'o', 'l'):
                                                    reader.SetPosition(reader.GetPosition() + 1);
                                                    break;
                                                case HKMakeFOURCC('G', 'l', 'b', 'O'):
                                                    reader.SetPosition(reader.GetPosition() + 0);
                                                    break;
                                                case HKMakeFOURCC('t', 'y', 'p', 'e'):
                                                case HKMakeFOURCC('G', 'l', 'b', 'C'):
                                                    reader.SetPosition(reader.GetPosition() + 0);
                                                    break;
                                                case HKMakeFOURCC('a', 'l', 'i', 's'):
                                                    reader.SetPosition(reader.GetPosition() + 0);
                                                    break;
                                            }
                                        }
                                    }
                                    break;
                                case HKMakeFOURCC('l', 'r', 'F', 'X'):
                                    {
                                    }
                                    break;
                                case HKMakeFOURCC('T', 'y', 'S', 'h'):
                                    {
                                        const uint16 version = reader.ReadUInt16();
                                        const double xx = reader.ReadDouble();
                                        const double xy = reader.ReadDouble();
                                        const double yx = reader.ReadDouble();
                                        const double yy = reader.ReadDouble();
                                        const double tx = reader.ReadDouble();
                                        const double ty = reader.ReadDouble();
                                        const uint16 textVersion = reader.ReadUInt16();
                                        uint32 descriptorVersion = reader.ReadUInt32();
                                        descriptorVersion = descriptorVersion;
                                    }
                                    break;
                            }

                            reader.SetPosition(additionalLayerEndPosition);
                        }
                        else
                            break;
                    }

                    reader.SetPosition(adjustmentEndPosition);
                }

                reader.SetPosition(extraDataEndPosition);
            }
        }

        PhotoshopLayer::~PhotoshopLayer()
        {
        }

        void PhotoshopLayer::ReadPixelData(int bitsPerPixel, PhotoshopDocumentReader& reader)
        {
            for (std::vector<PhotoshopChannelPtr>::iterator it = channels.begin(); it != channels.end(); it++)
            {
                PhotoshopChannelPtr channel = (*it);

                if( channel->GetID() == PhotoshopChannel::UserSuppliedLayerMask ||
                    channel->GetID() == PhotoshopChannel::UserSuppliedVectorMask )
                    continue;

                channel->ReadPixelData(rectangle.Width, rectangle.Height, bitsPerPixel, reader);
            }

            if (rectangle.Width != 0 && rectangle.Height != 0)
            {
                if (GetChannel(PhotoshopChannel::TransparencyMask))
                {
                    // Merge to transparency bitmap.
                }
                else
                {
                    // Merge to bitmap.
                }
            }

            if (mask)
                mask->ReadPixelData(GetChannel(PhotoshopChannel::UserSuppliedLayerMask), bitsPerPixel, reader);
        }

        void PhotoshopLayer::AddSubLayer(PhotoshopLayerPtr item)
        {
            HKAssert(item->group.IsAlive() == false);
            HKAssert(std::find(subLayers.begin(), subLayers.end(), item) == subLayers.end());

            subLayers.push_back(item);
            item->group = This<PhotoshopLayer>();
        }

        bool PhotoshopLayer::RemoveSubLayer(PhotoshopLayerPtr item)
        {
            std::vector<PhotoshopLayerPtr>::iterator it = std::find(subLayers.begin(), subLayers.end(), item);
            if (it != subLayers.end())
            {
                subLayers.push_back(item);
                return true;
            }
            else
                return false;
        }

        PhotoshopLayer* PhotoshopLayer::FindSubLayer(const String& name) const
        {
            for (std::vector<PhotoshopLayerPtr>::const_iterator it = subLayers.begin(); it != subLayers.end(); it++)
            {
                if ((*it)->GetName() == name)
                    return *it;
            }

            return nullptr;
        }

        const String& PhotoshopLayer::GetName() const
        {
            return name;
        }

        const Rectangle& PhotoshopLayer::GetRectangle() const
        {
            return rectangle;
        }

        const String& PhotoshopLayer::GetBlendMode() const
        {
            return blendMode;
        }

        byte PhotoshopLayer::GetOpacity() const
        {
            return opacity;
        }

        bool PhotoshopLayer::GetClipping() const
        {
            return clipping;
        }
        
        bool PhotoshopLayer::GetTransparencyProtected() const
        {
            return transparencyProtected;
        }

        bool PhotoshopLayer::GetVisible() const
        {
            return visible;
        }

        bool PhotoshopLayer::IsGroup() const
        {
            return isGroup;
        }
                    
        const std::vector<PhotoshopChannelPtr>& PhotoshopLayer::GetChannels() const
        {
            return channels;
        }

        PhotoshopChannel* PhotoshopLayer::GetChannel(const PhotoshopChannel::ID id) const
        {
            for (std::vector<PhotoshopChannelPtr>::const_iterator it = channels.begin(); it != channels.end(); it++)
            {
                if( (*it)->GetID() == id )
                    return (*it);
            }

            return nullptr;
        }
        
        PhotoshopMask* PhotoshopLayer::GetMask() const
        {
            return mask;
        }

        Rectangle PhotoshopLayer::GetUnionRectangle() const
        {
            Rectangle result = GetRectangle();
            for (std::vector<PhotoshopLayerPtr>::const_iterator it = subLayers.begin(); it != subLayers.end(); it++)
            {
                if (result.IsEmpty())
                    result = (*it)->GetUnionRectangle();
                else
                    result = Rectangle::Union(result, (*it)->GetUnionRectangle());
            }

            return result;
        }

        PhotoshopLayer* PhotoshopLayer::GetGroup() const
        {
            return group;
        }

        const std::vector<PhotoshopLayerPtr>& PhotoshopLayer::GetSubLayers() const
        {
            return subLayers;
        }

        Texture2DPtr PhotoshopLayer::ToTexture(GraphicsDevice* graphicsDevice) const
        {
            if (IsGroup())
                return nullptr;
            if (rectangle.IsEmpty())
                return nullptr;

            PhotoshopChannelPtr r = GetChannel(PhotoshopChannel::RedChannel);
            PhotoshopChannelPtr g = GetChannel(PhotoshopChannel::GreenChannel);
            PhotoshopChannelPtr b = GetChannel(PhotoshopChannel::BlueChannel);
            PhotoshopChannelPtr a = GetChannel(PhotoshopChannel::TransparencyMask);
            if (r && g && b)
            {
                if (a)
                    return Texture2DPtr(new MemoryTexture2D(graphicsDevice, rectangle.Width, rectangle.Height, rectangle.Width, r->GetBitmap(), g->GetBitmap(), b->GetBitmap(), a->GetBitmap()));
                else
                    return Texture2DPtr(new MemoryTexture2D(graphicsDevice, rectangle.Width, rectangle.Height, rectangle.Width, r->GetBitmap(), g->GetBitmap(), b->GetBitmap()));
            }
            else
                return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        
        PhotoshopMask::PhotoshopMask(const Rectangle& rectangle, byte defaultColor, bool positionRelativeToLayer, bool disabled, bool invertWhenBlending)
            : rectangle(rectangle),
              defaultColor(defaultColor),
              positionRelativeToLayer(positionRelativeToLayer),
              disabled(disabled),
              invertWhenBlending(invertWhenBlending)
        {
        }

        PhotoshopMask::~PhotoshopMask()
        {
        }

        void PhotoshopMask::ReadPixelData(PhotoshopChannelPtr channel, int bitsPerPixel, PhotoshopDocumentReader& reader)
        {
            this->channel = channel;
            this->channel->ReadPixelData(rectangle.Width, rectangle.Height, bitsPerPixel, reader);
        }

        const Rectangle& PhotoshopMask::GetRectangle() const
        {
            return rectangle;
        }

        byte PhotoshopMask::GetDefaultColor() const
        {
            return defaultColor;
        }

        bool PhotoshopMask::GetPositionRelativeToLayer() const
        {
            return positionRelativeToLayer;
        }

        bool PhotoshopMask::GetDisabled() const
        {
            return disabled;
        }

        bool PhotoshopMask::GetInvertWhenBlending() const
        {
            return invertWhenBlending;
        }

        PhotoshopChannelPtr PhotoshopMask::GetChannel() const
        {
            return channel;
        }
    }
}