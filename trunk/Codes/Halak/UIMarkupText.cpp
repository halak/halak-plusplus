#include <Halak/PCH.h>
#include <Halak/UIMarkupText.h>
#include <Halak/Assert.h>
#include <Halak/Color.h>
#include <algorithm>

namespace Halak
{
    const UIMarkupText UIMarkupText::Empty = UIMarkupText();

    UIMarkupText::UIMarkupText()
    {
    }

    UIMarkupText::UIMarkupText(const String text)
        : originalText(text)
    {
        Parse();
    }

    UIMarkupText::UIMarkupText(const UIMarkupText& original)
        : originalText(original.originalText),
          displayText(original.displayText)
    {
        Copy(phrases, original.phrases);
    }

    UIMarkupText::~UIMarkupText()
    {
        PhraseCollection deletingPhrases;
        deletingPhrases.swap(phrases);
        
        for (PhraseCollection::const_iterator it = deletingPhrases.begin(); it != deletingPhrases.end(); it++)
            delete (*it);
    }

    UIMarkupText& UIMarkupText::operator = (const UIMarkupText& original)
    {
        originalText = original.originalText;
        displayText = original.displayText;
        Copy(phrases, original.phrases);
        return *this;
    }

    bool UIMarkupText::operator == (const UIMarkupText& right) const
    {
        return originalText == right.originalText;
    }

    bool UIMarkupText::operator != (const UIMarkupText& right) const
    {
        return operator == (right);
    }

    void UIMarkupText::AddSubText(const String& subText)
    {
        if (subText.IsEmpty())
            return;

        phrases.push_back(new TextPhrase(subText));
        displayText += subText;
    }

    template <typename T> int UIMarkupText::AddSpecialPhrase(int index, char open, char close, String& inoutSubText)
    {
        if (index + 1 < originalText.GetLength())
        {
            if (originalText[index + 1] == open)
            {
                // ���� ���ڰ� ���������� ���� ���� ��
                // ���� ���� �ϳ��� �߰��մϴ�.
                inoutSubText += open;
                index += 2;
            }
            else
            {
                // �����ڸ� ã���ϴ�.
                const int closeIndex = originalText.Find(close, index + 1);
                if (closeIndex != -1)
                {
                    // �������� �׾Ƶ� ���ڿ��� �״�� �߰��մϴ�.
                    AddSubText(inoutSubText);

                    const String content = originalText.Substring(index + 1, closeIndex - index - 1);
                    if (content.IsEmpty() == false)
                        phrases.push_back(new T(content));

                    inoutSubText = String::Empty;
                    index = closeIndex + 1;
                }
                else
                {
                    // ���ȴµ� �� �������� ���� �߰��մϴ�.
                    inoutSubText += originalText[index++];
                }
            }
        }
        else
        {
            // ������ ���ڿ��� ���� �߰��մϴ�.
            inoutSubText += originalText[index++];
        }

        return index;
    }

    void UIMarkupText::Parse()
    {
        if (originalText.IsEmpty())
            return;

        String subText;

        for (int i = 0; i < originalText.GetLength();)
        {
            switch (originalText[i])
            {
                case '|':
                    i = AddSpecialPhrase<ColorPhrase>(i, '|', '|', subText);
                    break;
                case '[':
                    i = AddSpecialPhrase<ContentPhrase>(i, '[', ']', subText);
                    break;
                case ']':
                    if (i + 1 < originalText.GetLength())
                    {
                        if (originalText[i + 1] == ']')
                        {
                            // ']]' �� ��
                            // ==> ']'�� �߰��մϴ�.
                            subText += originalText[i];
                            i += 2;
                        }
                    }
                    else
                    {
                        // ']'�� ������ ��
                        subText += originalText[i++];
                    }
                    break;
                case '\r': // ���๮�� ó�� (Text Phrase ����)
                    AddSubText(subText);
                    phrases.push_back(new NewLinePhrase());

                    subText = String::Empty;
                    i++;

                    // '\r' ������ '\n'�� �̾����ٸ� '\n'�� �����մϴ�.
                    if (i < originalText.GetLength() && originalText[i] == '\n')
                        i++;

                    break;
                case '\n': // ���๮�� ó�� (Text Phrase ����)
                    AddSubText(subText);
                    phrases.push_back(new NewLinePhrase());

                    subText = String::Empty;
                    i++;
                    break;
                default:
                    subText += originalText[i++];
                    break;
            }
        }

        AddSubText(subText);
    }

    void UIMarkupText::Copy(PhraseCollection& outTarget, const PhraseCollection& original)
    {
        HKAssert(outTarget.size() == 0);

        outTarget.reserve(original.size());
        for (PhraseCollection::const_iterator it = original.begin(); it != original.end(); it++)
            outTarget.push_back((*it)->Clone());
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    UIMarkupText::Phrase::Phrase()
    {
    }

    UIMarkupText::Phrase::Phrase(const String& text)
        : text(text)
    {
    }

    UIMarkupText::Phrase::Phrase(const Phrase& original)
        : text(original.text)
    {
    }

    UIMarkupText::Phrase::~Phrase()
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    UIMarkupText::TextPhrase::TextPhrase(const String& text)
        : Phrase(text)
    {
    }

    UIMarkupText::TextPhrase::TextPhrase(const TextPhrase& original)
        : Phrase(original)
    {
    }

    UIMarkupText::TextPhrase::~TextPhrase()
    {
    }

    UIMarkupText::TextPhrase* UIMarkupText::TextPhrase::Clone() const
    {
        return new TextPhrase(*this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    UIMarkupText::NewLinePhrase::NewLinePhrase()
    {
    }

    UIMarkupText::NewLinePhrase::NewLinePhrase(const NewLinePhrase& original)
        : Phrase(original)
    {
    }

    UIMarkupText::NewLinePhrase::~NewLinePhrase()
    {
    }

    UIMarkupText::NewLinePhrase* UIMarkupText::NewLinePhrase::Clone() const
    {
        return new NewLinePhrase(*this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    UIMarkupText::ColorPhrase::ColorPhrase(const String& text)
        : Phrase(text),
          color(nullptr)
    {
        Color convertedColor = Color::Black;
        if (Color::CanParse(text.Substring(2)))
            color = new Color(Color::Parse(text.Substring(2)));
    }

    UIMarkupText::ColorPhrase::ColorPhrase(const ColorPhrase& original)
        : Phrase(original.text),
          color(original.color ? new Color(*original.color) : nullptr)
    {
    }

    UIMarkupText::ColorPhrase::~ColorPhrase()
    {
        delete color;
    }

    UIMarkupText::ColorPhrase* UIMarkupText::ColorPhrase::Clone() const
    {
        return new ColorPhrase(*this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    UIMarkupText::ContentPhrase::ContentPhrase(const String& text)
        : Phrase(text)
    {
        int colonIndex    = text.Find(':');
        int questionIndex = text.Find('?');
        if (colonIndex != -1)
        {
            type = text.Substring(0, colonIndex);
            type.Trim();
        }

        if (questionIndex != -1)
        {
            name = text.Substring(colonIndex + 1, questionIndex - colonIndex - 1);
            ParseAttributes(text.Substring(questionIndex + 1));
        }
        else
            name = text.Substring(colonIndex + 1);
    }

    UIMarkupText::ContentPhrase::ContentPhrase(const ContentPhrase& original)
        : Phrase(original),
          type(original.type),
          name(original.name),
          attributes(original.attributes)
    {
    }

    UIMarkupText::ContentPhrase::~ContentPhrase()
    {
    }

    UIMarkupText::ContentPhrase* UIMarkupText::ContentPhrase::Clone() const
    {
        return new ContentPhrase(*this);
    }

    const String& UIMarkupText::ContentPhrase::FindAttribute(const String& key) const
    {
        //struct Comparer
        //{
        //    bool operator () (const KeyValuePair& current)
        //    {
        //        return false;
        //    }
        //};

        //std::binary_search(attributes.begin(), attributes.end(), key, Comparer());

        return String::Empty;
    }

    void UIMarkupText::ContentPhrase::ParseAttributes(const String& text)
    {
        for (int i = 0; i < text.GetLength();)
        {
            const int equalSignIndex = text.Find('=', i);
            const int ampersandIndex = text.Find('&', i);
            if (i == -1)
                break;
            if (i == -1)
                i = text.GetLength();

            if (equalSignIndex < ampersandIndex)
            {
                String key = text.Substring(i, equalSignIndex - i);
                key.ToLower();
                attributes.push_back(KeyValuePair(name, text.Substring(equalSignIndex + 1, ampersandIndex - equalSignIndex - 1)));
            }

            i = ampersandIndex + 1;
        }

        struct Compare
        {
            bool operator () (const KeyValuePair& a, const KeyValuePair& b) const
            {
                return a.first < b.first;
            }
        };

        std::sort(attributes.begin(), attributes.end(), Compare());
    }
}