#pragma once
#ifndef __HALAK_SEQUENCETEMPLATE_H__
#define __HALAK_SEQUENCETEMPLATE_H__

#   include <Halak/FWD.h>
#   include <vector>

    namespace Halak
    {
        template <typename T> class SequenceTemplate
        {
            public:
                SequenceTemplate();

                void AddKeyframe(const T& item);
                void InsertKeyframe(int index, const T& item);
                void InsertKeyframe(float time, const T& item);
                void RemoveKeyframe(int index);
                void RemoveKeyframe(float time);
                void RemoveAllKeyframes();

                int GetNumberOfKeyframes();
                const T& GetKeyframe(int index);
                const T& GetKeyframe(float time);
                int GetKeyframeIndex(float time, int startIndex = 0);
                void SetKeyframe(int index, const T& item);

                float GetDuration();

            private:
                void ResetDuration();
                void UpdateStartTimes();

            private:
                std::vector<T> keyframes;
                float duration;
                bool startTimeChanged;
        };
    }

#   include <Halak/SequenceTemplate.inl>

#endif