namespace Halak
{
    Exception::Exception()
    {
    }

    Exception::Exception(const char* message)
        : Message(message)
    {
    }

    Exception::Exception(const Exception& original)
        : Message(original.Message)
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    BadCastException::BadCastException()
        : Exception()
    {
    }

    BadCastException::BadCastException(const char* message)
        : Exception(message)
    {
    }

    BadCastException::BadCastException(const BadCastException& original)
        : Exception(original)
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    OutOfRangeException::OutOfRangeException()
        : Exception(),
          Index(-1),
          Count(0)
    {
    }

    OutOfRangeException::OutOfRangeException(const char* message, int index, int count)
        : Exception(message),
          Index(index),
          Count(count)
    {
    }

    OutOfRangeException::OutOfRangeException(const OutOfRangeException& original)
        : Exception(original)
    {
    }
}