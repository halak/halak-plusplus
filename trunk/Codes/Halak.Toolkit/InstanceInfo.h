#pragma once
#ifndef __HALAK_TOOKIT_INSTANCEINFO_H__
#define __HALAK_TOOKIT_INSTANCEINFO_H__

#   include <Halak.Toolkit/FWD.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class InstanceInfo
            {
                public:
                    inline explicit InstanceInfo(const TypeInfo* typeInfo);
                    inline InstanceInfo(const TypeInfo* typeInfo, int pointerDepth);
                    inline InstanceInfo(const TypeInfo* typeInfo, bool isReference);
                    inline InstanceInfo(const TypeInfo* typeInfo, int pointerDepth, bool isReference);
                    inline InstanceInfo(const InstanceInfo& original);
                    inline ~InstanceInfo();

                    inline const TypeInfo* GetType() const;
                    inline int GetPointerDepth() const;
                    inline bool IsReference() const;

                    inline InstanceInfo& operator = (const InstanceInfo& right);
                    inline bool operator == (const InstanceInfo& right) const;
                    inline bool operator != (const InstanceInfo& right) const;

                    template <typename T> static InstanceInfo From();

                public:
                    static const InstanceInfo Empty;

                private:
                    enum Fields
                    {
                        IsReferenceBit   = 0x10,
                        PointerDepthBits = 0x0F,
                    };

                    static byte ComposeFields(int pointerDepth, bool isReference);

                private:
                    const TypeInfo* typeInfo;
                    byte fields;
            };
        }
    };

#   include <Halak.Toolkit/InstanceInfo.inl>

#endif