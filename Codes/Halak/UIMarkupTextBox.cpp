#include <Halak/PCH.h>
#include <Halak/UIMarkupTextBox.h>
#include <Halak/UILabel.h>
#include <Halak/UISprite.h>

namespace Halak
{
    UIMarkupTextBox::UIMarkupTextBox()
        : text(UIMarkupText::Empty)
    {
    }

    UIMarkupTextBox::~UIMarkupTextBox()
    {
    }

    void UIMarkupTextBox::SetText(const UIMarkupText& value)
    {
        if (text != value)
        {
            text = value;
            UpdateLayout();
        }
    }

    void UIMarkupTextBox::UpdateLayout()
    {
        RemoveAllChildren();

        typedef UIMarkupText::Phrase Phrase;
        typedef UIMarkupText::TextPhrase TextPhrase;
        typedef UIMarkupText::NewLinePhrase NewLinePhrase;
        typedef UIMarkupText::ColorPhrase ColorPhrase;
        typedef UIMarkupText::FontPhrase FontPhrase;
        typedef UIMarkupText::ContentPhrase ContentPhrase;
        typedef UIMarkupText::PhraseCollection PhraseCollection;
        const PhraseCollection& phrases = text.GetPhrases();
        for (PhraseCollection::const_iterator it = phrases.begin(); it != phrases.end(); it++)
        {
            switch ((*it)->GetType())
            {
                case UIMarkupText::TextPhraseType:
                    {
                        const TextPhrase* item = static_cast<const TextPhrase*>(*it);
                    }
                    break;
                case UIMarkupText::NewLinePhraseType:
                    {
                    }
                    break;
                case UIMarkupText::ColorPhraseType:
                    {
                        const ColorPhrase* item = static_cast<const ColorPhrase*>(*it);
                    }
                    break;
                case UIMarkupText::FontPhraseType:
                    {
                        const FontPhrase* item = static_cast<const FontPhrase*>(*it);
                    }
                    break;
                case UIMarkupText::ContentPhraseType:
                    {
                        const ContentPhrase* item = static_cast<const ContentPhrase*>(*it);
                    }
                    break;
            }
        }
    }
}