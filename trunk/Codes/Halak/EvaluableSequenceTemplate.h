#pragma once
#ifndef __HALAK_EVALUABLESEQUENCETEMPLATE_H__
#define __HALAK_EVALUABLESEQUENCETEMPLATE_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        template <typename T> class EvaluableSequenceTemplate
        {
            public:
                typedef typename T::element_type SequenceType;
                typedef typename SequenceType::KeyframeType KeyframeType;
                typedef typename KeyframeType::ValueType ValueType;

            public:
                EvaluableSequenceTemplate();
                ~EvaluableSequenceTemplate();

                void Update(float dt, uint timestamp);

                ValueType Evaluate();

                float GetTime() const;

                float GetVelocity() const;
                void  SetVelocity(float value);

                bool GetLooped() const;
                void SetLooped(bool value);

                T GetSource() const;
                void SetSource(T value);

            private:
                void UpdateValue();

            protected:
                float time;
                int timeIndex;
                float velocity;
                bool looped;
                bool timeChanged;
                T source;
                ValueType value;
                uint lastTimestamp;
        };
    }

#   include <Halak/EvaluableSequenceTemplate.inl>

#endif