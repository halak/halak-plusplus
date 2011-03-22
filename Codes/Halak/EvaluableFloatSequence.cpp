#include <Halak/PCH.h>
#include <Halak/EvaluableFloatSequence.h>
#include <Halak/EvaluableSequenceTemplate.h>
#include <Halak/FloatSequence.h>

namespace Halak
{
    EvaluableFloatSequence::EvaluableFloatSequence()
        : s(new EvaluableSequenceTemplate<SharedSequencePointerType>())
    {
    }

    EvaluableFloatSequence::~EvaluableFloatSequence()
    {
        delete s;
    }

    void EvaluableFloatSequence::Update(float dt, uint timestamp)
    {
        s->Update(dt, timestamp);
    }

    float EvaluableFloatSequence::Evaluate()
    {
        return s->Evaluate();
    }

    float EvaluableFloatSequence::GetTime() const
    {
        return s->GetTime();
    }

    float EvaluableFloatSequence::GetVelocity() const
    {
        return s->GetVelocity();
    }

    void EvaluableFloatSequence::SetVelocity(float value)
    {
        s->SetVelocity(value);
    }

    bool EvaluableFloatSequence::GetLooped() const
    {
        return s->GetLooped();
    }

    void EvaluableFloatSequence::SetLooped(bool value)
    {
        s->SetLooped(value);
    }

    EvaluableFloatSequence::SharedSequencePointerType EvaluableFloatSequence::GetSource() const
    {
        return s->GetSource();
    }

    void EvaluableFloatSequence::SetSource(SharedSequencePointerType value)
    {
        s->SetSource(value);
    }
}