#pragma once
#ifndef __HALAK_VECTOR3RANGESEQUENCE_H__
#define __HALAK_VECTOR3RANGESEQUENCE_H__

#   include <Halak/FWD.h>
#   include <Halak/Asset.h>
#   include <Halak/Range.h>
#   include <Halak/Vector3.h>

    namespace Halak
    {
        struct Vector3RangeKeyframe
        {
            typedef Range<Vector3> ValueType;

            ValueType Value;
            float Duration;
            float StartTime;

            Vector3RangeKeyframe();
            Vector3RangeKeyframe(ValueType value, float duration);
        };

        class Vector3RangeSequence : public Asset
        {
            public:
                typedef Vector3RangeKeyframe KeyframeType;

            public:
                Vector3RangeSequence();
                virtual ~Vector3RangeSequence();

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