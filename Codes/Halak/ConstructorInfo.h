#pragma once
#ifndef __HALAK_CONSTRUCTORINFO_H__
#define __HALAK_CONSTRUCTORINFO_H__

#   include <Halak/FWD.h>
#   include <Halak/Any.h>
#   include <Halak/InstanceInfo.h>
#   include <vector>

    namespace Halak
    {
        class ConstructorInfo
        {
            public:
                typedef std::vector<InstanceInfo> InstanceCollection;
                typedef std::vector<const Attribute*> AttributeCollection;
                
                class Constructor;
                class Fields
                {
                    friend class ConstructorInfo;
                    Constructor* constructor;
                    const ClassInfo* class_;
                    InstanceCollection parameters;
                };

            public:
                explicit ConstructorInfo(const Fields& fields);
                ~ConstructorInfo();

                template <typename C>
                C* Construct();
                template <typename C, typename T1>
                C* Construct(T1 arg1);
                template <typename C, typename T1, typename T2>
                C* Construct(T1 arg1, T2 arg2);
                template <typename C, typename T1, typename T2, typename T3>
                C* Construct(T1 arg1, T2 arg2, T3 arg3);
                template <typename C, typename T1, typename T2, typename T3, typename T4>
                C* Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4);
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5>
                C* Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5);
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
                C* Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6);
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
                C* Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7);
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
                C* Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8);
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
                C* Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9);
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
                C* Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10);
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
                C* Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11);
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
                C* Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12);

                void Add(const Attribute* item);
                bool Remove(const Attribute* item);

                inline const ClassInfo* GetClass() const;
                inline const InstanceCollection& GetParameters() const;
                inline const AttributeCollection& GetAttributes() const;

                template <typename C>
                static Fields Make();
                template <typename C, typename T1>
                static Fields Make();
                template <typename C, typename T1, typename T2>
                static Fields Make();
                template <typename C, typename T1, typename T2, typename T3>
                static Fields Make();
                template <typename C, typename T1, typename T2, typename T3, typename T4>
                static Fields Make();
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5>
                static Fields Make();
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
                static Fields Make();
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
                static Fields Make();
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
                static Fields Make();
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
                static Fields Make();
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
                static Fields Make();
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
                static Fields Make();
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
                static Fields Make();

            private:
                Constructor* constructor;
                const ClassInfo* class_;
                InstanceCollection parameters;
                AttributeCollection attributes;

            private:
                ConstructorInfo(const ConstructorInfo&);
                ConstructorInfo& operator = (const ConstructorInfo&);

            public:
                class Constructor
                {
                    friend class ConstructorInfo;
                    protected:
                        virtual ~Constructor();
                        virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4,  const Any& arg5,  const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12) = 0;
                };

                template <typename C>
                class ConstructorTemplate0 : public Constructor
                {
                    virtual ~ConstructorTemplate0() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
                template <typename C, typename T1>
                class ConstructorTemplate1 : public Constructor
                {
                    virtual ~ConstructorTemplate1() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
                template <typename C, typename T1, typename T2>
                class ConstructorTemplate2 : public Constructor
                {
                    virtual ~ConstructorTemplate2() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
                template <typename C, typename T1, typename T2, typename T3>
                class ConstructorTemplate3 : public Constructor
                {
                    virtual ~ConstructorTemplate3() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
                template <typename C, typename T1, typename T2, typename T3, typename T4>
                class ConstructorTemplate4 : public Constructor
                {
                    virtual ~ConstructorTemplate4() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5>
                class ConstructorTemplate5 : public Constructor
                {
                    virtual ~ConstructorTemplate5() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
                class ConstructorTemplate6 : public Constructor
                {
                    virtual ~ConstructorTemplate6() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
                class ConstructorTemplate7 : public Constructor
                {
                    virtual ~ConstructorTemplate7() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
                class ConstructorTemplate8 : public Constructor
                {
                    virtual ~ConstructorTemplate8() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
                class ConstructorTemplate9 : public Constructor
                {
                    virtual ~ConstructorTemplate9() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
                class ConstructorTemplate10 : public Constructor
                {
                    virtual ~ConstructorTemplate10() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
                class ConstructorTemplate11 : public Constructor
                {
                    virtual ~ConstructorTemplate11() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
                template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
                class ConstructorTemplate12 : public Constructor
                {
                    virtual ~ConstructorTemplate12() { }
                    virtual void* Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12);
                };
        };
    }

#   include <Halak/ConstructorInfo.inl>

#endif