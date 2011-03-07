#pragma once
#ifndef __HALAK_EVALUABLEFLOATCONSTANT_H__
#define __HALAK_EVALUABLEFLOATCONSTANT_H__

#   include <Halak/FWD.h>
#   include <Halak/IFloatEvaluable.h>

    namespace Halak
    {
        class EvaluableFloatConstant : public IFloatEvaluable
        {
            typedef float ValueType;
            public:
                EvaluableFloatConstant();
                EvaluableFloatConstant(ValueType value);
                virtual ~EvaluableFloatConstant();

                virtual ValueType Evaluate();

                ValueType GetValue() const;
                void SetValue(ValueType value);

            private:
                ValueType value;
        };
    }

#endif