#pragma once
#ifndef __HALAK_PARTICLEEFFECTENTITY_H__
#define __HALAK_PARTICLEEFFECTENTITY_H__

#   include <Halak/FWD.h>
#   include <Halak/EffectEntity.h>
#   include <Halak/IDrawable.h>

    namespace Halak
    {
        class ParticleEffectEntity : public EffectEntity, public IDrawable
        {
            public:
                ParticleEffectEntity();
                ParticleEffectEntity(const String& name);
                ParticleEffectEntity(const ParticleEffectEntity& original, CloningContext& context);
                virtual ~ParticleEffectEntity();

                virtual ParticleEffectEntity* Clone() const;
                virtual ParticleEffectEntity* CloneWith(CloningContext& context) const;
                virtual void Dispose();

                virtual bool Pick(PickingContext& context);

                virtual void Update(float dt, uint timestamp);
                virtual void Draw(DrawingContext& context);

                ParticleEmitterPtr GetEmitter() const;
                void SetEmitter(ParticleEmitterPtr value);

                ParticleRendererPtr GetRenderer() const;
                void SetRenderer(ParticleRendererPtr value);

            protected:
                virtual void OnOriginChanged(ISpatialPtr old);
                virtual void OnEmitterChanged(ParticleEmitterPtr old);
                virtual void OnRendererChanged(ParticleRendererPtr old);

            private:
                ParticleEmitterPtr emitter;
                ParticleRendererPtr renderer;

            private:
                friend void __Startup__();
                static void __Startup__();
        };
    }

#endif