#include <Halak/PCH.h>
#include <Halak/Exception.h>

namespace Halak
{
    Exception& Exception::operator = (const Exception& right)
    {
        if (this == &right)
            return *this;

        Message = right.Message;
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    BadArgumentException& BadArgumentException::operator = (const BadArgumentException& right)
    {
        if (this == &right)
            return *this;

        Exception::operator = (right);
        ArgumentName = right.ArgumentName;
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    BadCastException& BadCastException::operator = (const BadCastException& right)
    {
        if (this == &right)
            return *this;

        Exception::operator = (right);
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    OutOfRangeException& OutOfRangeException::operator = (const OutOfRangeException& right)
    {
        if (this == &right)
            return *this;

        Exception::operator = (right);
        Index = right.Index;
        Count = right.Count;
        return *this;
    }
}