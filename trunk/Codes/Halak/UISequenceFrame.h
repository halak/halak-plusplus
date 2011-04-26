#pragma once
#ifndef __HALAK_UISEQUENCEFRAME_H__
#define __HALAK_UISEQUENCEFRAME_H__

#   include <Halak/FWD.h>
#   include <Halak/UIFrame.h>

    namespace Halak
    {
        class UISequenceFrame : public UIFrame
        {
            public:
                UISequenceFrame();
                virtual ~UISequenceFrame();

                virtual RectangleF ComputeBounds(UIVisualVisitor& visitor);

            private:
        };
    }

#   include <Halak/UISequenceFrame.inl>

#endif