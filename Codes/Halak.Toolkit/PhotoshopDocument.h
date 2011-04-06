#pragma once
#ifndef __HALAK_TOOLKIT_PHOTOSHOPDOCUMENT_H__
#define __HALAK_TOOLKIT_PHOTOSHOPDOCUMENT_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/Asset.h>
#   include <Halak/IReloadable.h>
#   include <Halak/String.h>
#   include <vector>

    namespace Halak
    {
        namespace Toolkit
        {
            class PhotoshopDocument : public Asset, public IReloadable
            {
                public:
                    enum CompressionMode
                    {
                        NoCompression = 0,
                        RLECompression = 1,
                        ZIPWithoutPredictionCompression = 2,
                        ZIPWithPredictionCompression = 3,
                    };

                    enum ColorMode
                    {
                        GrayscaleColor = 1,
                        IndexedColor = 2,
                        RGBColor = 3,
                        CMYKColor = 4,
                        DuetoneColor = 8,
                        LabColor = 9,
                    };

                    enum Elements
                    {
                        ColorModeDataElement = (0x01 << 0),
                        ImageResourceElement = (0x01 << 1),
                        LayerElement         = (0x01 << 2),
                        MergedImageElement   = (0x01 << 3),
                        AllElements          = (0xFF),
                    };

                public:
                    PhotoshopDocument(const String& filename);
                    PhotoshopDocument(const String& filename, Elements importingElements);
                    virtual ~PhotoshopDocument();

                    virtual void Reload();

                    virtual const String& GetFilename() const;

                    int GetNumberOfChannels() const;
                    int GetWidth() const;
                    int GetHeight() const;
                    int GetBitsPerPixel() const;
                    ColorMode GetColorMode() const;

                    const std::vector<PhotoshopImageResourcePtr> GetImageResources() const;
                    const std::vector<PhotoshopLayerPtr> GetLayers() const;

                    Elements GetImportingElements() const;
                    void SetImportingElements(Elements value);

                    Texture2DPtr ToTexture(GraphicsDevice* graphicsDevice) const;

                private:
                    typedef std::vector<byte> ByteVector;

                private:
                    String filename;
                    int channels;
                    int width;
                    int height;
                    int bitsPerPixel;
                    ColorMode colorMode;

                    std::vector<PhotoshopImageResourcePtr> imageResources;
                    std::vector<PhotoshopLayerPtr> layers;
                    std::vector<ByteVector> mergedImage;

                    Elements importingElements;
            };
        }
    }

#endif