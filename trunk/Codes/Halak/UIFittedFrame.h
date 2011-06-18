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
                static UIFittedFramePtr Instance;

            public:
                UIFittedFrame();
                virtual ~UIFittedFrame();

                virtual RectangleF ComputeBounds(UIVisualVisitor& visitor, Vector2 desiredSize);
        };
    }

#   include <Halak/UIFittedFrame.inl>

#endif