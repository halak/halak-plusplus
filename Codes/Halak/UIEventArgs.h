#pragma once
#ifndef __HALAK_UIEVENTARGS_H__
#define __HALAK_UIEVENTARGS_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>

    namespace Halak
    {
        class UIEventArgs : public SharedObject
        {
            public:
                UIEventArgs();
                UIEventArgs(UIWindow* target);
                UIEventArgs(const UIEventArgs& original);
                virtual ~UIEventArgs();

                inline UIWindow* GetTarget() const;

            private:
                UIWindowPtr target;
        };
    }

#   include <Halak/UIEventArgs.inl>

#endif