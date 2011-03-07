#pragma once
#ifndef __HALAK_SEQUENTIALPARTICLE_H__
#define __HALAK_SEQUENTIALPARTICLE_H__

#   include <Halak/FWD.h>
#   include <Halak/Particle.h>
#   include <Halak/Sprite.h>

    namespace Halak
    {
        class SequentialParticle : public Particle
        {
            public:
                float Rotation;
                Vector2 Scale;

                const int SpriteSequenceIndex;
                Sprite SpriteInstance;

                Vector3 LastLinearVelocityRange[2];
                float LastRotationRange[2];
                Vector2 LastScaleRange[2];
                Color LastTintRange[2];

                short LastLinearVelocityKeyrameIndex;
                short LastRotationKeyframeIndex;
                short LastScaleKeyframeIndex;
                short LastTintKeyframeIndex;
                short LastSpriteKeyframeIndex;

            public:
                inline SequentialParticle(float lifespan, Vector3 position, int spriteSequenceIndex);
                inline ~SequentialParticle();
        };
    }

#   include <Halak/SequentialParticle.inl>

#endif