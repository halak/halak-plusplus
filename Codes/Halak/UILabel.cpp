#include <Halak/PCH.h>
#include <Halak/UILabel.h>
#include <Halak/Font.h>
#include <Halak/UIDrawingContext.h>

namespace Halak
{
    UILabel::UILabel()
        : text(String::Empty),
          font(nullptr),
          fontString(FontString::Empty),
          autoResize(true)
    {
    }

    UILabel::~UILabel()
    {
    }

    void UILabel::SetText(const String& value)
    {
        if (text != value)
        {
            text = value;
            fontStringChanged = true;
        }
    }

    void UILabel::SetFont(Font* value)
    {
        if (font != value)
        {
            font = value;
            fontStringChanged = true;
        }
    }

    void UILabel::SetAutoResize(bool value)
    {
        if (autoResize != value)
        {
            autoResize = value;
        }
    }

    void UILabel::OnDraw(UIDrawingContext& context)
    {
        UIVisual::OnDraw(context);

        context.DrawRectangle(context.GetCurrentBounds(), Color::White);
        context.DrawRectangle(context.GetCurrentClippedBounds(), Color::Yellow);

        if (GetFont() == nullptr || GetText().IsEmpty())
            return;

        if (fontStringChanged)
        {
            fontStringChanged = false;
            fontString = FontString(GetFont(), GetText());
        }

        context.DrawString(fontString);
    }
}