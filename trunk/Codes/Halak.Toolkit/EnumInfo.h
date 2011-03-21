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
            HKDeclareClassFOURCC('E', 'N', 'U', 'M');
            public:
                class Value
                {
                    HKDeclareClassFOURCC('E', 'N', 'V', 'L');
                    HKThisIsNoncopyableClass(Value);
                    public:
                        ~Value();

                        void Add(const Attribute* item);
                        bool Remove(const Attribute* item);

                        inline const char* GetName() const;
                        inline int         GetValue() const;
                        inline const AttributeCollection& GetAttributes() const;

                    private:
                        Value(const char* name, int value);

                    private:
                        const char* name;
                        int value;
                        AttributeCollection attributes;

                    private:
                        friend class EnumInfo;
                };

            public:
                typedef std::vector<const Value*> ValueCollection;

            public:
                void Add(const char* name, int value);

                inline const ValueCollection& GetValues() const;

            private:
                EnumInfo(int allocationSize);
                virtual ~EnumInfo();

            private:
                ValueCollection values;

            private:
                friend class TypeLibrary;
        };
    }

#endif