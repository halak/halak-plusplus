#pragma once
#ifndef __HALAK_GLYPHSURFACE_H__
#define __HALAK_GLYPHSURFACE_H__

#   include <Halak/FWD.h>
#   include <Halak/Rectangle.h>

    namespace Halak
    {
        class GlyphSurface
        {
            friend class GlyphTable;
            public:
                Rectangle Allocate(const void* buffer, int width, int height, int pitch);
                void Deallocate(const Rectangle& rectangle);

                const Halak::RectangleStorage& GetStorage() const;
                DynamicTexture2DPtr GetTexture() const;

            private:
                GlyphSurface(GraphicsDevice* graphicsDevice, int width, int height);
                ~GlyphSurface();

            private:
                Halak::RectangleStorage* storage;
                DynamicTexture2DPtr texture;
        };
    }

#endif  