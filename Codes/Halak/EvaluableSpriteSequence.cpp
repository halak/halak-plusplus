#include <Halak/PCH.h>
#include <Halak/EvaluableSpriteSequence.h>
#include <Halak/EvaluableSequenceTemplate.h>
#include <Halak/SpriteSequence.h>

namespace Halak
{
    EvaluableSpriteSequence::EvaluableSpriteSequence()
        : s(new EvaluableSequenceTemplate<SharedSequencePointerType>())
    {
    }

    EvaluableSpriteSequence::~EvaluableSpriteSequence()
    {
        delete s;
    }

    void EvaluableSpriteSequence::Update(float dt, uint timestamp)
    {
        s->Update(dt, timestamp);
    }

    Sprite EvaluableSpriteSequence::Evaluate()
    {
        return s->Evaluate();
    }

    float EvaluableSpriteSequence::GetTime() const
    {
        return s->GetTime();
    }

    float EvaluableSpriteSequence::GetVelocity() const
    {
        return s->GetVelocity();
    }

    void EvaluableSpriteSequence::SetVelocity(float value)
    {
        s->SetVelocity(value);
    }

    bool EvaluableSpriteSequence::GetLooped() const
    {
        return s->GetLooped();
    }

    void EvaluableSpriteSequence::SetLooped(bool value)
    {
        s->SetLooped(value);
    }

    EvaluableSpriteSequence::SharedSequencePointerType EvaluableSpriteSequence::GetSource() const
    {
        return s->GetSource();
    }

    void EvaluableSpriteSequence::SetSource(SharedSequencePointerType value)
    {
        s->SetSource(value);
    }
}