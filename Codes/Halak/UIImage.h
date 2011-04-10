#pragma once
#ifndef __HALAK_UIIMAGE_H__
#define __HALAK_UIIMAGE_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>
#   include <Halak/Rectangle.h>
#   include <Halak/RectangleF.h>
#   include <Halak/String.h>

    namespace Halak
    {
        class UIImage : public SharedObject
        {
            public:
                UIImage(const String& textureURI, const Rectangle& clippingRectangle);
                virtual ~UIImage();

                void SetRealTextureData(const Texture2DPtr& texture, const Rectangle& clippingRectangle);

                inline const String& GetTextureURI() const;
                inline const Rectangle& GetClippingRectangle() const;

                inline const Texture2DPtr& GetRealTexture() const;
                inline const Rectangle& GetRealClippingRectangle() const;
                inline const RectangleF& GetNormalizedRealClippingRectangle() const;

                inline uint GetRevision() const;

            private:
                String textureURI;
                Rectangle clippingRectangle;
                Texture2DPtr realTexture;
                Rectangle realClippingRectangle;
                RectangleF normalizedRealClippingRectangle;
                uint revision;
        };
    }

#   include <Halak/UIImage.inl>

#endif