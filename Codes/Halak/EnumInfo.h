#pragma once
#ifndef __HALAK_ENUMINFO_H__
#define __HALAK_ENUMINFO_H__

#   include <Halak/FWD.h>
#   include <Halak/TypeInfo.h>
#   include <Halak/String.h>
#   include <vector>

    namespace Halak
    {
        class EnumInfo : public TypeInfo
        {
            friend class TypeLibrary;
            public:
                class Value
                {
                    friend class EnumInfo;
                    public:
                        ~Value();

                        void Add(const Attribute* item);
                        bool Remove(const Attribute* item);

                        const AttributeCollection& GetAttributes() const;

                    private:
                        Value(const char* name, int value);

                    private:
                        String name;
                        int value;
                        AttributeCollection attributes;
                };

            public:
                typedef std::vector<const Value*> ValueCollection;

            public:
                void Add(const char* name, int value);

                const ValueCollection& GetValues() const;

            private:
                EnumInfo(int allocationSize);
                virtual ~EnumInfo();

            private:
                ValueCollection values;
        };
    }

#endif