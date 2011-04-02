#pragma once
#ifndef __HALAK_TOOLKIT_ENUMINFO_H__
#define __HALAK_TOOLKIT_ENUMINFO_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/TypeInfo.h>
#   include <Halak/String.h>
#   include <vector>

    namespace Halak
    {
        namespace Toolkit
        {
            class EnumInfo : public TypeInfo
            {
                public:
                    class Value
                    {
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

                    friend class TypeLibrary;
            };
        }
    }

#endif