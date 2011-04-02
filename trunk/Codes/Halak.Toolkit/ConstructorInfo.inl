#include <Halak.Toolkit/TypeLibrary.h>

namespace Halak
{
    namespace Toolkit
    {
        template <typename C>
        C* ConstructorInfo::Construct()
        {
            return reinterpret_cast<C*>(constructor->Call(Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing));
        }

        template <typename C, typename T1>
        C* ConstructorInfo::Construct(T1 arg1)
        {
            return reinterpret_cast<C*>(constructor->Call(Any(arg1), Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing));
        }

        template <typename C, typename T1, typename T2>
        C* ConstructorInfo::Construct(T1 arg1, T2 arg2)
        {
            return reinterpret_cast<C*>(constructor->Call(Any(arg1), Any(arg2), Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing));
        }

        template <typename C, typename T1, typename T2, typename T3>
        C* ConstructorInfo::Construct(T1 arg1, T2 arg2, T3 arg3)
        {
            return reinterpret_cast<C*>(constructor->Call(Any(arg1), Any(arg2), Any(arg3), Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing));
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4>
        C* ConstructorInfo::Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4)
        {
            return reinterpret_cast<C*>(constructor->Call(Any(arg1), Any(arg2), Any(arg3), Any(arg4), Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing));
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5>
        C* ConstructorInfo::Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5)
        {
            return reinterpret_cast<C*>(constructor->Call(Any(arg1), Any(arg2), Any(arg3), Any(arg4), Any(arg5), Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing));
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
        C* ConstructorInfo::Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6)
        {
            return reinterpret_cast<C*>(constructor->Call(Any(arg1), Any(arg2), Any(arg3), Any(arg4), Any(arg5), Any(arg6), Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing));
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
        C* ConstructorInfo::Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7)
        {
            return reinterpret_cast<C*>(constructor->Call(Any(arg1), Any(arg2), Any(arg3), Any(arg4), Any(arg5), Any(arg6), Any(arg7), Any::Missing, Any::Missing, Any::Missing, Any::Missing, Any::Missing));
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
        C* ConstructorInfo::Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8)
        {
            return reinterpret_cast<C*>(constructor->Call(Any(arg1), Any(arg2), Any(arg3), Any(arg4), Any(arg5), Any(arg6), Any(arg7), Any(arg8), Any::Missing, Any::Missing, Any::Missing, Any::Missing));
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
        C* ConstructorInfo::Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9)
        {
            return reinterpret_cast<C*>(constructor->Call(Any(arg1), Any(arg2), Any(arg3), Any(arg4), Any(arg5), Any(arg6), Any(arg7), Any(arg8), Any(arg9), Any::Missing, Any::Missing, Any::Missing));
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
        C* ConstructorInfo::Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10)
        {
            return reinterpret_cast<C*>(constructor->Call(Any(arg1), Any(arg2), Any(arg3), Any(arg4), Any(arg5), Any(arg6), Any(arg7), Any(arg8), Any(arg9), Any(arg10), Any::Missing, Any::Missing));
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
        C* ConstructorInfo::Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11)
        {
            return reinterpret_cast<C*>(constructor->Call(Any(arg1), Any(arg2), Any(arg3), Any(arg4), Any(arg5), Any(arg6), Any(arg7), Any(arg8), Any(arg9), Any(arg10), Any(arg11), Any::Missing));
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
        C* ConstructorInfo::Construct(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12)
        {
            return reinterpret_cast<C*>(constructor->Call(Any(arg1), Any(arg2), Any(arg3), Any(arg4), Any(arg5), Any(arg6), Any(arg7), Any(arg8), Any(arg9), Any(arg10), Any(arg11), Any(arg12)));
        }

        const ClassInfo* ConstructorInfo::GetClass() const
        {
            return class_;
        }

        const ConstructorInfo::InstanceCollection& ConstructorInfo::GetParameters() const
        {
            return parameters;
        }

        const ConstructorInfo::AttributeCollection& ConstructorInfo::GetAttributes() const
        {
            return attributes;
        }

        template <typename C>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate0<C>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            return f;
        }

        template <typename C, typename T1>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate1<C, T1>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            f.parameters.push_back(InstanceInfo::From<T1>());
            return f;
        }

        template <typename C, typename T1, typename T2>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate2<C, T1, T2>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            f.parameters.push_back(InstanceInfo::From<T1>());
            f.parameters.push_back(InstanceInfo::From<T2>());
            return f;
        }

        template <typename C, typename T1, typename T2, typename T3>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate3<C, T1, T2, T3>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            f.parameters.push_back(InstanceInfo::From<T1>());
            f.parameters.push_back(InstanceInfo::From<T2>());
            f.parameters.push_back(InstanceInfo::From<T3>());
            return f;
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate4<C, T1, T2, T3, T4>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            f.parameters.push_back(InstanceInfo::From<T1>());
            f.parameters.push_back(InstanceInfo::From<T2>());
            f.parameters.push_back(InstanceInfo::From<T3>());
            f.parameters.push_back(InstanceInfo::From<T4>());
            return f;
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate5<C, T1, T2, T3, T4, T5>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            f.parameters.push_back(InstanceInfo::From<T1>());
            f.parameters.push_back(InstanceInfo::From<T2>());
            f.parameters.push_back(InstanceInfo::From<T3>());
            f.parameters.push_back(InstanceInfo::From<T4>());
            f.parameters.push_back(InstanceInfo::From<T5>());
            return f;
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate6<C, T1, T2, T3, T4, T5, T6>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            f.parameters.push_back(InstanceInfo::From<T1>());
            f.parameters.push_back(InstanceInfo::From<T2>());
            f.parameters.push_back(InstanceInfo::From<T3>());
            f.parameters.push_back(InstanceInfo::From<T4>());
            f.parameters.push_back(InstanceInfo::From<T5>());
            f.parameters.push_back(InstanceInfo::From<T6>());
            return f;
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate7<C, T1, T2, T3, T4, T5, T6, T7>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            f.parameters.push_back(InstanceInfo::From<T1>());
            f.parameters.push_back(InstanceInfo::From<T2>());
            f.parameters.push_back(InstanceInfo::From<T3>());
            f.parameters.push_back(InstanceInfo::From<T4>());
            f.parameters.push_back(InstanceInfo::From<T5>());
            f.parameters.push_back(InstanceInfo::From<T6>());
            f.parameters.push_back(InstanceInfo::From<T7>());
            return f;
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate8<C, T1, T2, T3, T4, T5, T6, T7, T8>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            f.parameters.push_back(InstanceInfo::From<T1>());
            f.parameters.push_back(InstanceInfo::From<T2>());
            f.parameters.push_back(InstanceInfo::From<T3>());
            f.parameters.push_back(InstanceInfo::From<T4>());
            f.parameters.push_back(InstanceInfo::From<T5>());
            f.parameters.push_back(InstanceInfo::From<T6>());
            f.parameters.push_back(InstanceInfo::From<T7>());
            f.parameters.push_back(InstanceInfo::From<T8>());
            return f;
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate9<C, T1, T2, T3, T4, T5, T6, T7, T8, T9>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            f.parameters.push_back(InstanceInfo::From<T1>());
            f.parameters.push_back(InstanceInfo::From<T2>());
            f.parameters.push_back(InstanceInfo::From<T3>());
            f.parameters.push_back(InstanceInfo::From<T4>());
            f.parameters.push_back(InstanceInfo::From<T5>());
            f.parameters.push_back(InstanceInfo::From<T6>());
            f.parameters.push_back(InstanceInfo::From<T7>());
            f.parameters.push_back(InstanceInfo::From<T8>());
            f.parameters.push_back(InstanceInfo::From<T9>());
            return f;
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate10<C, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            f.parameters.push_back(InstanceInfo::From<T1>());
            f.parameters.push_back(InstanceInfo::From<T2>());
            f.parameters.push_back(InstanceInfo::From<T3>());
            f.parameters.push_back(InstanceInfo::From<T4>());
            f.parameters.push_back(InstanceInfo::From<T5>());
            f.parameters.push_back(InstanceInfo::From<T6>());
            f.parameters.push_back(InstanceInfo::From<T7>());
            f.parameters.push_back(InstanceInfo::From<T8>());
            f.parameters.push_back(InstanceInfo::From<T9>());
            f.parameters.push_back(InstanceInfo::From<T10>());
            return f;
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate11<C, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            f.parameters.push_back(InstanceInfo::From<T1>());
            f.parameters.push_back(InstanceInfo::From<T2>());
            f.parameters.push_back(InstanceInfo::From<T3>());
            f.parameters.push_back(InstanceInfo::From<T4>());
            f.parameters.push_back(InstanceInfo::From<T5>());
            f.parameters.push_back(InstanceInfo::From<T6>());
            f.parameters.push_back(InstanceInfo::From<T7>());
            f.parameters.push_back(InstanceInfo::From<T8>());
            f.parameters.push_back(InstanceInfo::From<T9>());
            f.parameters.push_back(InstanceInfo::From<T10>());
            f.parameters.push_back(InstanceInfo::From<T11>());
            return f;
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
        ConstructorInfo::Fields ConstructorInfo::Make()
        {
            Fields f;
            f.constructor = new ConstructorTemplate12<C, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>();
            f.class_ = static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetTypeInfo<C>());
            f.parameters.push_back(InstanceInfo::From<T1>());
            f.parameters.push_back(InstanceInfo::From<T2>());
            f.parameters.push_back(InstanceInfo::From<T3>());
            f.parameters.push_back(InstanceInfo::From<T4>());
            f.parameters.push_back(InstanceInfo::From<T5>());
            f.parameters.push_back(InstanceInfo::From<T6>());
            f.parameters.push_back(InstanceInfo::From<T7>());
            f.parameters.push_back(InstanceInfo::From<T8>());
            f.parameters.push_back(InstanceInfo::From<T9>());
            f.parameters.push_back(InstanceInfo::From<T10>());
            f.parameters.push_back(InstanceInfo::From<T12>());
            return f;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        template <typename C>
        void* ConstructorInfo::ConstructorTemplate0<C>::Call(const Any& /*arg1*/, const Any& /*arg2*/, const Any& /*arg3*/, const Any& /*arg4*/, const Any& /*arg5*/, const Any& /*arg6*/, const Any& /*arg7*/, const Any& /*arg8*/, const Any& /*arg9*/, const Any& /*arg10*/, const Any& /*arg11*/, const Any& /*arg12*/)
        {
            return new C();
        }

        template <typename C, typename T1>
        void* ConstructorInfo::ConstructorTemplate1<C, T1>::Call(const Any& arg1, const Any& /*arg2*/, const Any& /*arg3*/, const Any& /*arg4*/, const Any& /*arg5*/, const Any& /*arg6*/, const Any& /*arg7*/, const Any& /*arg8*/, const Any& /*arg9*/, const Any& /*arg10*/, const Any& /*arg11*/, const Any& /*arg12*/)
        {
            return new C(arg1.CastTo<T1>());
        }

        template <typename C, typename T1, typename T2>
        void* ConstructorInfo::ConstructorTemplate2<C, T1, T2>::Call(const Any& arg1, const Any& arg2, const Any& /*arg3*/, const Any& /*arg4*/, const Any& /*arg5*/, const Any& /*arg6*/, const Any& /*arg7*/, const Any& /*arg8*/, const Any& /*arg9*/, const Any& /*arg10*/, const Any& /*arg11*/, const Any& /*arg12*/)
        {
            return new C(arg1.CastTo<T1>(), arg2.CastTo<T2>());
        }

        template <typename C, typename T1, typename T2, typename T3>
        void* ConstructorInfo::ConstructorTemplate3<C, T1, T2, T3>::Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& /*arg4*/, const Any& /*arg5*/, const Any& /*arg6*/, const Any& /*arg7*/, const Any& /*arg8*/, const Any& /*arg9*/, const Any& /*arg10*/, const Any& /*arg11*/, const Any& /*arg12*/)
        {
            return new C(arg1.CastTo<T1>(), arg2.CastTo<T2>(), arg3.CastTo<T3>());
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4>
        void* ConstructorInfo::ConstructorTemplate4<C, T1, T2, T3, T4>::Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& /*arg5*/, const Any& /*arg6*/, const Any& /*arg7*/, const Any& /*arg8*/, const Any& /*arg9*/, const Any& /*arg10*/, const Any& /*arg11*/, const Any& /*arg12*/)
        {
            return new C(arg1.CastTo<T1>(), arg2.CastTo<T2>(), arg3.CastTo<T3>(), arg4.CastTo<T4>());
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5>
        void* ConstructorInfo::ConstructorTemplate5<C, T1, T2, T3, T4, T5>::Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& /*arg6*/, const Any& /*arg7*/, const Any& /*arg8*/, const Any& /*arg9*/, const Any& /*arg10*/, const Any& /*arg11*/, const Any& /*arg12*/)
        {
            return new C(arg1.CastTo<T1>(), arg2.CastTo<T2>(), arg3.CastTo<T3>(), arg4.CastTo<T4>(), arg5.CastTo<T5>());
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
        void* ConstructorInfo::ConstructorTemplate6<C, T1, T2, T3, T4, T5, T6>::Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& /*arg7*/, const Any& /*arg8*/, const Any& /*arg9*/, const Any& /*arg10*/, const Any& /*arg11*/, const Any& /*arg12*/)
        {
            return new C(arg1.CastTo<T1>(), arg2.CastTo<T2>(), arg3.CastTo<T3>(), arg4.CastTo<T4>(), arg5.CastTo<T5>(), arg6.CastTo<T6>());
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
        void* ConstructorInfo::ConstructorTemplate7<C, T1, T2, T3, T4, T5, T6, T7>::Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& /*arg8*/, const Any& /*arg9*/, const Any& /*arg10*/, const Any& /*arg11*/, const Any& /*arg12*/)
        {
            return new C(arg1.CastTo<T1>(), arg2.CastTo<T2>(), arg3.CastTo<T3>(), arg4.CastTo<T4>(), arg5.CastTo<T5>(), arg6.CastTo<T6>(), arg7.CastTo<T7>());
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
        void* ConstructorInfo::ConstructorTemplate8<C, T1, T2, T3, T4, T5, T6, T7, T8>::Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& /*arg9*/, const Any& /*arg10*/, const Any& /*arg11*/, const Any& /*arg12*/)
        {
            return new C(arg1.CastTo<T1>(), arg2.CastTo<T2>(), arg3.CastTo<T3>(), arg4.CastTo<T4>(), arg5.CastTo<T5>(), arg6.CastTo<T6>(), arg7.CastTo<T7>(), arg8.CastTo<T8>());
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
        void* ConstructorInfo::ConstructorTemplate9<C, T1, T2, T3, T4, T5, T6, T7, T8, T9>::Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& /*arg10*/, const Any& /*arg11*/, const Any& /*arg12*/)
        {
            return new C(arg1.CastTo<T1>(), arg2.CastTo<T2>(), arg3.CastTo<T3>(), arg4.CastTo<T4>(), arg5.CastTo<T5>(), arg6.CastTo<T6>(), arg7.CastTo<T7>(), arg8.CastTo<T8>(), arg9.CastTo<T9>());
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
        void* ConstructorInfo::ConstructorTemplate10<C, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>::Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& /*arg11*/, const Any& /*arg12*/)
        {
            return new C(arg1.CastTo<T1>(), arg2.CastTo<T2>(), arg3.CastTo<T3>(), arg4.CastTo<T4>(), arg5.CastTo<T5>(), arg6.CastTo<T6>(), arg7.CastTo<T7>(), arg8.CastTo<T8>(), arg9.CastTo<T9>(), arg10.CastTo<T10>());
        }
        
        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
        void* ConstructorInfo::ConstructorTemplate11<C, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>::Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& /*arg12*/)
        {
            return new C(arg1.CastTo<T1>(), arg2.CastTo<T2>(), arg3.CastTo<T3>(), arg4.CastTo<T4>(), arg5.CastTo<T5>(), arg6.CastTo<T6>(), arg7.CastTo<T7>(), arg8.CastTo<T8>(), arg9.CastTo<T9>(), arg10.CastTo<T10>(), arg11.CastTo<T11>());
        }

        template <typename C, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
        void* ConstructorInfo::ConstructorTemplate12<C, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>::Call(const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4, const Any& arg5, const Any& arg6, const Any& arg7, const Any& arg8, const Any& arg9, const Any& arg10, const Any& arg11, const Any& arg12)
        {
            return new C(arg1.CastTo<T1>(), arg2.CastTo<T2>(), arg3.CastTo<T3>(), arg4.CastTo<T4>(), arg5.CastTo<T5>(), arg6.CastTo<T6>(), arg7.CastTo<T7>(), arg8.CastTo<T8>(), arg9.CastTo<T9>(), arg10.CastTo<T10>(), arg11.CastTo<T11>(), arg12.CastTo<T12>());
        }
    }
}