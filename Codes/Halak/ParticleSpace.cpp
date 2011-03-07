#include <Halak/ParticleSpace.h>
#include <Halak/ParticleEmitter.h>

namespace Halak
{
    ParticleSpace::ParticleSpace()
    {
    }

    ParticleSpace::~ParticleSpace()
    {
    }

    void ParticleSpace::Update(float dt, uint timestamp)
    {
        for (EmitterCollection::iterator it = emitters.begin(); it != emitters.end(); it++)
        {
            (*it)->Update(dt, timestamp);
        }
    }
}