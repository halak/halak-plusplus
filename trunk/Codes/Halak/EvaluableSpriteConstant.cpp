#include <Halak/PCH.h>
#include <Halak/EvaluableSpriteConstant.h>
#include <Halak/Texture2D.h>

namespace Halak
{
    EvaluableSpriteConstant::EvaluableSpriteConstant()
    {
    }

    EvaluableSpriteConstant::EvaluableSpriteConstant(ValueType value)
        : value(value)
    {
    }

    EvaluableSpriteConstant::~EvaluableSpriteConstant()
    {
    }

    EvaluableSpriteConstant::ValueType EvaluableSpriteConstant::Evaluate()
    {
        return value;
    }

    EvaluableSpriteConstant::ValueType EvaluableSpriteConstant::GetValue() const
    {
        return value;
    }

    void EvaluableSpriteConstant::SetValue(ValueType value)
    {
        this->value = value;
    }
}