#pragma once
#ifndef __HALAK_TOOLKIT_SIMPLEPARTICLEEMITTERTOOL_H__
#define __HALAK_TOOLKIT_SIMPLEPARTICLEEMITTERTOOL_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/ParticleEmitterTool.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class SimpleParticleEmitterTool : public ParticleEmitterTool
            {
                public:
                    SimpleParticleEmitterTool(GameStructure* structure);
                    virtual ~SimpleParticleEmitterTool();

                    virtual void Draw(DrawingContext& context);

                    SimpleParticleEmitterWeakPtr GetTargetPointee() const;
                    void SetTarget(SimpleParticleEmitterWeakPtr value);

                private:
                    SimpleParticleEmitterWeakPtr target;
            };
        }
    }

#endif