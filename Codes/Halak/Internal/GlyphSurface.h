#pragma once
#ifndef __HALAK_GLYPHSURFACE_H__
#define __HALAK_GLYPHSURFACE_H__

#   include <Halak/FWD.h>
#   include <Halak/Rectangle.h>

    namespace Halak
    {
        class GlyphSurface
        {
            public:
                Rectangle Allocate(const void* buffer, int width, int height, int pitch);
                void Deallocate(const Rectangle& rectangle);

                const RectangleStorage& GetStorage() const;
                Texture2D* GetTexture() const;

            private:
                GlyphSurface(GraphicsDevice* graphicsDevice, int width, int height);
                ~GlyphSurface();

            private:
                RectangleStorage* storage;
                DynamicTexture2DPtr texture;

                friend class GlyphTable;
        };
    }

#endif  