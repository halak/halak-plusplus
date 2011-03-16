#pragma once
#ifndef __HALAK_UUID_H__
#define __HALAK_UUID_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        struct UUID
        {
            HKDeclareStructFOURCC('U', 'U', 'I', 'D');

            dword values[4];

            inline UUID();
            inline UUID(const UUID& original);

            inline UUID& operator = (const UUID& right);
            inline bool operator == (const UUID& right) const;
            inline bool operator != (const UUID& right) const;

            inline bool operator < (const UUID& right) const;
        };
    }

#   include <Halak/UUID.inl>

#endif