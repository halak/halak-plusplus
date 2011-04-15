#pragma once
#ifndef __HALAK_COMMAND_H__
#define __HALAK_COMMAND_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class Command
        {
            public:
                virtual ~Command();

                virtual void Execute() = 0;

                virtual bool IsRestorable() const;

            protected:
                Command();

            private:
                friend void __Startup__();
                static void __Startup__();
        };
    }

#endif