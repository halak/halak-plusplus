#pragma once
#ifndef __HALAK_WXTOOLKIT_SIMPLEPARTICLEEMITTERTOOL_H__
#define __HALAK_WXTOOLKIT_SIMPLEPARTICLEEMITTERTOOL_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <Halak.wxToolkit/ParticleEmitterTool.h>

    namespace Halak
    {
        namespace wxToolkit
        {
            class SimpleParticleEmitterTool : public ParticleEmitterTool
            {
                public:
                    SimpleParticleEmitterTool(ServiceTree* services);
                    virtual ~SimpleParticleEmitterTool();

                    virtual void Draw(DrawingContext& context);

                    SimpleParticleEmitterWeakPtr GetTarGetPointee() const;
                    void SetTarget(SimpleParticleEmitterWeakPtr value);

                private:
                    SimpleParticleEmitterWeakPtr target;
            };
        }
    }

#endif