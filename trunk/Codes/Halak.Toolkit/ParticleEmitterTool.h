#pragma once
#ifndef __HALAK_WXTOOLKIT_PARTICLEEMITTERTOOL_H__
#define __HALAK_WXTOOLKIT_PARTICLEEMITTERTOOL_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <Halak.wxToolkit/Tool.h>
#   include <Halak/IDrawable.h>

    namespace Halak
    {
        namespace wxToolkit
        {
            class ParticleEmitterTool : public Tool, public IDrawable
            {
                public:
                    ParticleEmitterTool(ServiceTree* services);
                    virtual ~ParticleEmitterTool();

                protected:
                    ParticleEmitterWeakPtr GetTarGetPointee() const;
                    void SetTarget(ParticleEmitterWeakPtr value);

                private:
                    ServiceTree* services;
                    ParticleEmitterWeakPtr target;
            };
        }
    }

#endif