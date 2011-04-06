#pragma once
#ifndef __HALAK_UIALIGNEDFRAME_H__
#define __HALAK_UIALIGNEDFRAME_H__

#   include <Halak/FWD.h>
#   include <Halak/UIFrame.h>

    namespace Halak
    {
        class UIAlignedFrame : public UIFrame
        {
            public:
                UIAlignedFrame();
                virtual ~UIAlignedFrame();

                virtual RectangleF ComputeBounds(UIVisualVisitor& visitor);
        };
    }

#   include <Halak/UIAlignedFrame.inl>

#endif