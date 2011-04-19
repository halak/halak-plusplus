#include <Halak/PCH.h>
#include <Halak/StringReader.h>

namespace Halak
{
    StringReader::StringReader(const String& text)
        : text(text),
          index(0)
    {
    }

    String StringReader::ReadLine()
    {
        String result;

        for (; index < text.GetLength(); index++)
        {
            const char c = text[index];
            if (c == '\r' || c == '\n')
            {
                if (c == '\r' && index + 1 < text.GetLength() && text[index + 1] == '\n')
                {
                    // "\r\n"
                    index += 2;
                    return result;
                }
                else
                {
                    // "\r"
                    // "\n"
                    index += 1;
                    return result;
                }
            }
            else
                result += c;
        }

        return result;
    }

    bool StringReader::IsTerminated() const
    {
        return index >= text.GetLength();
    }
}