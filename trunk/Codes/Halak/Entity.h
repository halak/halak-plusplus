#pragma once
#ifndef __HALAK_ENTITY_H__
#define __HALAK_ENTITY_H__

#   include <Halak/FWD.h>
#   include <Halak/EntityComponent.h>
#   include <Halak/String.h>
#   include <vector>

    namespace Halak
    {
        /// Entity�� �����ϰ� ǥ���ϸ� Runtime�� ������ ������ Class�Դϴ�.
        /// �ǻ�Ȱ���� ���� �츮�� ���� �� �ִ� ���� ���ϸ� '�ٶ�', '����', '�Ҹ�' ���� �͵��� ���Ե˴ϴ�.
        /// ������ Entity ��ü�� �׷� ����� ������ ���� ������,
        /// �����ϴ� ���� ���� Component�鿡 ���� �׷� ��ó�� ���̰� �Ǵ� ���Դϴ�.
        /// 
        /// * Component�鿡 �̸��� �ο��Ͽ�, �ܺο��� Component���� ���� ������ �� �ֵ��� �մϴ�.
        ///     - �̴� "�ŵ���"�̶� �̸��� ���� ����� ������ "������", ȸ�翡�� "�Ű���"���� �Ҹ��� �Ͱ� ���� ��ġ�Դϴ�.
        /// * SharedObject���� ��� Lifetime cycle�� �����Ѵ�.
        ///     - Component���� interface�� ������ ���� ��� interface�� ��ü�� �ܼ� ���� class���� SharedObject�� ��� ����
        ///       ���� ������ class���� �� ��찡 �����ϴ�.
        ///       �׷��� ������ Entity���� å������ SharedObject�� Lifetime cycle�� �����ϰ� �Ǿ����ϴ�.
        ///
        /// ����:
        ///     ���� Component���� void*�� �����Ǵµ� �̴� ���� ������ ���ؼ��̸�,
        ///     ���� Component���� ��¥ ������ �˰� ������ ��ӵ� ������ Tag�� ��ȸ�ϸ� �˴ϴ�.
        ///     �׿ܿ��� void* ������ ���� Component���� �⺻���� ����� �����ϴ� IComponentOperator�� �����մϴ�.
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