#pragma once
#ifndef __HALAK_UIANCHOREDFRAME_H__
#define __HALAK_UIANCHOREDFRAME_H__

#   include <Halak/FWD.h>
#   include <Halak/UIFrame.h>

    namespace Halak
    {
        class UIAnchoredFrame : public UIFrame
        {
            public:
                UIAnchoredFrame();
                virtual ~UIAnchoredFrame();

                virtual RectangleF ComputeBounds(UIVisual* owner, UIVisualVisitor& visitor);

            private:
        };
    }

#   include <Halak/UIAnchoredFrame.inl>

#endif