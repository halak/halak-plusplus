#pragma once
#ifndef __HALAK_UIFUNCTIONEVENTHANDLER_H__
#define __HALAK_UIFUNCTIONEVENTHANDLER_H__

#   include <Halak/FWD.h>
#   include <Halak/UIEventHandler.h>
#   include <Halak/UIFunctionTable.h>
#   include <vector>

    namespace Halak
    {
        class UIFunctionEventHandler : public UIEventHandler
        {
            public:
                UIFunctionEventHandler();
                UIFunctionEventHandler(const UIFunctionTable* table, const String& functionName);
                virtual ~UIFunctionEventHandler();

                virtual bool Invoke(const UIEventArgs& args);

                inline const UIFunctionTable* GetTable() const;
                void SetTable(const UIFunctionTable* value);
 
                inline const String& GetFunctionName() const;
                void SetFunctionName(const String& value);

            private:
                const UIFunctionTable* table;
                String functionName;

                UIFunctionTable::FunctionType callable;
                bool callableChanged;
        };
    }

#   include <Halak/UIFunctionEventHandler.inl>

#endif