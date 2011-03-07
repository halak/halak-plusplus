#pragma once
#ifndef __HALAK_EVALUABLEFLOATSEQUENCE_H__
#define __HALAK_EVALUABLEFLOATSEQUENCE_H__

#   include <Halak/FWD.h>
#   include <Halak/IFloatEvaluable.h>
#   include <Halak/IUpdateable.h>

    namespace Halak
    {
        class EvaluableFloatSequence : public IFloatEvaluable, public IUpdateable
        {
            typedef FloatSequencePtr SharedSequencePointerType;
            public:
                EvaluableFloatSequence();
                virtual ~EvaluableFloatSequence();

                virtual void Update(float dt, uint timestamp);

                virtual float Evaluate();

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