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
                UIEventArgs(UIVisual* target);
                UIEventArgs(const UIEventArgs& original);
                virtual ~UIEventArgs();

                inline UIVisual* GetTarget() const;

            private:
                UIVisualPtr target;
        };
    }

#   include <Halak/UIEventArgs.inl>

#endif