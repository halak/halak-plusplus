#pragma once
#ifndef __HALAK_COMMANDQUEUE_H__
#define __HALAK_COMMANDQUEUE_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class CommandQueue : public GameComponent
        {
            HKClassFOURCC('C', 'M', 'D', 'Q');
            public:
                CommandQueue();
                virtual ~CommandQueue();               

            private:
                friend void __Startup__();
                static void __Startup__();
        };
    }

#endif