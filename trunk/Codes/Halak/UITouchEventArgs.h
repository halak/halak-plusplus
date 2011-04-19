#pragma once
#ifndef __HALAK_UITOUCHEVENTARGS_H__
#define __HALAK_UITOUCHEVENTARGS_H__

#   include <Halak/FWD.h>
#   include <Halak/UIEventArgs.h>

    namespace Halak
    {
        class UITouchEventArgs : public UIEventArgs
        {
            public:
                UITouchEventArgs();
                virtual ~UITouchEventArgs();

            private:
        };
    }

#   include <Halak/UITouchEventArgs.inl>

#endif