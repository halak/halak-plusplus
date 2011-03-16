#pragma once
#ifndef __HALAK_CLOCK_H__
#define __HALAK_CLOCK_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class Clock : public GameComponent
        {
            HKDeclareGameComponentClassFOURCC('C', 'L', 'C', 'K');
            public:
                Clock();
                explicit Clock(uint id);
                virtual ~Clock();
        };
    }

#endif