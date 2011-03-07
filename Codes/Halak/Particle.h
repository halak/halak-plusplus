#pragma once
#ifndef __HALAK_PARTICLE_H__
#define __HALAK_PARTICLE_H__

#   include <Halak/FWD.h>
#   include <Halak/Color.h>
#   include <Halak/Vector3.h>

    namespace Halak
    {
        class Particle
        {
            public:
                float Age;
                float Lifespan;

                Vector3 Position;
                Vector3 LinearVelocity;
                Color Tint;

            public:
                inline Particle();
                inline Particle(float lifespan, Vector3 position);
                inline Particle(float lifespan, Vector3 position, Vector3 linearVelocity, Color tint);

            protected:
                // Particle* 인채로 delete하지 말라는 의도입니다.
                inline ~Particle();

            private:
                Particle(const Particle&);
                Particle& operator = (const Particle&);
        };
    }

#   include <Halak/Particle.inl>

#endif