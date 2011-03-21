#pragma once
#ifndef __HALAK_QUATERNION_H__
#define __HALAK_QUATERNION_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        struct Quaternion
        {
            float X;
            float Y;
            float Z;
            float W;

            inline Quaternion();
            inline Quaternion(float x, float y, float z);
            inline Quaternion(float x, float y, float z, float w);
            inline Quaternion(const Quaternion& original);

            inline Quaternion& operator = (const Quaternion& original);
            
            inline bool operator == (const Quaternion& right) const;
            inline bool operator != (const Quaternion& right) const;

            static const Quaternion Zero;
            static const Quaternion Identity;
        };
    }

#   include <Halak/Quaternion.h>

#endif