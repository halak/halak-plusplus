#pragma once
#ifndef __HALAK_UUID_H__
#define __HALAK_UUID_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        struct UUID
        {
            dword Values[4];

            inline UUID();
            inline UUID(const UUID& original);

            inline UUID& operator = (const UUID& right);
            inline bool operator == (const UUID& right) const;
            inline bool operator != (const UUID& right) const;

            inline bool operator < (const UUID& right) const;

            static const UUID Empty;
        };
    }

#   include <Halak/UUID.inl>

#endif