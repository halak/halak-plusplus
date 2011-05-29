#pragma once
#ifndef __HALAK_ENTITY_H__
#define __HALAK_ENTITY_H__

#   include <Halak/FWD.h>
#   include <Halak/EntityComponent.h>
#   include <Halak/String.h>
#   include <vector>

    namespace Halak
    {
        /// Entity를 간단하게 표현하면 Runtime에 수정이 가능한 Class입니다.
        /// 실생활에서 보면 우리가 느낄 수 있는 것을 말하며 '바람', '생각', '소리' 같은 것들이 포함됩니다.
        /// 하지만 Entity 자체가 그런 기능을 가지고 있진 않으며,
        /// 관리하는 여러 개의 Component들에 의해 그런 것처럼 보이게 되는 것입니다.
        /// 
        /// * Component들에 이름을 부여하여, 외부에서 Component들을 쉽게 접근할 수 있도록 합니다.
        ///     - 이는 "신동림"이란 이름을 가진 사람이 집에선 "동림이", 회사에선 "신과장"으로 불리는 것과 같은 이치입니다.
        /// * SharedObject들의 경우 Lifetime cycle을 관리한다.
        ///     - Component에서 interface를 가지고 있을 경우 interface의 실체가 단순 다형 class인지 SharedObject를 상속 받은
        ///       공유 가능한 class인지 모를 경우가 많습니다.
        ///       그렇기 때문에 Entity에서 책임지고 SharedObject의 Lifetime cycle를 관리하게 되었습니다.
        ///
        /// 주의:
        ///     실제 Component들은 void*로 관리되는데 이는 빠른 성능을 위해서이며,
        ///     실제 Component들의 진짜 형식을 알고 싶으면 약속된 형식의 Tag를 조회하면 됩니다.
        ///     그외에도 void* 형식의 실제 Component들의 기본적인 기능을 수행하는 IComponentOperator을 제공합니다.
        class Entity : public SharedObject
        {
            public:
                typedef std::vector<EntityComponent> ComponentCollection;

            public:
                Entity();
                explicit Entity(int numberOfIndexedComponents);
                explicit Entity(const String& type);
                Entity(const String& type, const String& name);
                Entity(const String& type, const String& name, int numberOfIndexedComponents);
                virtual ~Entity();

                void Insert(const EntityComponent& item);
                bool Remove(const String& name);
                void RemoveAll();

                const EntityComponent* Find(const String& name) const;

                inline const String& GetType() const;
                inline void SetType(const String& value);

                inline const String& GetName() const;
                inline void SetName(const String& value);

                inline const ComponentCollection& GetIndexedComponents() const;

                inline const ComponentCollection& GetComponents() const;
                void SetComponents(const ComponentCollection& value);

            protected:
                inline       EntityComponent& GetAt(int index);
                inline const EntityComponent& GetAt(int index) const;
                inline void SetAt(int index, const EntityComponent& value);

                ComponentCollection::iterator FindIterator(const String& name);
                ComponentCollection::const_iterator FindIterator(const String& name) const;

                virtual void OnNameChanged(const String& old);
                virtual void OnComponentChanged(const EntityComponent& item);
                virtual void OnComponentRemoved(const EntityComponent& item);
                virtual void OnComponentsRemoved(const ComponentCollection& items);

                static void DestructAll(ComponentCollection& components);

            private:
                String type;
                String name;
                ComponentCollection indexedComponents;
                ComponentCollection components;

            private:
                Entity(const Entity&);
                Entity& operator = (const Entity&);

            private:
                friend void __Startup__();
                static void __Startup__();
        };
    }

#   include <Halak/Entity.inl>

#endif