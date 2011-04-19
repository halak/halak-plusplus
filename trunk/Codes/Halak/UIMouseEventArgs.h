#pragma once
#ifndef __HALAK_UIMOUSEEVENTARGS_H__
#define __HALAK_UIMOUSEEVENTARGS_H__

#   include <Halak/FWD.h>
#   include <Halak/UIEventArgs.h>
#   include <Halak/Point.h>

    namespace Halak
    {
        class UIMouseEventArgs : public UIEventArgs
        {
            public:
                UIMouseEventArgs();
                UIMouseEventArgs(UIVisual* target, Point position, int wheelDelta);
                UIMouseEventArgs(UIVisual* target, Point position, int wheelDelta, bool leftButton, bool rightButton, bool middleButton);
                UIMouseEventArgs(const UIMouseEventArgs& original);
                virtual ~UIMouseEventArgs();

                inline Point GetPosition() const;
                inline int GetWheelDelta() const;
                inline bool GetLeftButton() const;
                inline bool GetRightButton() const;
                inline bool GetMiddleButton() const;

            private:
                Point position;
                int wheelDelta;
                bool leftButton;
                bool rightButton;
                bool middleButton;
        };
    }

#   include <Halak/UIMouseEventArgs.inl>

#endif