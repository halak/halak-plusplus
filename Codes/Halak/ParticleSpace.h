#pragma once
#ifndef __HALAK_PARTICLESPACE_H__
#define __HALAK_PARTICLESPACE_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/IUpdateable.h>
#   include <vector>

    namespace Halak
    {
        class ParticleSpace : public GameComponent, public IUpdateable
        {
            HKClassFOURCC('P', 'T', 'S', 'P');
            public:
                typedef std::vector<ParticleEmitterPtr> EmitterCollection;

            public:
                ParticleSpace();

                virtual void Update(float dt, uint timestamp);

            protected:
                virtual ~ParticleSpace();

            private:
                EmitterCollection emitters;
        };
    }

#endif