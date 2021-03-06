#pragma once
#ifndef __HALAK_LOGGER_H__
#define __HALAK_LOGGER_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class Logger : public GameComponent
        {
            HKClassFOURCC('L', 'G', 'E', 'R');
            public:
                Logger();
                explicit Logger(uint32 id);
                virtual ~Logger();
        };
    }

#   include <Halak/Logger.inl>

#endif