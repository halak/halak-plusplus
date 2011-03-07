#pragma once
#ifndef __HALAK_WORKFLOW_VARIABLESTORAGE_H__
#define __HALAK_WORKFLOW_VARIABLESTORAGE_H__

#   include <Halak/FWD.h>
#   include <Halak/Any.h>
#   include <map>
#   include <vector>

    namespace Halak
    {
        class VariableStorage
        {
            typedef std::map<String, Any> AnyDictionary;
            typedef std::vector<Any> AnyCollection;

            public:
                VariableStorage();
                VariableStorage(VariableStoragePtr reference);
                virtual ~VariableStorage();

                bool Contains(const String& name) const;

                const Any& GetValue(const String& name) const;
                const Any& GetValue(int index) const;
                void SetValue(const String& name, const Any& value);
                void SetValue(int index, const Any& value);

                VariableStoragePtr GetReference() const;
                void SetReference(VariableStoragePtr value);

                const AnyDictionary& GetDictionary() const;

            private:
                VariableStoragePtr reference;
                AnyDictionary variables;

                AnyCollection arrangedVariables;
        };
    }

#endif