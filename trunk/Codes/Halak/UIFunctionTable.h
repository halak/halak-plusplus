#pragma once
#ifndef __HALAK_UIFUNCTIONTABLE_H__
#define __HALAK_UIFUNCTIONTABLE_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/String.h>
#   include <map>

    namespace Halak
    {
        class UIFunctionTable : public GameComponent
        {
            public:
                typedef bool (*GlobalFunctionType)(const UIEventArgs&);
                typedef GlobalFunctionType FunctionType;
                typedef std::map<String, FunctionType> NamedFunctionMap;

            public:
                UIFunctionTable();
                virtual ~UIFunctionTable();

                void Add(const String& name, GlobalFunctionType function);
                bool Remove(const String& name);
                void Clear();

                FunctionType Find(const String& name) const;

            private:
                NamedFunctionMap items;
        };
    }

#   include <Halak/UIFunctionTable.inl>

#endif