#include <Halak/PCH.h>
#include <Halak/String.h>
#include <Halak/Math.h>
#include <ctype.h>

namespace Halak
{
    const String String::Empty = String(EmptyStringTag());

    String::String(const char* s, int startIndex)
    {
        HKAssert(startIndex <= static_cast<int>(strlen(s)));
        buffer.Reset(new StringBuffer(&s[startIndex]));
    }

    String::String(const char* s, int startIndex, int length)
    {
        HKAssert(startIndex <= static_cast<int>(strlen(s)));
        buffer.Reset(new StringBuffer(&s[startIndex], length));
    }

    String::String(EmptyStringTag)
        : buffer(new StringBuffer(EmptyStringTag()))
    {
    }

    String::String(AppendTag, const char* s1, int length1, const char* s2, int length2)
    {
        if (length1 == -1)
            length1 = static_cast<int>(strlen(s1));
        if (length2 == -1)
            length2 = static_cast<int>(strlen(s2));

        if (length1 > 0 && length2 > 0)
            buffer.Reset(new StringBuffer(InsertTag(), s1, length1, length1, s2, length2));
        else
        {
            if (length1 > 0)
                buffer.Reset(new StringBuffer(s1, length1));
            else
                buffer.Reset(new StringBuffer(s2, length2));
        }
    }

    void String::Insert(int index, const char* s, int length)
    {
        // index == buffer->length로 하게되면 맨 끝에 추가.
        HKAssertDebug(0 <= index && index <= buffer->length);
        if (buffer->length != 0)
            buffer.Reset(new StringBuffer(InsertTag(), buffer->s, buffer->length, index, s, length));
        else
            buffer.Reset(new StringBuffer(s, length)); 
    }

    void String::Append(const char* s)
    {
        if (s && s[0] != '\0')
            Insert(buffer->length, s, strlen(s));
    }

    void String::Append(const char* s, int length)
    {
        if (s && s[0] != '\0')
            Insert(buffer->length, s, length);
    }

    void String::Append(const String& s)
    {
        if (s.buffer->length > 0)
            Insert(buffer->length, s.buffer->s, s.buffer->length);
    }

    void String::Insert(int index, const char* s)
    {
        if (s && s[0] != '\0')
            Insert(Math::Min(Math::Max(index, 0), buffer->length), s);
    }

    void String::Insert(int index, const String& s)
    {
        if (s.buffer->length > 0)
            Insert(Math::Min(Math::Max(index, 0), buffer->length), s.buffer->s, s.buffer->length);
    }

    void String::Replace(char oldValue, char newValue)
    {
        for (int i = 0; i < buffer->length; i++)
        {
            if (buffer->s[i] == oldValue)
            {
                if (buffer.GetReferenceCount() > 1)
                    buffer.Reset(new StringBuffer(*buffer));

                buffer->s[i] = newValue;
            }
        }
    }

    void String::Trim()
    {
        const int length = buffer->length;
        int index1 = 0;
        int index2 = length - 1;

        while (index1 < length)
        {
            const char c = buffer->s[index1];
            if (c == ' ' || c == '\t')
            {
                index1++;
                continue;
            }
            else
                break;
        }

        while (index2 >= 0)
        {
            const char c = buffer->s[index2];
            if (c == ' ' || c == '\t')
            {
                index2--;
                continue;
            }
            else
                break;
        }

        if (index1 <= index2)
            buffer.Reset(new StringBuffer(&buffer->s[index1], index2 - index1 + 1));
    }

    void String::ToLower()
    {
        if (buffer.GetReferenceCount() > 1)
            buffer.Reset(new StringBuffer(*buffer));

        for (int i = 0; i < buffer->length; i++)
            buffer->s[i] = static_cast<char>(tolower(buffer->s[i]));
    }

    void String::ToUpper()
    {
        if (buffer.GetReferenceCount() > 1)
            buffer.Reset(new StringBuffer(*buffer));

        for (int i = 0; i < buffer->length; i++)
            buffer->s[i] = static_cast<char>(toupper(buffer->s[i]));
    }

    int String::Compare(const char* right) const
    {
        if (buffer->s == right)
            return 0;
        if (right == nullptr)
            return +1;

        return strcmp(buffer->s, right);
    }

    int String::Compare(const String& right) const
    {
        return Compare(right.buffer->s);
    }

    int String::CompareIgnoreCase(const char* right) const
    {
        if (buffer->s == right)
            return 0;
        if (right == nullptr)
            return +1;

        return _stricmp(buffer->s, right);
    }

    int String::CompareIgnoreCase(const String& right) const
    {
        return CompareIgnoreCase(right.buffer->s);
    }

    bool String::Equals(const char* right) const
    {
        if (buffer->s == right)
            return true;

        return strcmp(buffer->s, right) == 0;
    }

    bool String::Equals(const String& right) const
    {
        if (buffer == right.buffer)
            return true;
        if (buffer->length != right.buffer->length || buffer->hashCode != right.buffer->hashCode)
            return false;

        return strcmp(buffer->s, right.buffer->s) == 0;
    }

    bool String::EqualsIgnoreCase(const char* right) const
    {
        if (buffer->s == right)
            return true;

        return _stricmp(buffer->s, right) == 0;
    }

    bool String::EqualsIgnoreCase(const String& right) const
    {
        if (buffer == right.buffer)
            return true;
        if (buffer->length != right.buffer->length)
            return false;

        return _stricmp(buffer->s, right.buffer->s) == 0;
    }

    bool String::Contains(char c) const
    {
        for (int i = 0; i < buffer->length; i++)
        {
            if (buffer->s[i] == c)
                return true;
        }

        return false;
    }

    bool String::ContainsTemplate(const char* s, int length) const
    {
        if (buffer->length < length)
            return false;

        const int lengthDifference = buffer->length - length;
        for (int i = 0; i < lengthDifference; i++)
        {
            int k = 0;
            for (; k < length; k++)
            {
                if (buffer->s[i + k] != s[k])
                    break;
            }

            if (k == length)
                return true;
        }

        return false;
    }

    bool String::Contains(const char* s) const
    {
        if (s == nullptr)
            return false;
        if (s[0] == '\0')
            return true;

        return ContainsTemplate(s, static_cast<int>(strlen(s)));
    }

    bool String::Contains(const String& s) const
    {
        if (s.IsEmpty())
            return true;

        return ContainsTemplate(s.buffer->s, s.buffer->length);
    }

    bool String::ContainsIgnoreCase(char c) const
    {
        const int character = static_cast<char>(tolower(c));
        for (int i = 0; i < buffer->length; i++)
        {
            if (tolower(buffer->s[i]) == character)
                return true;
        }

        return false;
    }

    bool String::ContainsIgnoreCaseTemplate(const char* s, int length) const
    {
        UTF8CharEnumerator en1(*this);
        UTF8CharEnumerator en2(s, length);
        en2.MoveNext(); // HKLogicalAssert(true)
        while (en1.MoveNext())
        {
            if (tolower(en1.GetCurrent()) == tolower(en2.GetCurrent()))
            {
                if (en2.MoveNext() == false)
                    return true;
            }
            else
            {
                en2.Reset();
                en2.MoveNext();
            }
        }

        return false;
    }

    bool String::ContainsIgnoreCase(const char* s) const
    {
        if (s == nullptr)
            return false;
        if (s[0] == '\0')
            return true;

        return ContainsIgnoreCaseTemplate(s, static_cast<int>(strlen(s)));
    }

    bool String::ContainsIgnoreCase(const String& s) const
    {
        if (s.IsEmpty())
            return true;

        return ContainsIgnoreCaseTemplate(s.buffer->s, s.buffer->length);
    }

    bool String::StartsWithTemplate(const char* s, int length) const
    {
        if (GetLength() < length)
            return false;

        for (int i = 0; i < length; i++)
        {
            if (buffer->s[i] != s[i])
                return false;
        }

        return true;
    }

    bool String::StartsWith(const char* s) const
    {
        if (s == nullptr)
            return false;
        if (s[0] == '\0')
            return true;

        return StartsWithTemplate(s, static_cast<int>(strlen(s)));
    }

    bool String::StartsWith(const String& s) const
    {
        if (s.IsEmpty())
            return true;

        return StartsWithTemplate(s.buffer->s, s.buffer->length);
    }

    bool String::StartsWithIgnoreCaseTemplate(const char* s, int length) const
    {
        UTF8CharEnumerator en1(*this);
        UTF8CharEnumerator en2(s, length);
        en2.MoveNext(); // HKLogicalAssert(true)
        while (en1.MoveNext())
        {
            if (tolower(en1.GetCurrent()) == tolower(en2.GetCurrent()))
            {
                if (en2.MoveNext() == false)
                    return true;
            }
            else
                return false;
        }

        return false;
    }

    bool String::StartsWithIgnoreCase(const char* s) const
    {
        if (s == nullptr)
            return false;
        if (s[0] == '\0')
            return true;

        return StartsWithIgnoreCaseTemplate(s, static_cast<int>(strlen(s)));
    }

    bool String::StartsWithIgnoreCase(const String& s) const
    {
        if (s.IsEmpty())
            return false;

        return StartsWithIgnoreCaseTemplate(s.buffer->s, s.buffer->length);
    }

    bool String::EndsWithTemplate(const char* s, int length) const
    {
        for (int i = buffer->length - length; i < buffer->length; i++, s++)
        {
            if (buffer->s[i] != *s)
                return false;
        }

        return true;
    }

    bool String::EndsWith(const char* s) const
    {
        if (s == nullptr)
            return false;
        if (s[0] == '\0')
            return true;

        return EndsWithTemplate(s, static_cast<int>(strlen(s)));
    }

    bool String::EndsWith(const String& s) const
    {
        if (s.IsEmpty())
            return false;

        return EndsWithTemplate(s.buffer->s, s.buffer->length);
    }

    bool String::EndsWithIgnoreCaseTemplate(const char* s, int length) const
    {
        UTF8CharEnumerator en1(&buffer->s[buffer->length - length], length);
        UTF8CharEnumerator en2(s, length);
        en2.MoveNext(); // HKLogicalAssert(true)
        while (en1.MoveNext())
        {
            if (tolower(en1.GetCurrent()) == tolower(en2.GetCurrent()))
            {
                if (en2.MoveNext() == false)
                    return true;
            }
            else
                return false;
        }

        return false;
    }

    bool String::EndsWithIgnoreCase(const char* s) const
    {
        if (s == nullptr)
            return false;
        if (s[0] == '\0')
            return true;

        return EndsWithIgnoreCaseTemplate(s, static_cast<int>(strlen(s)));
    }

    bool String::EndsWithIgnoreCase(const String& s) const
    {
        if (s.IsEmpty())
            return false;

        return EndsWithIgnoreCaseTemplate(s.buffer->s, s.buffer->length);
    }

    int String::Find(char c, int index) const
    {
        HKAssert(0 <= index && index < buffer->length);

        for (int i = index; i < buffer->length; i++)
        {
            if (buffer->s[i] == c)
                return i;
        }

        return -1;
    }

    int String::FindTemplate(const char* s, int length, int index) const
    {
        if (buffer->length < index + length)
            return -1;

        const int lengthDifference = buffer->length - (index + length);
        for (int i = index; i < lengthDifference; i++)
        {
            int k = 0;
            for (; k < length; k++)
            {
                if (buffer->s[i + k] != s[k])
                    break;
            }

            if (k == length)
                return i;
        }

        return -1;
    }

    int String::Find(const char* s, int index) const
    {
        return FindTemplate(s, static_cast<int>(strlen(s)), index);
    }

    int String::Find(const String& s, int index) const
    {
        return FindTemplate(s.buffer->s, s.buffer->length, index);
    }

    int String::FindIgnoreCase(char c, int index) const
    {
        HKAssert(0 <= index && index < buffer->length);

        const int character = static_cast<int>(tolower(c));
        for (int i = index; i < buffer->length; i++)
        {
            if (tolower(buffer->s[i]) == character)
                return i;
        }

        return -1;
    }

    int String::FindIgnoreCaseTemplate(const char* s, int length, int index) const
    {
        int i = 0;
        int result = i;
        UTF8CharEnumerator en1(&buffer->s[index], buffer->length - index);
        UTF8CharEnumerator en2(s, length);
        en2.MoveNext(); // HKLogicalAssert(true)
        while (en1.MoveNext())
        {
            if (tolower(en1.GetCurrent()) == tolower(en2.GetCurrent()))
            {
                if (en2.MoveNext() == false)
                    return result;
            }
            else
            {
                en2.Reset();
                en2.MoveNext();
                result = i;
            }

            i++;
        }

        return -1;
    }

    int String::FindIgnoreCase(const char* s, int index) const
    {
        if (s && s[0] != '\0')
            return FindIgnoreCaseTemplate(s, static_cast<int>(strlen(s)), index);
        else
            return -1;
    }

    int String::FindIgnoreCase(const String& s, int index) const
    {
        if (s.IsEmpty() == false)
            return FindIgnoreCaseTemplate(s.buffer->s, s.buffer->length, index);
        else
            return -1;
    }

    int String::ReverseFind(char c, int index) const
    {
        HKAssert(0 <= index && index < buffer->length);

        for (int i = index; i >= 0; i--)
        {
            if (buffer->s[i] == c)
                return i;
        }

        return -1;
    }

    int String::ReverseFindTemplate(const char* s, int length, int index) const
    {
        for (int i = index - length; i >= 0; i--)
        {
            int k = 0;
            for (; k < length; k++)
            {
                if (buffer->s[i + k] != s[k])
                    break;
            }

            if (k == length)
                return i;
        }

        return -1;

    }

    int String::ReverseFind(const char* s, int index) const
    {
        if (s && s[0] != '\0')
            return ReverseFindTemplate(s, static_cast<int>(strlen(s)), index);
        else
            return -1;
    }

    int String::ReverseFind(const String& s, int index) const
    {
        return ReverseFindTemplate(s.buffer->s, s.buffer->length, index);
    }

    int String::ReverseFindIgnoreCase(char c, int index) const
    {
        HKAssert(0 <= index && index < buffer->length);

        const int character = static_cast<char>(tolower(c));
        for (int i = index; i >= 0; i--)
        {
            if (tolower(buffer->s[i]) == character)
                return i;
        }

        return -1;
    }

    int String::ReverseFindIgnoreCaseTemplate(const char* /*s*/, int /*length*/, int /*index*/) const
    {
        throw;
    }

    int String::ReverseFindIgnoreCase(const char* s, int index) const
    {
        return ReverseFindIgnoreCaseTemplate(s, static_cast<int>(strlen(s)), index);
    }

    int String::ReverseFindIgnoreCase(const String& s, int index) const
    {
        return ReverseFindIgnoreCaseTemplate(s.buffer->s, static_cast<int>(s.buffer->length), index);
    }

    String String::Substring(int startIndex) const
    {
        if (startIndex <= 0)
            return String(*this);
        if (startIndex >= buffer->length - 1)
            return String::Empty;

        return String(buffer->s, startIndex);
    }

    String String::Substring(int startIndex, int length) const
    {
        if (startIndex >= buffer->length - 1)
            return String::Empty;

        if (startIndex < 0)
        {
            length += startIndex;
            startIndex = 0;
        }

        if (startIndex == 0 && length >= buffer->length)
            return String(*this);

        return String(buffer->s, startIndex, length);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    String::StringBuffer::StringBuffer(const char* s)
        : s(nullptr),
          length(0),
          hashCode(0)
    {
        Initialize(s, static_cast<int>(strlen(s)));
    }

    String::StringBuffer::StringBuffer(EmptyStringTag)
        : s(new char [1]),
          length(0),
          hashCode(0)
    {
        s[0] = '\0';
    }

    String::StringBuffer::StringBuffer(InsertTag, const char* s1, int length1, int index, const char* s2, int length2)
    {
        HKAssertDebug(length1 > 0 && length2 > 0);

        this->length = length1 + length2;
        this->s = new char [this->length + 1];
        this->hashCode = 0;

        int   i = 0;
        char* destination = this->s;
        for (; i < index; i++, destination++, s1++)
        {
            (*destination) = (*s1);
            this->hashCode += static_cast<uint>(*destination) << i;
        }

        const int midterm = index + length2;
        for (; i < midterm; i++, destination++, s2++)
        {
            (*destination) = (*s2);
            this->hashCode += static_cast<uint>(*destination) << i;
        }

        for (; i < this->length; i++, destination++, s1++)
        {
            (*destination) = (*s1);
            this->hashCode += static_cast<uint>(*destination) << i;
        }

        HKAssertDebug(destination - this->s == this->length);
        (*destination) = '\0';
    }
    
    void String::StringBuffer::Initialize(const char* s, int length)
    {
        HKAssertDebug(length > 0);

        this->length = length;
        this->s = new char [this->length + 1];
        this->hashCode = 0;
        char* destination = this->s;
        for (int i = 0; i < length; i++, destination++)
        {
            (*destination) = s[i];
            this->hashCode += static_cast<uint>(s[i]) << i;
        }
 
        HKAssertDebug(destination - this->s == this->length);
        (*destination) = '\0';
    }
}