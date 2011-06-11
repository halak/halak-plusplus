#pragma once
#ifndef __HALAK_UIMOUSEBUTTONEVENTARGS_H__
#define __HALAK_UIMOUSEBUTTONEVENTARGS_H__

#   include <Halak/FWD.h>
#   include <Halak/UIMouseEventArgs.h>
#   include <Halak/Key.h>

    namespace Halak
    {
        class UIMouseButtonEventArgs : public UIMouseEventArgs
        {
            public:
                UIMouseButtonEventArgs();
                UIMouseButtonEventArgs(UIVisual* target, Point position, Key::Code buttonCode);
                UIMouseButtonEventArgs(UIVisual* target, Point position, bool isLeftButtonPressed, bool isRightButtonPressed, bool isMiddleButtonPressed, Key::Code buttonCode);
                UIMouseButtonEventArgs(const UIMouseEventArgs& base, Key::Code buttonCode);
                UIMouseButtonEventArgs(const UIMouseButtonEventArgs& original);
                virtual ~UIMouseButtonEventArgs();

                virtual UIMouseButtonEventArgs* Clone() const;

                inline Key::Code GetButtonCode() const;

            private:
                Key::Code buttonCode;
        };
    }

#   include <Halak/UIMouseButtonEventArgs.inl>

#endif