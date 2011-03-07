#pragma once
#ifndef __HALAK_COMMANDQUEUE_H__
#define __HALAK_COMMANDQUEUE_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class CommandQueue : public GameComponent
        {
            public:
                CommandQueue();

            private:
                virtual ~CommandQueue();

            private:
                friend void __Startup__();
                static void __Startup__();
        };
    }

#endif