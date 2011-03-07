#pragma once
#ifndef __HALAK_RESTORABLECOMMAND_H__
#define __HALAK_RESTORABLECOMMAND_H__

#   include <Halak/FWD.h>
#   include <Halak/Command.h>

    namespace Halak
    {
        class RestorableCommand : public Command
        {
            public:
                virtual ~RestorableCommand();

                virtual void Undo() = 0;
                virtual void Redo();

                virtual bool CanUndo() const;
                virtual bool CanRedo() const;

            protected:
                RestorableCommand();

            private:
                friend void __Startup__();
                static void __Startup__();
        };
    }

#endif