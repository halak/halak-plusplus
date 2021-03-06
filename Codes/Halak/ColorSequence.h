#pragma once
#ifndef __HALAK_COLORSEQUENCE_H__
#define __HALAK_COLORSEQUENCE_H__

#   include <Halak/FWD.h>
#   include <Halak/Asset.h>
#   include <Halak/Color.h>

    namespace Halak
    {
        struct ColorKeyframe
        {
            typedef Color ValueType;

            ValueType Value;
            float Duration;
            float StartTime;

            ColorKeyframe();
            ColorKeyframe(ValueType value, float duration);

            static ValueType Interpolate(const ColorKeyframe& k1, const ColorKeyframe& k2, float t);
        };

        class ColorSequence : public Asset
        {
            public:
                typedef ColorKeyframe KeyframeType;

            public:
                ColorSequence();
                virtual ~ColorSequence();

                void AddKeyframe(const KeyframeType& item);
                void InsertKeyframe(int index, const KeyframeType& item);
                void InsertKeyframe(float time, const KeyframeType& item);
                void RemoveKeyframe(int index);
                void RemoveKeyframe(float time);
                void RemoveAllKeyframes();

                int GetNumberOfKeyframes();
                const KeyframeType& GetKeyframe(int index);
                const KeyframeType& GetKeyframe(float time);
                int GetKeyframeIndex(float time);
                int GetKeyframeIndex(float time, int startIndex);
                void SetKeyframe(int index, const KeyframeType& item);

                float GetDuration();
           
            private:
                SequenceTemplate<KeyframeType>* s;
        };
    }

#endif