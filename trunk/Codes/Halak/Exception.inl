#pragma once
#ifndef __HALAK_EXCEPTION_INL__
#define __HALAK_EXCEPTION_INL__

    namespace Halak
    {
        Exception::Exception(const char* what)
            : std::exception(what)
        {
        }

        Exception::Exception(const Exception& original)
            : std::exception(original)
        {
        }

        Exception& Exception::operator = (const Exception& right)
        {
            std::exception::operator = (right);
            return *this;
        }
    }

#endif