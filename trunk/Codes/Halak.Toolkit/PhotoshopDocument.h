#pragma once
#ifndef __TH_DOCUMENTS_ADOBE_PHOTOSHOPDOCUMENT_H__
#define __TH_DOCUMENTS_ADOBE_PHOTOSHOPDOCUMENT_H__

#   include <TH/Documents/Adobe/FWD.h>
#   include <Halak/Asset.h>
#   include <Halak/IReloadable.h>
#   include <vector>

    namespace TH
    {
        namespace Documents
        {
            namespace Adobe
            {
                struct PhotoshopCompression
                {
                    enum E
                    {
                        RawData = 0,
                        RLECompression = 1,
                        ZIPWithoutPrediction = 2,
                        ZIPWithPrediction = 3,
                    };
                };

                struct PhotoshopColorMode
                {
                    enum E
                    {
                        Grayscale = 1,
                        Indexed = 2,
                        RGB = 3,
                        CMYK = 4,
                        Duetone = 8,
                        Lab = 9,
                    };
                };

                struct PhotoshopDocumentElements
                {
                    enum E
                    {
                        ColorModeData = (0x01 << 0),
                        ImageResource = (0x01 << 1),
                        Layer         = (0x01 << 2),
                        MergedImage   = (0x01 << 3),
                        All           = (0xFF),
                    };
                };

                class PhotoshopDocument : public Halak::Asset, public Halak::IReloadable
                {
                    public:
                        PhotoshopDocument(const Halak::String& filename);
                        PhotoshopDocument(const Halak::String& filename, PhotoshopDocumentElements::E importingElements);
                        virtual ~PhotoshopDocument();

                        virtual void Reload();

                        virtual const Halak::String& GetFilename() const;

                        int GetNumberOfChannels() const;
                        int GetWidth() const;
                        int GetHeight() const;
                        int GetBitsPerPixel() const;
                        PhotoshopColorMode::E GetColorMode() const;

                        const std::vector<PhotoshopImageResourcePtr> GetImageResources() const;
                        const std::vector<PhotoshopLayerPtr> GetLayers() const;

                        PhotoshopDocumentElements::E GetImportingElements() const;
                        void SetImportingElements(PhotoshopDocumentElements::E value);

                        Halak::Texture2DPtr ToTexture(Halak::GraphicsDevice* graphicsDevice) const;

                    private:
                        typedef std::vector<byte> ByteVector;

                    private:
                        Halak::String filename;
                        int channels;
                        int width;
                        int height;
                        int bitsPerPixel;
                        PhotoshopColorMode::E colorMode;

                        std::vector<PhotoshopImageResourcePtr> imageResources;
                        std::vector<PhotoshopLayerPtr> layers;
                        std::vector<ByteVector> mergedImage;

                        PhotoshopDocumentElements::E importingElements;
                };
            }
        }
    }

#endif