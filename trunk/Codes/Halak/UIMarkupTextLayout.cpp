//#include <Halak/PCH.h>
//#include <Halak/UIMarkupTextLayout.h>
//#include <TH/UI/MarkupText.h>
//#include <Halak/Assert.h>
//#include <Halak/DrawingContext.h>
//#include <Halak/Font.h>
//#include <Halak/FontString.h>
//#include <Halak/NumericLimits.h>
//#include <Halak/SpriteRenderer.h>
//#include <Halak/Texture2D.h>
//#include <Halak/Internal/Glyph.h>
//
//namespace Halak
//{
//        MarkupTextLayout::MarkupTextLayout()
//            : markupText(nullptr),
//              alignment(Alignment::MiddleLeft),
//              boundary(NumericLimits::MaxFloat),
//              font(),
//              numberOfContents(0),
//              displayContentLength(NumericLimits::FloatNaN),
//              layoutChanged(true),
//              size(Vector2::Zero)
//        {
//        }
//
//        MarkupTextLayout::MarkupTextLayout(const String& text)
//            : markupText(text.IsEmpty() == false ? new MarkupText(text) : nullptr),
//              alignment(Alignment::MiddleLeft),
//              boundary(NumericLimits::MaxFloat),
//              font(),
//              numberOfContents(0),
//              displayContentLength(NumericLimits::FloatNaN),
//              layoutChanged(true),
//              size(Vector2::Zero)
//        {
//        }
//
//        MarkupTextLayout::MarkupTextLayout(const MarkupTextLayout& original)
//            : markupText(original.markupText ? new MarkupText(*original.markupText) : nullptr),
//              alignment(original.alignment),
//              boundary(original.boundary),
//              font(original.font),
//              numberOfContents(original.numberOfContents),
//              displayContentLength(original.displayContentLength),
//              layoutChanged(original.layoutChanged),
//              size(original.size)
//        {
//            Copy(lines, original.lines);
//        }
//
//        MarkupTextLayout::~MarkupTextLayout()
//        {
//            delete markupText;
//            DeleteAllLines();
//        }
//
//        void MarkupTextLayout::Draw(DrawingContext& context)
//        {
//            if (layoutChanged)
//            {
//                layoutChanged = false;
//                UpdateLayout();
//            }
//
//            SpriteRenderer* renderer = context.GetSpriteRenderer();
//            float remainingLength = GetDisplayContentLength();
//            for (LineCollection::iterator itLine = lines.begin(); itLine != lines.end() && remainingLength > 0.0f; itLine++)
//            {
//                Line* line = (*itLine);
//                for (BlockCollection::iterator it = line->Blocks.begin(); it != line->Blocks.end() && remainingLength > 0.0f; it++)
//                {
//                    (*it)->Draw(renderer, remainingLength);
//                }
//            }
//        }
//
//        const String& MarkupTextLayout::GetText() const
//        {
//            if (markupText)
//                return markupText->GetOriginalText();
//            else
//            {
//                static const String EmptyString;
//                return EmptyString;
//            }
//        }
//
//        void MarkupTextLayout::SetText(const String& value)
//        {
//            if (GetText() != value)
//            {
//                MarkupText* deletingText = nullptr;
//                std::swap(deletingText, markupText);
//
//                delete deletingText;
//
//                if (value.IsEmpty() == false)
//                    markupText = new MarkupText(value);
//
//                layoutChanged = true;
//            }
//        }
//
//        const MarkupText& MarkupTextLayout::GetMarkupText() const
//        {
//            if (markupText)
//                return *markupText;
//            else
//                return MarkupText::Empty;
//        }
//
//        Vector2 MarkupTextLayout::GetSize()
//        {
//            if (layoutChanged)
//            {
//                layoutChanged = true;
//                UpdateLayout();
//            }
//
//            return size;
//        }
//
//        Alignment::E MarkupTextLayout::GetAlign() const
//        {
//            return alignment;
//        }
//
//        void MarkupTextLayout::SetAlign(Alignment::E value)
//        {
//            if (GetAlign() != value)
//            {
//                alignment = value;
//                layoutChanged = true;
//            }
//        }
//
//        float MarkupTextLayout::GetBoundary() const
//        {
//            return boundary;
//        }
//
//        void MarkupTextLayout::SetBoundary(float value)
//        {
//            value = std::max(value, 0.0f);
//
//            if (GetBoundary() != value)
//            {
//                boundary = value;
//                layoutChanged = true;
//            }
//        }
//
//        FontPtr MarkupTextLayout::GetFont() const
//        {
//            return font;
//        }
//
//        void MarkupTextLayout::SetFont(FontPtr value)
//        {
//            if (GetFont() != value)
//            {
//                font = value;
//                layoutChanged = true;
//            }
//        }
//
//        int MarkupTextLayout::GetNumberOfContents()
//        {
//            if (layoutChanged)
//            {
//                layoutChanged = true;
//                UpdateLayout();
//            }
//
//            return numberOfContents;
//        }
//
//        float MarkupTextLayout::GetDisplayContentLength()
//        {
//            if (displayContentLength != displayContentLength) // is NaN
//                return static_cast<float>(GetNumberOfContents());
//            else
//                return displayContentLength;
//        }
//
//        void MarkupTextLayout::SetDisplayContentLength(float value)
//        {
//            displayContentLength = value;
//        }
//
//        MarkupTextLayout& MarkupTextLayout::operator = (const MarkupTextLayout& original)
//        {
//            if (markupText)
//            {
//                MarkupText* deletingText = nullptr;
//                std::swap(deletingText, markupText);
//                delete deletingText;
//            }
//
//            DeleteAllLines();
//
//            if (original.markupText)
//                markupText = new MarkupText(*original.markupText);
//            else
//                markupText = nullptr;
//            alignment = original.alignment;
//            boundary = original.boundary;
//            font = original.font;
//            numberOfContents = original.numberOfContents;
//            displayContentLength = original.displayContentLength;
//            layoutChanged = original.layoutChanged;
//
//            Copy(lines, original.lines);
//            size = original.size;
//            return *this;
//        }
//
//        bool MarkupTextLayout::operator == (const MarkupTextLayout& right) const
//        {
//            if ((markupText != nullptr && right.markupText == nullptr) ||
//                (markupText == nullptr && right.markupText != nullptr) ||
//                (markupText && right.markupText && (*markupText) != (*right.markupText)))
//                return false;
//
//            return alignment == right.alignment &&
//                   boundary  == right.boundary &&
//                   font      == right.font &&
//                   displayContentLength == right.displayContentLength;
//        }
//
//        bool MarkupTextLayout::operator != (const MarkupTextLayout& right) const
//        {
//            return !operator == (right);
//        }
//
//        void MarkupTextLayout::UpdateLayout()
//        {
//            DeleteAllLines();
//
//            if (markupText == nullptr || font == nullptr)
//                return;
//
//            numberOfContents = 0;
//
//            LayoutContext context(this);
//            const MarkupText::PhraseCollection& phrases = GetMarkupText().GetPhrases();
//            for (MarkupText::PhraseCollection::const_iterator it = phrases.begin(); it != phrases.end(); it++)
//            {
//                if (const MarkupText::TextPhrase* item = dynamic_cast<const MarkupText::TextPhrase*>(*it))
//                {
//                    TextBlock* textBlock = new TextBlock(item->GetText(), context.GetFont());
//                    numberOfContents += textBlock->GetNumberOfGlyphs();
//                    context.Push(textBlock);
//                    continue;
//                }
//                if (const MarkupText::NewLinePhrase* item = dynamic_cast<const MarkupText::NewLinePhrase*>(*it))
//                {
//                    context.Wrap();
//                    continue;
//                }
//                if (const MarkupText::ColorPhrase* item = dynamic_cast<const MarkupText::ColorPhrase*>(*it))
//                {
//                    Color color = Color::White;
//                    if (item->GetColor())
//                        color = *item->GetColor();
//                    else
//                        color = context.GetFont()->GetColor();
//
//                    if (context.GetFont()->GetColor() != color)
//                    {
//                        FontPtr newFont = FontPtr(new Font(*context.GetFont()));
//                        newFont->SetColor(color);
//                        context.SetFont(newFont);
//                    }
//                    
//                    continue;
//                }
//                if (const MarkupText::ContentPhrase* item = dynamic_cast<const MarkupText::ContentPhrase*>(*it))
//                {
//                    continue;
//                }
//            }
//
//            size = Vector2::Zero;
//            for (LineCollection::const_iterator it = lines.begin(); it != lines.end(); it++)
//            {
//                size.X = std::max<float>(size.X, (*it)->Size.X);
//                size.Y += (*it)->Size.Y;
//            }
//        }
//
//        void MarkupTextLayout::DeleteAllLines()
//        {
//            LineCollection deletingLines;
//            deletingLines.swap(lines);
//
//            for (LineCollection::iterator it = deletingLines.begin(); it != deletingLines.end(); it++)
//                delete (*it);
//        }
//
//        void MarkupTextLayout::Copy(LineCollection& target, const LineCollection& original)
//        {
//            HKAssert(target.empty());
//
//            target.reserve(original.size());
//            for (LineCollection::const_iterator it = original.begin(); it != original.end(); it++)
//                target.push_back(new Line(*(*it)));
//        }
//
//        ////////////////////////////////////////////////////////////////////////////////////////////////////
//       
//        MarkupTextLayout::Block::~Block()
//        {
//        }
//
//        MarkupTextLayout::Block* MarkupTextLayout::Block::Divide(float /*cutWidth*/)
//        {
//            return nullptr;
//        }
//
//        ////////////////////////////////////////////////////////////////////////////////////////////////////
//
//        MarkupTextLayout::TextBlock::TextBlock(const String& text, FontPtr font)
//            : text(text),
//              font(font),
//              fontString(new FontString(font, text))
//        {
//            Size = font->Measure(*fontString);
//        }
//
//        MarkupTextLayout::TextBlock::~TextBlock()
//        {
//            delete fontString;
//        }
//        
//        MarkupTextLayout::TextBlock* MarkupTextLayout::TextBlock::Clone() const
//        {
//            return new TextBlock(*this);
//        }
//
//        void MarkupTextLayout::TextBlock::Draw(SpriteRenderer* renderer, float& outLength)
//        {
//            renderer->DrawString(Position, *fontString, outLength, NumericLimits::MaxFloat);
//            outLength -= static_cast<float>(GetNumberOfGlyphs());
//        }
//
//        MarkupTextLayout::TextBlock* MarkupTextLayout::TextBlock::Divide(float cutWidth)
//        {
//            float width = 0.0f;
//            const FontString::GlyphCollection& glyphs = fontString->GetRegularGlyphs();
//            for (FontString::GlyphCollection::size_type i = 0; i < glyphs.size(); i++)
//            {
//                width += font->GetSpacing() * glyphs[i]->GetAdvance().X;
//                if (width >= cutWidth)
//                {
//                    // 나눌필요가 없으면 그냥 바로 nullptr을 반환합니다.
//                    if (i == 0)
//                        return nullptr;
//
//                    const int index = fontString->ConvertToOriginalIndex(i);
//
//                    // 넘어간 순간 그 문자부터 나눕니다.
//                    TextBlock* textBlock = new TextBlock(fontString->GetOriginal().Substring(index), font);
//
//                    // 기존 Block을 축소시킵니다.
//                    text = text.Substring(0, index);
//                    delete fontString;
//                    fontString = new FontString(font, text);
//                    Size = font->Measure(*fontString);
//
//                    return textBlock;
//                }
//            }
//
//            return nullptr;
//        }
//
//        int MarkupTextLayout::TextBlock::GetNumberOfGlyphs() const
//        {
//            return static_cast<int>(fontString->GetRegularGlyphs().size());
//        }
//
//        ////////////////////////////////////////////////////////////////////////////////////////////////////
//
//        MarkupTextLayout::Line::Line()
//            : Size(Vector2::Zero)
//        {
//        }
//
//        MarkupTextLayout::Line::Line(const Line& original)
//            : Size(original.Size)
//        {
//            Blocks.reserve(original.Blocks.size());
//            for (BlockCollection::const_iterator it = original.Blocks.begin(); it != original.Blocks.end(); it++)
//                Blocks.push_back((*it)->Clone());
//        }
//
//        MarkupTextLayout::Line::~Line()
//        {
//            BlockCollection deletingBlocks;
//            deletingBlocks.swap(Blocks);
//
//            for (BlockCollection::iterator it = deletingBlocks.begin(); it != deletingBlocks.end(); it++)
//                delete (*it);
//        }
//
//        void MarkupTextLayout::Line::UpdateSize(float defaultHeight)
//        {
//            Vector2 size = Vector2(0.0f, defaultHeight);
//            for (BlockCollection::const_iterator it = Blocks.begin(); it != Blocks.end(); it++)
//            {
//                const Block* item = (*it);
//                size.X += item->Offset.X + item->Size.X;
//                size.Y = std::max(size.Y, item->Offset.Y + item->Size.Y);
//            }
//
//            Size = size;
//        }
//
//        void MarkupTextLayout::Line::AdjustBlocks(float y, float boundary, Alignment::E alignment)
//        {
//            // ASSERT : this->Size는 정상.
//            // ASSERT : 각 Block들의 Size는 정상.
//
//            // 세로축을 정렬합니다.
//            switch (alignment)
//            {
//                case Alignment::TopLeft:
//                case Alignment::TopCenter:
//                case Alignment::TopRight:
//                    {
//                        const float yAxis = y;
//                        for (BlockCollection::iterator it = Blocks.begin(); it != Blocks.end(); it++)
//                            (*it)->Position.Y = yAxis;
//                    }
//                    break;
//                case Alignment::MiddleLeft:
//                case Alignment::MiddleCenter:
//                case Alignment::MiddleRight:
//                    {
//                        const float yAxis = y + (Size.Y * 0.5f);
//                        for (BlockCollection::iterator it = Blocks.begin(); it != Blocks.end(); it++)
//                            (*it)->Position.Y = yAxis - ((*it)->Size.Y * 0.5f);
//                    }
//                    break;
//                case Alignment::BottomLeft:
//                case Alignment::BottomCenter:
//                case Alignment::BottomRight:
//                    {
//                        const float yAxis = y + Size.Y;
//                        for (BlockCollection::iterator it = Blocks.begin(); it != Blocks.end(); it++)
//                            (*it)->Position.Y = yAxis - (*it)->Size.Y;
//                    }
//                    break;
//            }
//
//            // 가로축을 정렬합니다.
//            float xAxis = 0.0f;
//            switch (alignment)
//            {
//                case Alignment::TopLeft:
//                case Alignment::MiddleLeft:
//                case Alignment::BottomLeft:
//                    xAxis = 0.0f;
//                    break;
//                case Alignment::TopCenter:
//                case Alignment::MiddleCenter:
//                case Alignment::BottomCenter:
//                    xAxis = (boundary - Size.X) * 0.5f;
//                    break;
//                case Alignment::TopRight:
//                case Alignment::MiddleRight:
//                case Alignment::BottomRight:
//                    xAxis = boundary - Size.X;
//                    break;
//            }
//            for (BlockCollection::iterator it = Blocks.begin(); it != Blocks.end(); it++)
//            {
//                (*it)->Position.X = xAxis;
//                xAxis += (*it)->Size.X;
//            }
//        }
//
//        ////////////////////////////////////////////////////////////////////////////////////////////////////
//
//        MarkupTextLayout::LayoutContext::LayoutContext(MarkupTextLayout* layout)
//            : layout(layout),
//              line(nullptr),
//              position(Vector2::Zero),
//              font(layout->GetFont())
//        {
//            Wrap();
//        }
//
//        MarkupTextLayout::LayoutContext::~LayoutContext()
//        {
//            line->UpdateSize(font->GetLineHeight());
//            line->AdjustBlocks(position.Y, layout->GetBoundary(), layout->GetAlign());
//        }
//
//        void MarkupTextLayout::LayoutContext::Push(Block* item)
//        {
//            // ASSERT : item->Offset, item->Size는 정상.
//
//            Block* nextLineItem = nullptr;
//            if (position.X + item->Offset.X + item->Size.X > layout->GetBoundary())
//            {
//                nextLineItem = item->Divide(layout->GetBoundary() - position.X);
//                if (nextLineItem == nullptr)
//                    Wrap();
//            }
//
//            line->Blocks.push_back(item);
//            position.X += item->Offset.X + item->Size.X;
//
//            if (nextLineItem)
//            {
//                Wrap();
//                Push(nextLineItem);
//            }
//        }
//
//        void MarkupTextLayout::LayoutContext::Wrap()
//        {
//            if (line)
//            {
//                line->UpdateSize(font->GetLineHeight());
//                line->AdjustBlocks(position.Y, layout->GetBoundary(), layout->GetAlign());
//                position.X = 0.0f;
//                position.Y += line->Size.Y;
//            }
//
//            line = new Line();
//            layout->lines.push_back(line);
//        }
//
//        FontPtr MarkupTextLayout::LayoutContext::GetFont() const
//        {
//            return font;
//        }
//
//        void MarkupTextLayout::LayoutContext::SetFont(FontPtr value)
//        {
//            font = value;
//        }
//}