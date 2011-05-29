#pragma once
#ifndef __HALAK_ENTITYCOMPONENT_H__
#define __HALAK_ENTITYCOMPONENT_H__

#   include <Halak/FWD.h>
#   include <Halak/String.h>

    namespace Halak
    {
        class EntityComponent
        {
            private:
                String name;
                String tag;
                void* object;
                SharedObjectPtr objectLifetime;
                ObjectOperator* operator_;

            public:
                static const EntityComponent Empty;

            public:
                EntityComponent();
                EntityComponent(const String& name, const String& tag, void* object, ObjectOperator* operator_);
                EntityComponent(const String& name, const String& tag, SharedObject* object, ObjectOperator* operator_);
                EntityComponent(const EntityComponent& original);
                ~EntityComponent();

                inline const String& GetName() const;
                inline const String& GetTag() const;
                inline void* GetObject() const;
                inline ObjectOperator* GetOperator() const;

                EntityComponent& operator = (const EntityComponent& right);
                bool operator == (const EntityComponent& right) const;
                inline bool operator != (const EntityComponent& right) const;
        };
    }

#   include <Halak/EntityComponent.inl>

#endif