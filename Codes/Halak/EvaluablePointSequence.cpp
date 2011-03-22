#include <Halak/PCH.h>
#include <Halak/EvaluablePointSequence.h>
#include <Halak/EvaluableSequenceTemplate.h>
#include <Halak/PointSequence.h>

namespace Halak
{
    EvaluablePointSequence::EvaluablePointSequence()
        : s(new EvaluableSequenceTemplate<SharedSequencePointerType>())
    {
    }

    EvaluablePointSequence::~EvaluablePointSequence()
    {
        delete s;
    }

    void EvaluablePointSequence::Update(float dt, uint timestamp)
    {
        s->Update(dt, timestamp);
    }

    Point EvaluablePointSequence::Evaluate()
    {
        return s->Evaluate();
    }

    float EvaluablePointSequence::GetTime() const
    {
        return s->GetTime();
    }

    float EvaluablePointSequence::GetVelocity() const
    {
        return s->GetVelocity();
    }

    void EvaluablePointSequence::SetVelocity(float value)
    {
        s->SetVelocity(value);
    }

    bool EvaluablePointSequence::GetLooped() const
    {
        return s->GetLooped();
    }

    void EvaluablePointSequence::SetLooped(bool value)
    {
        s->SetLooped(value);
    }

    EvaluablePointSequence::SharedSequencePointerType EvaluablePointSequence::GetSource() const
    {
        return s->GetSource();
    }

    void EvaluablePointSequence::SetSource(SharedSequencePointerType value)
    {
        s->SetSource(value);
    }
}