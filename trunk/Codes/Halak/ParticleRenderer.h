#pragma once
#ifndef __HALAK_PARTICLERENDERER_H__
#define __HALAK_PARTICLERENDERER_H__

#   include <Halak/FWD.h>
#   include <Halak/IDrawable.h>

    namespace Halak
    {
        class ParticleRenderer : public SharedObject, public IDrawable
        {
            public:
                ParticleRenderer();
                virtual ~ParticleRenderer();

                ParticleEmitterPtr GetTargetPointee() const;
                void SetTarget(ParticleEmitterPtr value);

            protected:
                virtual void OnTargetChanged(ParticleEmitterPtr old);

            private:
                ParticleEmitterPtr target;
        };
    }

#   include <Halak/ParticleRenderer.inl>

#endif