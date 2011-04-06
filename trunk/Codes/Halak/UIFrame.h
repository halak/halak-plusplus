#pragma once
#ifndef __HALAK_UIFRAME_H__
#define __HALAK_UIFRAME_H__

#   include <Halak/FWD.h>
#   include <Halak/UIElement.h>
#   include <Halak/RectangleF.h>

    namespace Halak
    {
        class UIFrame : public UIElement
        {
            public:
                UIFrame();
                virtual ~UIFrame();

                virtual RectangleF ComputeBounds(UIVisualVisitor& visitor) = 0;
        };
    }

#   include <Halak/UIFrame.inl>

#endif