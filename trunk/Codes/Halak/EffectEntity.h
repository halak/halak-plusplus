#pragma once
#ifndef __HALAK_EFFECTENTITY_H__
#define __HALAK_EFFECTENTITY_H__

#   include <Halak/FWD.h>
#   include <Halak/Entity.h>
#   include <Halak/IPickable.h>
#   include <Halak/IUpdateable.h>

    namespace Halak
    {
        class EffectEntity : public Entity, public IPickable, public IUpdateable
        {
            public:
                EffectEntity();
                EffectEntity(const String& name);
                ///^EffectEntity(const EffectEntity& original, CloningContext& context);
                virtual ~EffectEntity();

                virtual void Dispose();

                ISpatialPtr GetOrigin() const;
                void SetOrigin(ISpatialPtr value);

            protected:
                virtual void OnOriginChanged(ISpatialPtr old);

            private:
                ISpatialPtr origin;

            private:
                friend void __Startup__();
                static void __Startup__();
        };
    }

#endif