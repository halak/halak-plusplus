#pragma once
#ifndef __HALAK_EVALUABLERANGESEQUENCETEMPLATE_H__
#define __HALAK_EVALUABLERANGESEQUENCETEMPLATE_H__
/**
#   include <Halak/FWD.h>
#   include <Halak/EvaluableSequenceTemplate.h>
#   include <random>

    namespace Halak
    {
        template <typename T> class EvaluableRangeSequenceTemplate : public EvaluableSequenceTemplate<T>
        {
            public:
                typedef typename ValueType::ElementType ElementType;

            public:
                EvaluableRangeSequenceTemplate();
                EvaluableRangeSequenceTemplate(ulong seed);
                ~EvaluableRangeSequenceTemplate();

                // ""overloading""
                ElementType Evaluate();

                void SetSeed(ulong seed);

            private:
                // ""overloading""
                void UpdateValue();

            private:
                std::tr1::mt19937 randomEngine;
                std::tr1::uniform_real<float> normalize;
                ElementType range[2];
                ElementType value;
        };
    }

#   include <Halak/EvaluableRangeSequenceTemplate.inl>
**/
#endif