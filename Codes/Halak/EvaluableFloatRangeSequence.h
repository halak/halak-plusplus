#pragma once
#ifndef __HALAK_EVALUABLEFLOATRANGESEQUENCE_H__
#define __HALAK_EVALUABLEFLOATRANGESEQUENCE_H__

#   include <Halak/FWD.h>
#   include <Halak/IFloatRangeEvaluable.h>
#   include <Halak/IUpdateable.h>

    namespace Halak
    {
        class EvaluableFloatRangeSequence : public IFloatRangeEvaluable, public IUpdateable
        {
            typedef FloatRangeSequencePtr SharedSequencePointerType;
            public:
                EvaluableFloatRangeSequence();
                virtual ~EvaluableFloatRangeSequence();

                virtual void Update(float dt, uint timestamp);

                virtual FloatRange Evaluate();

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