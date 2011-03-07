#pragma once
#ifndef __HALAK_SPRITE_INL__
#define __HALAK_SPRITE_INL__

    namespace Halak
    {
        Texture2DPtr Sprite::GetTexture() const
        {
            return texture;
        }

        const Rectangle& Sprite::GetClippingRectangle() const
        {
            return clippingRectangle;
        }

        Vector2 Sprite::GetOrigin() const
        {
            return origin;
        }
    }

#endif