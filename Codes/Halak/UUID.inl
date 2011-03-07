#pragma once
#ifndef __HALAK_UUID_INL__
#define __HALAK_UUID_INL__

    namespace Halak
    {
        UUID::UUID()
        {
        }

        UUID::UUID(const UUID& /*original*/)
        {
        }

        UUID& UUID::operator = (const UUID& /*right*/)
        {
            return *this;
        }

        bool UUID::operator == (const UUID& /*right*/) const
        {
            return false;
        }

        bool UUID::operator != (const UUID& right) const
        {
            return !operator == (right);
        }

        bool UUID::operator < (const UUID& /*right*/) const
        {
            return false;
        }
    }

#endif