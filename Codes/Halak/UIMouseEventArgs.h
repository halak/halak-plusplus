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
                UIMouseEventArgs(UIVisual* target, Point position);
                UIMouseEventArgs(UIVisual* target, Point position, bool isLeftButtonPressed, bool isRightButtonPressed, bool isMiddleButtonPressed);
                UIMouseEventArgs(const UIMouseEventArgs& original);
                virtual ~UIMouseEventArgs();

                virtual UIMouseEventArgs* Clone() const;

                inline Point GetPosition() const;
                inline bool IsLeftButtonPressed() const;
                inline bool IsRightButtonPressed() const;
                inline bool IsMiddleButtonPressed() const;

            private:
                Point position;
                bool isLeftButtonPressed;
                bool isRightButtonPressed;
                bool isMiddleButtonPressed;
        };
    }

#   include <Halak/UIMouseEventArgs.inl>

#endif