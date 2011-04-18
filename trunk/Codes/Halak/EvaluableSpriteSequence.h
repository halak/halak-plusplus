#pragma once
#ifndef __HALAK_EvaluableSpriteSequence_H__
#define __HALAK_EvaluableSpriteSequence_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>
#   include <Halak/ISpriteEvaluable.h>
#   include <Halak/IUpdateable.h>

    namespace Halak
    {
        class EvaluableSpriteSequence : public SharedObject, public ISpriteEvaluable, public IUpdateable
        {
            typedef SpriteSequencePtr SharedSequencePointerType;
            public:
                EvaluableSpriteSequence();
                virtual ~EvaluableSpriteSequence();

                virtual void Update(float dt, uint timestamp);

                virtual Sprite Evaluate();

                float GetTime() const;

                float GetVelocity() const;
                void  SetVelocity(float value);

                bool GetLooped() const;
                void SetLooped(bool value);

                SharedSequencePointerType GetSource() const;
                void SetSource(SharedSequencePointerType value);

            private:
                EvaluableSequenceTemplate<SharedSequencePointerType>* s;
        };
    }

#endif