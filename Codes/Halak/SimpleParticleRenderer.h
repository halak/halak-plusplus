#pragma once
#ifndef __HALAK_SIMPLEPARTICLERENDERER_H__
#define __HALAK_SIMPLEPARTICLERENDERER_H__

#   include <Halak/FWD.h>
#   include <Halak/ParticleRenderer.h>

    namespace Halak
    {
        class SimpleParticleRenderer : public ParticleRenderer
        {
            public:
                SimpleParticleRenderer();
                virtual ~SimpleParticleRenderer();

                virtual void Draw(DrawingContext& context);
                virtual void DrawDebugInformation(DrawingContext& context);

            protected:
                virtual void OnTargetChanged(ParticleEmitterPtr old);                
        };
    }

#endif