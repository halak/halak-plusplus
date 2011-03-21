#pragma once
#ifndef __HALAK_PROPERTYINFO_INL__
#define __HALAK_PROPERTYINFO_INL__

#   include <Halak/AnyPtr.h>
#   include <Halak/DynamicCast.h>
#   include <Halak/TypeLibrary.h>

    namespace Halak
    {
        PropertyInfo::Getter::Getter(const InstanceInfo& instanceInfo)
            : instanceInfo(instanceInfo)
        {
        }

        template <typename C, typename V> PropertyInfo::GetterTemplate<C, V>::GetterTemplate(V (C::*method)())
            : Getter(InstanceInfo::From<V>()),
              method(reinterpret_cast<MethodType>(method))
        {
        }

        template <typename C, typename V> PropertyInfo::GetterTemplate<C, V>::GetterTemplate(V (C::*method)() const)
            : Getter(InstanceInfo::From<V>()),
              method(reinterpret_cast<MethodType>(method))
        {
        }

        template <typename C, typename V> PropertyInfo::GetterTemplate<C, V>::~GetterTemplate()
        {
        }

        template <typename C, typename V> Any PropertyInfo::GetterTemplate<C, V>::Call(const void* instance) const
        {
            return Any((reinterpret_cast<const C*>(instance)->*method)());
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        PropertyInfo::Setter::Setter(const InstanceInfo& instanceInfo)
            : instanceInfo(instanceInfo)
        {
        }

        template <typename C, typename V> PropertyInfo::SetterTemplate<C, V>::SetterTemplate(void (C::*method)(V))
            : Setter(InstanceInfo::From<V>()),
              method(reinterpret_cast<MethodType>(method))
        {
        }

        template <typename C, typename V> PropertyInfo::SetterTemplate<C, V>::~SetterTemplate()
        {
        }

        template <typename C, typename V> void PropertyInfo::SetterTemplate<C, V>::Call(void* instance, const Any& value) const
        {
            return (reinterpret_cast<C*>(instance)->*method)(value.CastTo<StorageType>());
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        template <typename C, typename G> PropertyInfo::PropertyInfo(uint id, const char* name, G (C::*getter)())
            : id(id),
              name(name),
              class_(static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetType<C>())),
              getter(new GetterTemplate<C, G>(getter)),
              setter(nullptr)
        {
        }

        template <typename C, typename G> PropertyInfo::PropertyInfo(uint id, const char* name, G (C::*getter)() const)
            : id(id),
              name(name),
              class_(static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetType<C>())),
              getter(new GetterTemplate<C, G>(getter)),
              setter(nullptr)
        {
        }

        template <typename C, typename G, typename S> PropertyInfo::PropertyInfo(uint id, const char* name, G (C::*getter)(), void (C::*setter)(S))
            : id(id),
              name(name),
              class_(static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetType<C>())),
              getter(new GetterTemplate<C, G>(getter)),
              setter(new SetterTemplate<C, S>(setter))
        {
        }

        template <typename C, typename G, typename S> PropertyInfo::PropertyInfo(uint id, const char* name, G (C::*getter)() const, void (C::*setter)(S))
            : id(id),
              name(name),
              class_(static_cast<const ClassInfo*>(TypeLibrary::GetInstance().GetType<C>())),
              getter(new GetterTemplate<C, G>(getter)),
              setter(new SetterTemplate<C, S>(setter))
        {
        }

        uint PropertyInfo::GetID() const
        {
            return id;
        }

        const char* PropertyInfo::GetName() const
        {
            return name;
        }

        const ClassInfo* PropertyInfo::GetClass() const
        {
            return class_;
        }

        const InstanceInfo& PropertyInfo::GetGetterInfo() const
        {
            if (getter)
                return getter->instanceInfo;
            else
                return InstanceInfo::Empty;
        }

        const InstanceInfo& PropertyInfo::GetSetterInfo() const
        {
            if (setter)
                return setter->instanceInfo;
            else
                return InstanceInfo::Empty;
        }

        const PropertyInfo::AttributeCollection& PropertyInfo::GetAttributes() const
        {
            return attributes;
        }

        template <typename T> const T* PropertyInfo::FindAttribute() const
        {
            for (AttributeCollection::const_iterator it = attributes.begin(); it != attributes.end(); it++)
            {
                if (const T* result = dynamic_cast<const T*>(*it))
                    return result;
            }

            return nullptr;
        }

        template <typename V> V PropertyInfo::GetValue(const AnyPtr& instance) const
        {
            if (const void* castedInstance = instance.DynamicCastTo(class_))
                return getter->Call(castedInstance).CastTo<V>();
            else
                return V();
        }

        template <typename V> void PropertyInfo::SetValue(const AnyPtr& instance, V value) const
        {
            if (void* castedInstance = instance.DynamicCastTo(class_))
                setter->Call(castedInstance, Any(value));
        }

        template <typename V, typename C> V PropertyInfo::GetValueFast(const C* instance) const
        {
            GetterTemplate<C, V>::MethodType m = static_cast<GetterTemplate<C, V>*>(getter)->method;
            return (instance->*m)();
        }

        template <typename V, typename C> void PropertyInfo::SetValueFast(C* instance, V value) const
        {
            SetterTemplate<C, V>::MethodType m = static_cast<SetterTemplate<S, V>*>(setter)->method;
            (instance->*m)(value);
        }
    }

#endif