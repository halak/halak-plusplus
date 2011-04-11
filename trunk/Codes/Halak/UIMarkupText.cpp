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
                // 여는 문자가 연속적으로 써져 있을 때
                // 여는 문자 하나를 추가합니다.
                inoutSubText += open;
                index += 2;
            }
            else
            {
                // 종결자를 찾습니다.
                const int closeIndex = originalText.Find(close, index + 1);
                if (closeIndex != -1)
                {
                    // 그전까지 쌓아둔 문자열을 그대로 추가합니다.
                    AddSubText(inoutSubText);

                    const String content = originalText.Substring(index + 1, closeIndex - index - 1);
                    if (content.IsEmpty() == false)
                        phrases.push_back(new T(content));

                    inoutSubText = String::Empty;
                    index = closeIndex + 1;
                }
                else
                {
                    // 열렸는데 안 닫혀있을 때는 추가합니다.
                    inoutSubText += originalText[index++];
                }
            }
        }
        else
        {
            // 마지막 문자였을 때는 추가합니다.
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
                            // ']]' 일 때
                            // ==> ']'를 추가합니다.
                            subText += originalText[i];
                            i += 2;
                        }
                    }
                    else
                    {
                        // ']'로 끝났을 때
                        subText += originalText[i++];
                    }
                    break;
                case '\r': // 개행문자 처리 (Text Phrase 나눔)
                    AddSubText(subText);
                    phrases.push_back(new NewLinePhrase());

                    subText = String::Empty;
                    i++;

                    // '\r' 다음에 '\n'이 이어진다면 '\n'을 무시합니다.
                    if (i < originalText.GetLength() && originalText[i] == '\n')
                        i++;

                    break;
                case '\n': // 개행문자 처리 (Text Phrase 나눔)
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