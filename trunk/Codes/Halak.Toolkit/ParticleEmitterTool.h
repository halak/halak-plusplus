#pragma once
#ifndef __HALAK_TOOLKIT_PARTICLEEMITTERTOOL_H__
#define __HALAK_TOOLKIT_PARTICLEEMITTERTOOL_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/Tool.h>
#   include <Halak/IDrawable.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class ParticleEmitterTool : public Tool, public IDrawable
            {
                public:
                    ParticleEmitterTool(GameStructure* structure);
                    virtual ~ParticleEmitterTool();

                protected:
                    ParticleEmitterWeakPtr GetTargetPointee() const;
                    void SetTarget(ParticleEmitterWeakPtr value);

                private:
                    GameStructure* structure;
                    ParticleEmitterWeakPtr target;
            };
        }
    }

#endif