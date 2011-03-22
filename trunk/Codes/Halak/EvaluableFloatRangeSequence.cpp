#include <Halak/PCH.h>
#include <Halak/EvaluableFloatRangeSequence.h>
#include <Halak/EvaluableSequenceTemplate.h>
#include <Halak/FloatRangeSequence.h>

namespace Halak
{
    EvaluableFloatRangeSequence::EvaluableFloatRangeSequence()
        : s(new EvaluableSequenceTemplate<SharedSequencePointerType>())
    {
    }

    EvaluableFloatRangeSequence::~EvaluableFloatRangeSequence()
    {
        delete s;
    }

    void EvaluableFloatRangeSequence::Update(float dt, uint timestamp)
    {
        s->Update(dt, timestamp);
    }

    FloatRange EvaluableFloatRangeSequence::Evaluate()
    {
        return s->Evaluate();
    }

    float EvaluableFloatRangeSequence::GetTime() const
    {
        return s->GetTime();
    }

    float EvaluableFloatRangeSequence::GetVelocity() const
    {
        return s->GetVelocity();
    }

    void EvaluableFloatRangeSequence::SetVelocity(float value)
    {
        s->SetVelocity(value);
    }

    bool EvaluableFloatRangeSequence::GetLooped() const
    {
        return s->GetLooped();
    }

    void EvaluableFloatRangeSequence::SetLooped(bool value)
    {
        s->SetLooped(value);
    }

    EvaluableFloatRangeSequence::SharedSequencePointerType EvaluableFloatRangeSequence::GetSource() const
    {
        return s->GetSource();
    }

    void EvaluableFloatRangeSequence::SetSource(SharedSequencePointerType value)
    {
        s->SetSource(value);
    }
}