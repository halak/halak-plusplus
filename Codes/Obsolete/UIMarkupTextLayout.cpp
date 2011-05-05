#include <Halak/PCH.h>
#include <Halak/UIMarkupTextLayout.h>
#include <Halak/Assert.h>
#include <Halak/DrawingContext.h>
#include <Halak/Font.h>
#include <Halak/FontString.h>
#include <Halak/Math.h>
#include <Halak/NumericLimits.h>
#include <Halak/SpriteRenderer.h>
#include <Halak/UIMarkupText.h>
#include <Halak/Internal/Glyph.h>

namespace Halak
{
    UIMarkupTextLayout::UIMarkupTextLayout()
        : markupText(nullptr),
          align(LeftMiddlePoint),
          boundary(NumericLimits::MaxFloat),
          font(),
          numberOfContents(0),
          displayContentLength(NumericLimits::FloatNaN),
          layoutChanged(true),
          size(Vector2::Zero)
    {
    }

    UIMarkupTextLayout::UIMarkupTextLayout(const String& text)
        : markupText(text.IsEmpty() == false ? new UIMarkupText(text) : nullptr),
          align(LeftMiddlePoint),
          boundary(NumericLimits::MaxFloat),
          font(),
          numberOfContents(0),
          displayContentLength(NumericLimits::FloatNaN),
          layoutChanged(true),
          size(Vector2::Zero)
    {
    }

    UIMarkupTextLayout::UIMarkupTextLayout(const UIMarkupTextLayout& original)
        : markupText(original.markupText ? new UIMarkupText(*original.markupText) : nullptr),
          align(original.align),
          boundary(original.boundary),
          font(original.font),
          numberOfContents(original.numberOfContents),
          displayContentLength(original.displayContentLength),
          layoutChanged(original.layoutChanged),
          size(original.size)
    {
        Copy(lines, original.lines);
    }

    UIMarkupTextLayout::~UIMarkupTextLayout()
    {
        delete markupText;
        DeleteAllLines();
    }

    void UIMarkupTextLayout::Draw(DrawingContext& context)
    {
        if (layoutChanged)
        {
            layoutChanged = false;
            UpdateLayout();
        }

        SpriteRenderer* renderer = context.GetSpriteRenderer();
        float remainingLength = GetDisplayContentLength();
        for (LineCollection::iterator itLine = lines.begin(); itLine != lines.end() && remainingLength > 0.0f; itLine++)
        {
            Line* line = (*itLine);
            for (BlockCollection::iterator it = line->Blocks.begin(); it != line->Blocks.end() && remainingLength > 0.0f; it++)
            {
                (*it)->Draw(renderer, remainingLength);
            }
        }
    }

    const String& UIMarkupTextLayout::GetText() const
    {
        if (markupText)
            return markupText->GetOriginalText();
        else
        {
            static const String EmptyString;
            return EmptyString;
        }
    }

    void UIMarkupTextLayout::SetText(const String& value)
    {
        if (GetText() != value)
        {
            UIMarkupText* deletingText = nullptr;
            std::swap(deletingText, markupText);

            delete deletingText;

            if (value.IsEmpty() == false)
                markupText = new UIMarkupText(value);

            layoutChanged = true;
        }
    }

    const UIMarkupText& UIMarkupTextLayout::GetMarkupText() const
    {
        if (markupText)
            return *markupText;
        else
            return UIMarkupText::Empty;
    }

    Vector2 UIMarkupTextLayout::GetSize()
    {
        if (layoutChanged)
        {
            layoutChanged = true;
            UpdateLayout();
        }

        return size;
    }

    UIMarkupTextLayout::Alignment UIMarkupTextLayout::GetAlign() const
    {
        return align;
    }

    void UIMarkupTextLayout::SetAlign(Alignment value)
    {
        if (GetAlign() != value)
        {
            align = value;
            layoutChanged = true;
        }
    }

    float UIMarkupTextLayout::GetBoundary() const
    {
        return boundary;
    }

    void UIMarkupTextLayout::SetBoundary(float value)
    {
        value = Math::Max(value, 0.0f);

        if (GetBoundary() != value)
        {
            boundary = value;
            layoutChanged = true;
        }
    }

    FontPtr UIMarkupTextLayout::GetFont() const
    {
        return font;
    }

    void UIMarkupTextLayout::SetFont(FontPtr value)
    {
        if (GetFont() != value)
        {
            font = value;
            layoutChanged = true;
        }
    }

    int UIMarkupTextLayout::GetNumberOfContents()
    {
        if (layoutChanged)
        {
            layoutChanged = true;
            UpdateLayout();
        }

        return numberOfContents;
    }

    float UIMarkupTextLayout::GetDisplayContentLength()
    {
        if (displayContentLength != displayContentLength) // is NaN
            return static_cast<float>(GetNumberOfContents());
        else
            return displayContentLength;
    }

    void UIMarkupTextLayout::SetDisplayContentLength(float value)
    {
        displayContentLength = value;
    }

    UIMarkupTextLayout& UIMarkupTextLayout::operator = (const UIMarkupTextLayout& original)
    {
        if (markupText)
        {
            UIMarkupText* deletingText = nullptr;
            std::swap(deletingText, markupText);
            delete deletingText;
        }

        DeleteAllLines();

        if (original.markupText)
            markupText = new UIMarkupText(*original.markupText);
        else
            markupText = nullptr;
        align = original.align;
        boundary = original.boundary;
        font = original.font;
        numberOfContents = original.numberOfContents;
        displayContentLength = original.displayContentLength;
        layoutChanged = original.layoutChanged;

        Copy(lines, original.lines);
        size = original.size;
        return *this;
    }

    bool UIMarkupTextLayout::operator == (const UIMarkupTextLayout& right) const
    {
        if ((markupText != nullptr && right.markupText == nullptr) ||
            (markupText == nullptr && right.markupText != nullptr) ||
            (markupText && right.markupText && (*markupText) != (*right.markupText)))
            return false;

        return align == right.align &&
               boundary  == right.boundary &&
               font      == right.font &&
               displayContentLength == right.displayContentLength;
    }

    bool UIMarkupTextLayout::operator != (const UIMarkupTextLayout& right) const
    {
        return !operator == (right);
    }

    void UIMarkupTextLayout::UpdateLayout()
    {
        DeleteAllLines();

        if (markupText == nullptr || font == nullptr)
            return;

        numberOfContents = 0;

        LayoutContext context(this);
        const UIMarkupText::PhraseCollection& phrases = GetMarkupText().GetPhrases();
        for (UIMarkupText::PhraseCollection::const_iterator it = phrases.begin(); it != phrases.end(); it++)
        {
            switch ((*it)->GetType())
            {
                case UIMarkupText::TextPhraseType:
                    {
                        const UIMarkupText::TextPhrase* item = static_cast<const UIMarkupText::TextPhrase*>(*it);
                        const String& originalText = GetMarkupText().GetOriginalText();
                        TextBlock* textBlock = new TextBlock(originalText.Substring(item->GetIndex(), item->GetLength()), context.GetFont());
                        numberOfContents += textBlock->GetNumberOfGlyphs();
                        context.Push(textBlock);
                    }
                    break;
                case UIMarkupText::NewLinePhraseType:
                    context.Wrap();
                    break;
                case UIMarkupText::ColorPhraseType:
                    {
                        const UIMarkupText::ColorPhrase* item = static_cast<const UIMarkupText::ColorPhrase*>(*it);

                        Color color = Color(255, 255, 255, 255);
                        if (item->HasColor())
                            color = item->GetColor();
                        else
                            color = context.GetFont()->GetColor();

                        if (context.GetFont()->GetColor() != color)
                        {
                            FontPtr newFont = FontPtr(new Font(*context.GetFont()));
                            newFont->SetColor(color);
                            context.SetFont(newFont);
                        }
                    }
                    break;
                case UIMarkupText::ContentPhraseType:
                    {
                        const UIMarkupText::ContentPhrase* item = static_cast<const UIMarkupText::ContentPhrase*>(*it);
                    }
                    break;
            }
        }

        size = Vector2::Zero;
        for (LineCollection::const_iterator it = lines.begin(); it != lines.end(); it++)
        {
            size.X = Math::Max(size.X, (*it)->Size.X);
            size.Y += (*it)->Size.Y;
        }
    }

    void UIMarkupTextLayout::DeleteAllLines()
    {
        LineCollection deletingLines;
        deletingLines.swap(lines);

        for (LineCollection::iterator it = deletingLines.begin(); it != deletingLines.end(); it++)
            delete (*it);
    }

    void UIMarkupTextLayout::Copy(LineCollection& target, const LineCollection& original)
    {
        HKAssert(target.empty());

        target.reserve(original.size());
        for (LineCollection::const_iterator it = original.begin(); it != original.end(); it++)
            target.push_back(new Line(*(*it)));
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    UIMarkupTextLayout::Block::~Block()
    {
    }

    UIMarkupTextLayout::Block* UIMarkupTextLayout::Block::Divide(float /*cutWidth*/)
    {
        return nullptr;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    UIMarkupTextLayout::TextBlock::TextBlock(const String& text, FontPtr font)
        : text(text),
          font(font),
          fontString(new FontString(font, text))
    {
        Size = font->Measure(*fontString);
    }

    UIMarkupTextLayout::TextBlock::~TextBlock()
    {
        delete fontString;
    }
    
    UIMarkupTextLayout::TextBlock* UIMarkupTextLayout::TextBlock::Clone() const
    {
        return new TextBlock(*this);
    }

    void UIMarkupTextLayout::TextBlock::Draw(SpriteRenderer* renderer, float& outLength)
    {
        renderer->DrawString(Position, *fontString, outLength, NumericLimits::MaxFloat);
        outLength -= static_cast<float>(GetNumberOfGlyphs());
    }

    UIMarkupTextLayout::TextBlock* UIMarkupTextLayout::TextBlock::Divide(float cutWidth)
    {
        float width = 0.0f;
        const FontString::GlyphCollection& glyphs = fontString->GetRegularGlyphs();
        for (FontString::GlyphCollection::size_type i = 0; i < glyphs.size(); i++)
        {
            width += font->GetSpacing() * glyphs[i]->GetAdvance().X;
            if (width >= cutWidth)
            {
                // 나눌필요가 없으면 그냥 바로 nullptr을 반환합니다.
                if (i == 0)
                    return nullptr;

                const int index = fontString->ConvertToOriginalIndex(i);

                // 넘어간 순간 그 문자부터 나눕니다.
                TextBlock* textBlock = new TextBlock(fontString->GetOriginal().Substring(index), font);

                // 기존 Block을 축소시킵니다.
                text = text.Substring(0, index);
                delete fontString;
                fontString = new FontString(font, text);
                Size = font->Measure(*fontString);

                return textBlock;
            }
        }

        return nullptr;
    }

    int UIMarkupTextLayout::TextBlock::GetNumberOfGlyphs() const
    {
        return static_cast<int>(fontString->GetRegularGlyphs().size());
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    UIMarkupTextLayout::Line::Line()
        : Size(Vector2::Zero)
    {
    }

    UIMarkupTextLayout::Line::Line(const Line& original)
        : Size(original.Size)
    {
        Blocks.reserve(original.Blocks.size());
        for (BlockCollection::const_iterator it = original.Blocks.begin(); it != original.Blocks.end(); it++)
            Blocks.push_back((*it)->Clone());
    }

    UIMarkupTextLayout::Line::~Line()
    {
        BlockCollection deletingBlocks;
        deletingBlocks.swap(Blocks);

        for (BlockCollection::iterator it = deletingBlocks.begin(); it != deletingBlocks.end(); it++)
            delete (*it);
    }

    void UIMarkupTextLayout::Line::UpdateSize(float defaultHeight)
    {
        Vector2 size = Vector2(0.0f, defaultHeight);
        for (BlockCollection::const_iterator it = Blocks.begin(); it != Blocks.end(); it++)
        {
            const Block* item = (*it);
            size.X += item->Offset.X + item->Size.X;
            size.Y = Math::Max(size.Y, item->Offset.Y + item->Size.Y);
        }

        Size = size;
    }

    void UIMarkupTextLayout::Line::AdjustBlocks(float y, float boundary, Alignment align)
    {
        // ASSERT : this->Size는 정상.
        // ASSERT : 각 Block들의 Size는 정상.

        // 가로축을 정렬합니다.
        float xAxis = 0.0f;
        switch (align)
        {
            case LeftTopPoint:
            case LeftBottomPoint:
            case LeftMiddlePoint:
                xAxis = 0.0f;
                break;
            case CenterTopPoint:
            case CenterBottomPoint:
            case CenterPoint:
                xAxis = (boundary - Size.X) * 0.5f;
                break;
            case RightTopPoint:
            case RightBottomPoint:
            case RightMiddlePoint:
                xAxis = boundary - Size.X;
                break;
        }

        // 세로축을 정렬합니다.
        switch (align)
        {
            case LeftTopPoint:
            case RightTopPoint:
            case CenterTopPoint:
                {
                    const float yAxis = y;
                    for (BlockCollection::iterator it = Blocks.begin(); it != Blocks.end(); it++)
                        (*it)->Position.Y = yAxis;
                }
                break;
            case LeftMiddlePoint:
            case RightMiddlePoint:
            case CenterPoint:
                {
                    const float yAxis = y + (Size.Y * 0.5f);
                    for (BlockCollection::iterator it = Blocks.begin(); it != Blocks.end(); it++)
                        (*it)->Position.Y = yAxis - ((*it)->Size.Y * 0.5f);
                }
                break;
            case LeftBottomPoint:
            case RightBottomPoint:
            case CenterBottomPoint:
                {
                    const float yAxis = y + Size.Y;
                    for (BlockCollection::iterator it = Blocks.begin(); it != Blocks.end(); it++)
                        (*it)->Position.Y = yAxis - (*it)->Size.Y;
                }
                break;
        }

        for (BlockCollection::iterator it = Blocks.begin(); it != Blocks.end(); it++)
        {
            (*it)->Position.X = xAxis;
            xAxis += (*it)->Size.X;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    UIMarkupTextLayout::LayoutContext::LayoutContext(UIMarkupTextLayout* layout)
        : layout(layout),
          line(nullptr),
          position(Vector2::Zero),
          font(layout->GetFont())
    {
        Wrap();
    }

    UIMarkupTextLayout::LayoutContext::~LayoutContext()
    {
        line->UpdateSize(font->GetLineHeight());
        line->AdjustBlocks(position.Y, layout->GetBoundary(), layout->GetAlign());
    }

    void UIMarkupTextLayout::LayoutContext::Push(Block* item)
    {
        // ASSERT : item->Offset, item->Size는 정상.

        Block* nextLineItem = nullptr;
        if (position.X + item->Offset.X + item->Size.X > layout->GetBoundary())
        {
            nextLineItem = item->Divide(layout->GetBoundary() - position.X);
            if (nextLineItem == nullptr)
                Wrap();
        }

        line->Blocks.push_back(item);
        position.X += item->Offset.X + item->Size.X;

        if (nextLineItem)
        {
            Wrap();
            Push(nextLineItem);
        }
    }

    void UIMarkupTextLayout::LayoutContext::Wrap()
    {
        if (line)
        {
            line->UpdateSize(font->GetLineHeight());
            line->AdjustBlocks(position.Y, layout->GetBoundary(), layout->GetAlign());
            position.X = 0.0f;
            position.Y += line->Size.Y;
        }

        line = new Line();
        layout->lines.push_back(line);
    }

    FontPtr UIMarkupTextLayout::LayoutContext::GetFont() const
    {
        return font;
    }

    void UIMarkupTextLayout::LayoutContext::SetFont(FontPtr value)
    {
        font = value;
    }
}