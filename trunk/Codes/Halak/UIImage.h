#pragma once
#ifndef __HALAK_UIIMAGE_H__
#define __HALAK_UIIMAGE_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>
#   include <Halak/Rectangle.h>
#   include <Halak/RectangleF.h>
#   include <Halak/URI.h>

    namespace Halak
    {
        class UIImage : public SharedObject
        {
            public:
                UIImage(const URI& textureURI, const Rectangle& clippingRectangle);
                virtual ~UIImage();

                void SetRealTextureData(Texture2D* texture);
                void SetRealTextureData(Texture2D* texture, const Rectangle& clippingRectangle);

                inline const URI& GetTextureURI() const;
                inline const Rectangle& GetClippingRectangle() const;

                inline Texture2D* GetRealTexture() const;
                inline const Rectangle& GetRealClippingRectangle() const;
                inline const RectangleF& GetNormalizedRealClippingRectangle() const;

                inline uint GetRevision() const;

            private:
                URI textureURI;
                Rectangle clippingRectangle;
                Texture2DPtr realTexture;
                Rectangle realClippingRectangle;
                RectangleF normalizedRealClippingRectangle;
                uint revision;
        };
    }

#   include <Halak/UIImage.inl>

#endif