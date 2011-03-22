#pragma once
#ifndef __HALAK_COMMANDHISTORY_H__
#define __HALAK_COMMANDHISTORY_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/Signal.h>
#   include <list>

    namespace Halak
    {
        class CommandHistory : public GameComponent
        {
            HKDeclareGameComponentClassFOURCC('C', 'M', 'D', 'H');
            public:
                typedef std::list<Command*> CommandCollection;

            public:
                CommandHistory();
                virtual ~CommandHistory();

                void Execute(Command* command);
                void Undo();
                void Undo(int level);
                void Redo();
                void Redo(int level);
                void ProgressTo(Command* command);

                bool CanUndo() const;
                bool CanUndo(int level) const;
                bool CanRedo() const;
                bool CanRedo(int level) const;

                bool Contains(Command* command) const;

                const CommandCollection& GetCommands() const;
                const CommandCollection& GetCancelledCommands() const;

                Signal<CommandHistory*, Command*, const CommandCollection&>& Executed();
                Signal<CommandHistory*, const CommandCollection&>& Undone();
                Signal<CommandHistory*, const CommandCollection&>& Redone();

            private:
                CommandCollection commands;
                CommandCollection cancelledCommands;

                Signal<CommandHistory*, Command*, const CommandCollection&> executed;
                Signal<CommandHistory*, const CommandCollection&> undone;
                Signal<CommandHistory*, const CommandCollection&> redone;

            private:
                friend void __Startup__();
                static void __Startup__();
        };
    }

#endif