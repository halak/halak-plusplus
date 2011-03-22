#include <Halak/PCH.h>
#include <Halak/ColorSequence.h>
#include <Halak/Math.h>
#include <Halak/SequenceTemplate.h>

namespace Halak
{
    ColorKeyframe::ColorKeyframe()
        : Value(Color::White),
          Duration(0.0f),
          StartTime(0.0f)
    {
    }

    ColorKeyframe::ColorKeyframe(ValueType value, float duration)
        : Value(value),
          Duration(duration),
          StartTime(0.0f)
    {
    }

    ColorKeyframe::ValueType ColorKeyframe::Interpolate(const ColorKeyframe& k1, const ColorKeyframe& k2, float t)
    {
        if (t <= 0.0f)
            return k1.Value;
        if (t >= 1.0f)
            return k2.Value;

        return Math::Interpolate(k1.Value, k2.Value, t);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    ColorSequence::ColorSequence()
        : s(new SequenceTemplate<KeyframeType>())
    {
    }

    ColorSequence::~ColorSequence()
    {
        delete s;
    }

    void ColorSequence::AddKeyframe(const KeyframeType& item)
    {
        s->AddKeyframe(item);
    }

    void ColorSequence::InsertKeyframe(int index, const KeyframeType& item)
    {
        s->InsertKeyframe(index, item);
    }

    void ColorSequence::InsertKeyframe(float time, const KeyframeType& item)
    {
        s->InsertKeyframe(time, item);
    }

    void ColorSequence::RemoveKeyframe(int index)
    {
        s->RemoveKeyframe(index);
    }

    void ColorSequence::RemoveKeyframe(float time)
    {
        s->RemoveKeyframe(time);
    }

    void ColorSequence::RemoveAllKeyframes()
    {
        s->RemoveAllKeyframes();
    }

    int ColorSequence::GetNumberOfKeyframes()
    {
        return s->GetNumberOfKeyframes();
    }

    const ColorSequence::KeyframeType& ColorSequence::GetKeyframe(int index)
    {
        return s->GetKeyframe(index);
    }

    const ColorSequence::KeyframeType& ColorSequence::GetKeyframe(float time)
    {
        return s->GetKeyframe(time);
    }

    int ColorSequence::GetKeyframeIndex(float time)
    {
        return s->GetKeyframeIndex(time);
    }

    int ColorSequence::GetKeyframeIndex(float time, int startIndex)
    {
        return s->GetKeyframeIndex(time, startIndex);
    }

    void ColorSequence::SetKeyframe(int index, const KeyframeType& item)
    {
        return s->SetKeyframe(index, item);
    }

    float ColorSequence::GetDuration()
    {
        return s->GetDuration();
    }
}