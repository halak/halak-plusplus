#pragma once
#ifndef __HALAK_EVALUABLEFLOATCONSTANT_H__
#define __HALAK_EVALUABLEFLOATCONSTANT_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>
#   include <Halak/IFloatEvaluable.h>

    namespace Halak
    {
        class EvaluableFloatConstant : public SharedObject, public IFloatEvaluable
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