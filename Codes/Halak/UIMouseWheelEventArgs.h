#pragma once
#ifndef __HALAK_UIMOUSEWHEELEVENTARGS_H__
#define __HALAK_UIMOUSEWHEELEVENTARGS_H__

#   include <Halak/FWD.h>
#   include <Halak/UIMouseEventArgs.h>

    namespace Halak
    {
        class UIMouseWheelEventArgs : public UIMouseEventArgs
        {
            public:
                UIMouseWheelEventArgs();
                UIMouseWheelEventArgs(UIVisual* target, Point position, int wheelDelta);
                UIMouseWheelEventArgs(UIVisual* target, Point position, bool isLeftButtonPressed, bool isRightButtonPressed, bool isMiddleButtonPressed, int wheelDelta);
                UIMouseWheelEventArgs(const UIMouseEventArgs& base, int wheelDelta);
                UIMouseWheelEventArgs(const UIMouseWheelEventArgs& original);
                virtual ~UIMouseWheelEventArgs();

                virtual UIMouseWheelEventArgs* Clone() const;

                inline int GetWheelDelta() const;

            private:
                int wheelDelta;
        };
    }

#   include <Halak/UIMouseWheelEventArgs.inl>

#endif