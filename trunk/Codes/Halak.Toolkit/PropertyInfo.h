#pragma once
#ifndef __HALAK_PROPERTYINFO_H__
#define __HALAK_PROPERTYINFO_H__

#   include <Halak/FWD.h>
#   include <Halak/Any.h>
#   include <Halak/InstanceInfo.h>
#   include <Halak/MPL.h>
#   include <vector>

    namespace Halak
    {
        class PropertyInfo
        {
            HKDeclareClassFOURCC('P', 'R', 'O', 'P');
            HKThisIsNoncopyableClass(PropertyInfo);
            public:
                typedef std::vector<const Attribute*> AttributeCollection;

            public:
                template <typename C, typename G> PropertyInfo(uint id, const char* name, G (C::*getter)());
                template <typename C, typename G> PropertyInfo(uint id, const char* name, G (C::*getter)() const);
                template <typename C, typename G, typename S> PropertyInfo(uint id, const char* name, G (C::*getter)(), void (C::*setter)(S));
                template <typename C, typename G, typename S> PropertyInfo(uint id, const char* name, G (C::*getter)() const, void (C::*setter)(S));
                ~PropertyInfo();

                void Add(const Attribute* item);
                bool Remove(const Attribute* item);

                inline uint GetID() const;
                inline const char* GetName() const;
                inline const ClassInfo* GetClass() const;
                inline const InstanceInfo& GetGetterInfo() const;
                inline const InstanceInfo& GetSetterInfo() const;
                inline const AttributeCollection& GetAttributes() const;
                template <typename T> const T* FindAttribute() const;

                Any GetValue(const AnyPtr& instance) const;
                template <typename V> V GetValue(const AnyPtr& instance) const;
                template <typename V> void SetValue(const AnyPtr& instance, V value) const;

                template <typename V, typename C> V GetValueFast(const C* instance) const;
                template <typename V, typename C> void SetValueFast(C* instance, V value) const;

            private:
                struct Getter
                {
                    InstanceInfo instanceInfo;

                    inline Getter(const InstanceInfo& instanceInfo);
                    virtual ~Getter();

                    virtual Any Call(const void* instance) const = 0;
                };

                template <typename C, typename V> struct GetterTemplate : Getter
                {
                    typedef V (C::*MethodType)() const;
                    typedef typename MPL::RemoveConst<V>::type ConstRemovedType;
                    typedef typename MPL::RemoveReference<ConstRemovedType>::type StorageType;
                    MethodType method;

                    GetterTemplate(V (C::*method)());
                    GetterTemplate(V (C::*method)() const);
                    virtual ~GetterTemplate();

                    virtual Any Call(const void* instance) const;
                };

                struct Setter
                {
                    InstanceInfo instanceInfo;

                    inline Setter(const InstanceInfo& instanceInfo);
                    virtual ~Setter();

                    virtual void Call(void* instance, const Any& value) const = 0;
                };

                template <typename C, typename V> struct SetterTemplate : Setter
                {
                    typedef void (C::*MethodType)(V);
                    typedef typename MPL::RemoveConst<V>::type ConstRemovedType;
                    typedef typename MPL::RemoveReference<ConstRemovedType>::type StorageType;
                    MethodType method;

                    SetterTemplate(void (C::*method)(V));
                    virtual ~SetterTemplate();

                    virtual void Call(void* instance, const Any& value) const;
                };

            private:
                uint id;
                const char* name;
                const ClassInfo* class_;
                Getter* getter;
                Setter* setter;
                AttributeCollection attributes;

                friend class PropertyRegistrationContext;
        };
    }

#   include <Halak/PropertyInfo.inl>

#endif