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
                virtual ~UIKeyboardEventArgs();

                inline Key::Code GetKeyCode() const;

            private:
                Key::Code keyCode;
        };
    }

#   include <Halak/UIKeyboardEventArgs.inl>

#endif