#pragma once
#ifndef __HALAK_UIFITTEDFRAME_H__
#define __HALAK_UIFITTEDFRAME_H__

#   include <Halak/FWD.h>
#   include <Halak/UIFrame.h>

    namespace Halak
    {
        class UIFittedFrame : public UIFrame
        {
            public:
                UIFittedFrame();
                virtual ~UIFittedFrame();

                virtual RectangleF ComputeBounds(UIVisual* owner, UIVisualVisitor& visitor);
        };
    }

#   include <Halak/UIFittedFrame.inl>

#endif