#pragma once
#ifndef __HALAK_DRAWABLE_INTERFACE__
#define __HALAK_DRAWABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class IDrawable
        {
            public:
                virtual ~IDrawable() { }

                virtual void Draw(DrawingContext& context) = 0;
                virtual void DrawDebugInformation(DrawingContext& /*context*/) { }
        };
    }

#endif