//#include <Halak/PCH.h>
//#include <Halak/UIMarkupText.h>
//#include <Halak/Assert.h>
//#include <Halak/Color.h>
//
//namespace Halak
//{
//        const MarkupText MarkupText::Empty = MarkupText();
//
//        MarkupText::MarkupText()
//        {
//        }
//
//        MarkupText::MarkupText(const String text)
//            : originalText(text)
//        {
//            Parse();
//        }
//
//        MarkupText::MarkupText(const MarkupText& original)
//            : originalText(original.originalText),
//              displayText(original.displayText)
//        {
//            Copy(phrases, original.phrases);
//        }
//
//        MarkupText::~MarkupText()
//        {
//            PhraseCollection deletingCollection;
//            deletingCollection.swap(phrases);
//
//            for (PhraseCollection::iterator it = deletingCollection.begin(); it != deletingCollection.end(); it++)
//                delete *it;
//        }
//
//        const String& MarkupText::GetOriginalText() const
//        {
//            return originalText;
//        }
//
//        const String& MarkupText::GetDisplayText() const
//        {
//            return displayText;
//        }
//
//        const MarkupText::PhraseCollection& MarkupText::GetPhrases() const
//        {
//            return phrases;
//        }
//
//        MarkupText& MarkupText::operator = (const MarkupText& original)
//        {
//            originalText = original.originalText;
//            displayText = original.displayText;
//            Copy(phrases, original.phrases);
//            return *this;
//        }
//
//        bool MarkupText::operator == (const MarkupText& right) const
//        {
//            return originalText == right.originalText;
//        }
//
//        bool MarkupText::operator != (const MarkupText& right) const
//        {
//            return operator == (right);
//        }
//
//        void MarkupText::AddSubText(const String subText)
//        {
//            if (subText.IsEmpty() == false)
//            {
//                phrases.push_back(new TextPhrase(subText));
//                displayText += subText;
//            }
//        }
//
//        template <typename T> int MarkupText::AddSpecialPhrase(int index, char open, char close, String& outSubText)
//        {
//            if (index + 1 < static_cast<int>(originalText.GetLength()))
//            {
//                if (originalText[index + 1] == open)
//                {
//                    // 여는 문자가 연속적으로 써져 있을 때
//                    // 여는 문자 하나를 추가합니다.
//                    outSubText += open;
//                    index   += 2;
//                }
//                else
//                {
//                    // 종결자를 찾습니다.
//                    const int closeIndex = originalText.Find(close, index + 1);
//                    if (closeIndex != -1)
//                    {
//                        AddSubText(outSubText);
//
//                        const String content = originalText.Substring(index + 1, static_cast<int>(closeIndex) - index - 1);
//                        if (content.IsEmpty() == false)
//                            phrases.push_back(new T(content));
//
//                        outSubText = String::Empty;
//                        index = static_cast<int>(closeIndex + 1);
//                    }
//                    else
//                    {
//                        // 열렸는데 안 닫혀있을 때는 추가합니다.
//                        outSubText += originalText[index++];
//                    }
//                }
//            }
//            else
//            {
//                // 마지막 문자였을 때는 추가합니다.
//                outSubText += originalText[index++];
//            }
//            
//            return index;
//        }
//
//        void MarkupText::Parse()
//        {
//            if (originalText.IsEmpty())
//                return;
//
//            String subText;
//
//            for (int i = 0; i < originalText.GetLength();)
//            {
//                switch (originalText[i])
//                {
//                    case '|':
//                        i = AddSpecialPhrase<ColorPhrase>(i, '|', '|', subText);
//                        break;
//                    case '[':
//                        i = AddSpecialPhrase<ContentPhrase>(i, '[', ']', subText);
//                        break;
//                    case ']':
//                        if (i + 1 < originalText.GetLength())
//                        {
//                            if (originalText[i + 1] == ']')
//                            {
//                                // ']]' 일 때
//                                // ==> ']'를 추가합니다.
//                                subText += originalText[i];
//                                i += 2;
//                            }
//                        }
//                        else
//                        {
//                            // ']'로 끝났을 때
//                            subText += originalText[i++];
//                        }
//                        break;
//                    case '\r': // 개행문자 처리 (Text Phrase 나눔)
//                        AddSubText(subText);
//                        phrases.push_back(new NewLinePhrase());
//
//                        subText = String::Empty;
//                        i++;
//
//                        // '\r' 다음에 '\n'이 이어진다면 '\n'을 무시합니다.
//                        if (i < originalText.GetLength() && originalText[i] == '\n')
//                            i++;
//
//                        break;
//                    case '\n': // 개행문자 처리 (Text Phrase 나눔)
//                        AddSubText(subText);
//                        phrases.push_back(new NewLinePhrase());
//
//                        subText = String::Empty;
//                        i++;
//                        break;
//                    default:
//                        subText += originalText[i++];
//                        break;
//                }
//            }
//
//            AddSubText(subText);
//        }
//
//        void MarkupText::Copy(PhraseCollection& outTarget, const PhraseCollection& original)
//        {
//            HKAssert(outTarget.size() == 0);
//
//            outTarget.reserve(original.size());
//            for (PhraseCollection::const_iterator it = original.begin(); it != original.end(); it++)
//                outTarget.push_back((*it)->Clone());
//        }
//
//        ////////////////////////////////////////////////////////////////////////////////////////////////////
//
//        MarkupText::Phrase::Phrase()
//        {
//        }
//
//        MarkupText::Phrase::Phrase(const String& text)
//            : text(text)
//        {
//        }
//
//        MarkupText::Phrase::Phrase(const Phrase& original)
//            : text(original.text)
//        {
//        }
//
//        MarkupText::Phrase::~Phrase()
//        {
//        }
//
//        const String& MarkupText::Phrase::GetText() const
//        {
//            return text;
//        }
//
//        ////////////////////////////////////////////////////////////////////////////////////////////////////
//
//        MarkupText::TextPhrase::TextPhrase(const String& text)
//            : Phrase(text)
//        {
//        }
//
//        MarkupText::TextPhrase::TextPhrase(const TextPhrase& original)
//            : Phrase(original)
//        {
//        }
//        
//        MarkupText::TextPhrase::~TextPhrase()
//        {
//        }
//
//        MarkupText::TextPhrase* MarkupText::TextPhrase::Clone() const
//        {
//            return new TextPhrase(*this);
//        }
//
//        ////////////////////////////////////////////////////////////////////////////////////////////////////
//
//        MarkupText::NewLinePhrase::NewLinePhrase()
//        {
//        }
//
//        MarkupText::NewLinePhrase::NewLinePhrase(const NewLinePhrase& original)
//            : Phrase(original)
//        {
//        }
//
//        MarkupText::NewLinePhrase::~NewLinePhrase()
//        {
//        }
//
//        MarkupText::NewLinePhrase* MarkupText::NewLinePhrase::Clone() const
//        {
//            return new NewLinePhrase(*this);
//        }
//
//        ////////////////////////////////////////////////////////////////////////////////////////////////////
//
//        MarkupText::ColorPhrase::ColorPhrase(const String& text)
//            : Phrase(text),
//              color(nullptr)
//        {
//            Color convertedColor = Color::Black;
//            if (Color::CanParse(text.Substring(2)))
//                color = new Color(Color::Parse(text.Substring(2)));
//        }
//
//        MarkupText::ColorPhrase::ColorPhrase(const ColorPhrase& original)
//            : Phrase(original.text),
//              color(original.color ? new Color(*original.color) : nullptr)
//        {
//        }
//
//        MarkupText::ColorPhrase::~ColorPhrase()
//        {
//            delete color;
//        }
//
//        MarkupText::ColorPhrase* MarkupText::ColorPhrase::Clone() const
//        {
//            return new ColorPhrase(*this);
//        }
//
//        Color* MarkupText::ColorPhrase::GetColor() const
//        {
//            return color;
//        }
//
//        ////////////////////////////////////////////////////////////////////////////////////////////////////
//
//        MarkupText::ContentPhrase::ContentPhrase(const String& text)
//            : Phrase(text)
//        {
//            int colonIndex    = text.Find(':');
//            int questionIndex = text.Find('?');
//            if (colonIndex != -1)
//            {
//                type = text.Substring(0, colonIndex);
//                type.Trim();
//            }
//
//            if (questionIndex != -1)
//            {
//                name = text.Substring(colonIndex + 1, questionIndex - colonIndex - 1);
//                ParseAttributes(text.Substring(questionIndex + 1));
//            }
//            else
//                name = text.Substring(colonIndex + 1);
//        }
//
//        MarkupText::ContentPhrase::ContentPhrase(const ContentPhrase& original)
//            : Phrase(original),
//              type(original.type),
//              name(original.name),
//              attributes(original.attributes)
//        {
//        }
//
//        MarkupText::ContentPhrase::~ContentPhrase()
//        {
//        }
//
//        MarkupText::ContentPhrase* MarkupText::ContentPhrase::Clone() const
//        {
//            return new ContentPhrase(*this);
//        }
//
//        const String& MarkupText::ContentPhrase::GetType() const
//        {
//            return type;
//        }
//
//        const String& MarkupText::ContentPhrase::GetName() const
//        {
//            return name;
//        }
//
//        const std::map<String, String> MarkupText::ContentPhrase::GetAttributes() const
//        {
//            return attributes;
//        }
//
//        void MarkupText::ContentPhrase::ParseAttributes(const String& text)
//        {
//            for (int i = 0; i < text.GetLength();)
//            {
//                const int equalSignIndex = text.Find('=', i);
//                const int ampersandIndex = text.Find('&', i);
//                if (i == -1)
//                    break;
//                if (i == -1)
//                    i = text.GetLength();
//
//                if (equalSignIndex < ampersandIndex)
//                {
//                    String name = text.Substring(i, equalSignIndex - i);
//                    name.ToLower();
//                    attributes[name] = text.Substring(equalSignIndex + 1, ampersandIndex - equalSignIndex - 1);
//                }
//
//                i = ampersandIndex + 1;
//            }
//        }
//}