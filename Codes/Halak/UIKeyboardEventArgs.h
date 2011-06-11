#pragma once
#ifndef __HALAK_UIKEYBOARDEVENTARGS_H__
#define __HALAK_UIKEYBOARDEVENTARGS_H__

#   include <Halak/FWD.h>
#   include <Halak/UIEventArgs.h>
#   include <Halak/Key.h>

    namespace Halak
    {
        class UIKeyboardEventArgs : public UIEventArgs
        {
            public:
                UIKeyboardEventArgs();
                UIKeyboardEventArgs(UIVisual* target, Key::Code keyCode);
                UIKeyboardEventArgs(UIVisual* target, Key::Code keyCode0, Key::Code keyCode1, Key::Code keyCode2, Key::Code keyCode3);
                UIKeyboardEventArgs(const UIKeyboardEventArgs& original);
                virtual ~UIKeyboardEventArgs();

                virtual UIKeyboardEventArgs* Clone() const;

                inline bool Contains(Key::Code keyCode) const;
                inline Key::Code GetKeyCode0() const;
                inline Key::Code GetKeyCode1() const;
                inline Key::Code GetKeyCode2() const;
                inline Key::Code GetKeyCode3() const;
                inline Key::Code GetKeyCodeAt(int index) const;

            private:
                Key::Code keyCode0;
                Key::Code keyCode1;
                Key::Code keyCode2;
                Key::Code keyCode3;
        };
    }

#   include <Halak/UIKeyboardEventArgs.inl>

#endif