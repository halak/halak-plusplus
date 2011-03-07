#pragma once
#ifndef __HALAK_BATCHCOMMAND_H__
#define __HALAK_BATCHCOMMAND_H__

#   include <Halak/FWD.h>
#   include <Halak/RestorableCommand.h>
#   include <Halak/ICloneable.h>
#   include <vector>

    namespace Halak
    {
        class BatchCommand : public RestorableCommand, public ICloneable
        {
            public:
                typedef std::vector<Command*> CommandCollection;
                typedef std::vector<RestorableCommand*> RestorableCommandCollection;

            public:
                BatchCommand(const CommandCollection commands);
                BatchCommand(const BatchCommand& original, CloningContext& context);
                virtual ~BatchCommand();

                virtual BatchCommand* CloneWith(CloningContext& context) const;

                virtual void Execute();
                virtual void Undo();
                virtual void Redo();

                virtual bool CanUndo() const;
                virtual bool CanRedo() const;

                const CommandCollection& GetCommands() const;
                void SetCommands(const CommandCollection& value);

            private:
                CommandCollection commands;
                RestorableCommandCollection restorableCommands;

            private:
                friend void __Startup__();
                static void __Startup__();
        };
    }

#endif