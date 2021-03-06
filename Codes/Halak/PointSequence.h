#pragma once
#ifndef __HALAK_POINTSEQUENCE_H__
#define __HALAK_POINTSEQUENCE_H__

#   include <Halak/FWD.h>
#   include <Halak/Asset.h>
#   include <Halak/Point.h>

    namespace Halak
    {
        struct PointKeyframe
        {
            typedef Point ValueType;

            ValueType Value;
            float Duration;
            float StartTime;

            PointKeyframe();
            PointKeyframe(ValueType value, float duration);

            static ValueType Interpolate(const PointKeyframe& k1, const PointKeyframe& k2, float t);
        };

        class PointSequence : public Asset
        {
            public:
                typedef PointKeyframe KeyframeType;

            public:
                PointSequence();
                virtual ~PointSequence();

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