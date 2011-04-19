#pragma once
#ifndef __HALAK_UIEVENTARGS_H__
#define __HALAK_UIEVENTARGS_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>

    namespace Halak
    {
        class UIEventArgs : public SharedObject
        {
            HKThisIsNoncopyableClass(UIEventArgs);
            public:
                UIEventArgs();
                UIEventArgs(UIVisual* target);
                virtual ~UIEventArgs();

                inline UIVisual* GetTarget() const;

            private:
                UIVisualPtr target;
        };
    }

#   include <Halak/UIEventArgs.inl>

#endif