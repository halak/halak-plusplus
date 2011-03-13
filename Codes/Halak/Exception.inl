namespace Halak
{
    Exception::Exception()
        : std::exception()
    {
    }

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

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    BadCastException::BadCastException()
        : Exception()
    {
    }

    BadCastException::BadCastException(const char* what)
        : Exception(what)
    {
    }

    BadCastException::BadCastException(const BadCastException& original)
        : Exception(original)
    {
    }

    BadCastException& BadCastException::operator = (const BadCastException& right)
    {
        Exception::operator = (right);
        return *this;
    }
}