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
                inline UIEventArgs();
                inline virtual ~UIEventArgs();

            private:
        };
    }

#   include <Halak/UIEventArgs.inl>

#endif