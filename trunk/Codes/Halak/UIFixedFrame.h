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
                explicit UIFixedFrame(const RectangleF& rectangle);
                virtual ~UIFixedFrame();

                virtual RectangleF ComputeBounds(UIVisualVisitor& visitor);

                inline const RectangleF& GetRectangle() const;
                inline void SetRectangle(const RectangleF& value);                

            private:
                RectangleF rectangle;
        };
    }

#   include <Halak/UIFixedFrame.inl>

#endif