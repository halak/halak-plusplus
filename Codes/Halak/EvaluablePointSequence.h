#pragma once
#ifndef __HALAK_EVALUABLEPOINTSEQUENCE_H__
#define __HALAK_EVALUABLEPOINTSEQUENCE_H__

#   include <Halak/FWD.h>
#   include <Halak/IPointEvaluable.h>
#   include <Halak/IUpdateable.h>
#   include <Halak/Point.h>

    namespace Halak
    {
        class EvaluablePointSequence : public IPointEvaluable, public IUpdateable
        {
            typedef PointSequencePtr SharedSequencePointerType;
            public:
                EvaluablePointSequence();
                virtual ~EvaluablePointSequence();

                virtual void Update(float dt, uint timestamp);

                virtual Point Evaluate();

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