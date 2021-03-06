#pragma once
#ifndef __HALAK_SPRITESEQUENCE_H__
#define __HALAK_SPRITESEQUENCE_H__

#   include <Halak/FWD.h>
#   include <Halak/Asset.h>
#   include <Halak/Sprite.h>

    namespace Halak
    {
        struct SpriteKeyframe
        {
            typedef Sprite ValueType;

            ValueType Value;
            float Duration;
            float StartTime;

            SpriteKeyframe();
            SpriteKeyframe(ValueType value, float duration);

            static ValueType Interpolate(const SpriteKeyframe& k1, const SpriteKeyframe& k2, float t);
        };

        class SpriteSequence : public Asset
        {
            public:
                typedef SpriteKeyframe KeyframeType;

            public:
                SpriteSequence();
                virtual ~SpriteSequence();

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