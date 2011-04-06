#pragma once
#ifndef __HALAK_TOOLKIT_PHOTOSHOPLAYERS_H__
#define __HALAK_TOOLKIT_PHOTOSHOPLAYERS_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/Asset.h>
#   include <Halak/Rectangle.h>
#   include <Halak/String.h>
#   include <vector>

    namespace Halak
    {
        namespace Toolkit
        {
            class PhotoshopChannel : public Asset
            {
                public:
                    enum ID
                    {
                        RedChannel    = 0,
                        GreenChannel  = 1,
                        BlueChannel   = 2,
                        TransparencyMask       = -1,
                        UserSuppliedLayerMask  = -2,
                        UserSuppliedVectorMask = -3,
                    };

                public:
                    PhotoshopChannel(ID id, unsigned int size);
                    virtual ~PhotoshopChannel();

                    void ReadPixelData(int width, int height, int bitsPerPixel, PhotoshopDocumentReader& reader);

                    ID GetID() const;
                    unsigned int GetSize() const;
                    int GetWidth() const;
                    int GetHeight() const;
                    int GetBitsPerPixel() const;
                    const std::vector<byte>& GetBitmap() const;

                private:
                    ID id;
                    unsigned int size;
                    int width;
                    int height;
                    int bitsPerPixel;
                    std::vector<byte> bitmap;

                private:
                    PhotoshopChannel(const PhotoshopChannel&);
                    PhotoshopChannel& operator = (const PhotoshopChannel&);
            };

            class PhotoshopLayer : public Asset
            {
                public:
                    PhotoshopLayer(PhotoshopDocumentReader& reader);
                    virtual ~PhotoshopLayer();

                    void AddSubLayer(PhotoshopLayerPtr item);
                    bool RemoveSubLayer(PhotoshopLayerPtr item);
                    PhotoshopLayerPtr FindSubLayer(const String& name) const;

                    void ReadPixelData(int bitsPerPixel, PhotoshopDocumentReader& reader);

                    const String& GetName() const;
                    const Rectangle& GetRectangle() const;
                    const String& GetBlendMode() const;
                    byte GetOpacity() const;
                    bool GetClipping() const;
                    bool GetTransparencyProtected() const;
                    bool GetVisible() const;
                    bool IsGroup() const;
                    const std::vector<PhotoshopChannelPtr>& GetChannels() const;
                    PhotoshopChannelPtr GetChannel(const PhotoshopChannel::ID id) const;
                    PhotoshopMaskPtr GetMask() const;

                    Rectangle GetUnionRectangle() const;

                    PhotoshopLayerWeakPtr GetGroup() const;
                    const std::vector<PhotoshopLayerPtr>& GetSubLayers() const;

                    Texture2DPtr ToTexture(GraphicsDevice* graphicsDevice) const;

                private:
                    String name;
                    Rectangle rectangle;
                    String blendMode;
                    byte opacity;
                    bool clipping;
                    bool transparencyProtected;
                    bool visible;
                    bool isGroup;
                    std::vector<PhotoshopChannelPtr> channels;
                    PhotoshopMaskPtr mask;
                    PhotoshopLayerWeakPtr group;
                    std::vector<PhotoshopLayerPtr> subLayers;
            };

            class PhotoshopMask : public Asset
            {
                public:
                    PhotoshopMask(const Rectangle& rectangle, byte defaultColor, bool positionRelativeToLayer, bool disabled, bool invertWhenBlending);
                    virtual ~PhotoshopMask();

                    void ReadPixelData(PhotoshopChannelPtr channel, int bitsPerPixel, PhotoshopDocumentReader& reader);

                    const Rectangle& GetRectangle() const;
                    byte GetDefaultColor() const;
                    bool GetPositionRelativeToLayer() const;
                    bool GetDisabled() const;
                    bool GetInvertWhenBlending() const;
                    PhotoshopChannelPtr GetChannel() const;

                private:
                    Rectangle rectangle;
                    byte defaultColor;
                    bool positionRelativeToLayer;
                    bool disabled;
                    bool invertWhenBlending;
                    PhotoshopChannelPtr channel;
            };
        }
    }

#endif