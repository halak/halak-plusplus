#pragma once
#ifndef __HALAK_SPRITE_H__
#define __HALAK_SPRITE_H__

#   include <Halak/FWD.h>
#   include <Halak/Rectangle.h>
#   include <Halak/Vector2.h>

    namespace Halak
    {
        class Sprite
        {
            public:
                Sprite();
                Sprite(Texture2DPtr texture);
                Sprite(Texture2DPtr texture, const Rectangle& clippingRectangle);
                Sprite(Texture2DPtr texture, const Rectangle& clippingRectangle, Vector2 origin);
                Sprite(Texture2DPtr texture, Vector2 origin);
                Sprite(const Sprite& original);

                inline Texture2DPtr GetTexture() const;
                inline const Rectangle& GetClippingRectangle() const;
                inline Vector2 GetOrigin() const;

                Sprite& operator = (const Sprite& original);
                
                bool operator == (const Sprite& right) const;
                bool operator != (const Sprite& right) const;

            private:
                Texture2DPtr texture;
                Rectangle clippingRectangle;
                Vector2 origin;
        };
    }

#   include <Halak/Sprite.inl>

#endif