#pragma once
#ifndef __HALAK_ROOTENTITY_H__
#define __HALAK_ROOTENTITY_H__

#   include <Halak/FWD.h>
#   include <Halak/Entity.h>

    namespace Halak
    {
        class RootEntity : public Entity
        {
            public:
                RootEntity();
                RootEntity(const String& name);
                RootEntity(const RootEntity& original, CloningContext& context);
                virtual ~RootEntity();

                virtual RootEntity* Clone() const;
                virtual RootEntity* CloneWith(CloningContext& context) const;

                const String& GetAuthor() const;
                void SetAuthor(const String& value);

                const String& GetComment() const;
                void SetComment(const String& value);

            private:
                String author;
                String comment;

            private:
                friend void __Startup__();
                static void __Startup__();
        };
    }

#endif