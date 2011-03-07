#pragma once
#ifndef __HALAK_QUATERNION_H__
#define __HALAK_QUATERNION_H__

    namespace Halak
    {
        struct Quaternion
        {
            float X;
            float Y;
            float Z;
            float W;

            Quaternion();
            Quaternion(float x, float y, float z);
            Quaternion(float x, float y, float z, float w);
            Quaternion(const Quaternion& original);

            Quaternion& operator = (const Quaternion& original);
            
            bool operator == (const Quaternion& right) const;
            bool operator != (const Quaternion& right) const;

            static const Quaternion Zero;
            static const Quaternion Identity;
        };
    }

#endif