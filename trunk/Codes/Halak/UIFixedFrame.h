#pragma once
#ifndef __HALAK_UIFIXEDFRAME_H__
#define __HALAK_UIFIXEDFRAME_H__

#   include <Halak/FWD.h>
#   include <Halak/UIFrame.h>

    namespace Halak
    {
        class UIFixedFrame : public UIFrame
        {
            public:
                UIFixedFrame();
                virtual ~UIFixedFrame();

                virtual RectangleF ComputeBounds(UIVisualVisitor& visitor);
        };
    }

#   include <Halak/UIFixedFrame.inl>

#endif