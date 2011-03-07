#include <Halak/EvaluableFloatConstant.h>

namespace Halak
{
    EvaluableFloatConstant::EvaluableFloatConstant()
        : value(0.0f)
    {
    }

    EvaluableFloatConstant::EvaluableFloatConstant(ValueType value)
        : value(value)
    {
    }

    EvaluableFloatConstant::~EvaluableFloatConstant()
    {
    }

    EvaluableFloatConstant::ValueType EvaluableFloatConstant::Evaluate()
    {
        return value;
    }

    EvaluableFloatConstant::ValueType EvaluableFloatConstant::GetValue() const
    {
        return value;
    }

    void EvaluableFloatConstant::SetValue(ValueType value)
    {
        this->value = value;
    }
}