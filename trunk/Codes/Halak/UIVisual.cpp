#include <Halak/PCH.h>
#include <Halak/UIVisual.h>
#include <Halak/Math.h>
#include <Halak/UIFrame.h>

namespace Halak
{
    UIVisual::UIVisual()
    {
    }

    UIVisual::~UIVisual()
    {
    }

    void UIVisual::SetOpacity(float value)
    {
        value = Math::Clamp(value, 0.0f, 1.0f);

        if (opacity != value)
        {
            const float old = opacity;

            opacity = value;

            OnOpacityChanged(old);
        }
    }

    void UIVisual::SetShown(bool value)
    {
        if (shown != value)
        {
            shown = value;

            OnShownChanged();
        }
    }

    void UIVisual::SetFrame(const UIFramePtr& value)
    {
        if (frame != value)
        {
            UIFramePtr old = frame;

            frame = value;

            OnFrameChanged(old);
        }
    }

    bool UIVisual::IsWindow() const
    {
        return false;
    }

    void UIVisual::OnDraw(UIDrawingContext& /*context*/)
    {
    }

    void UIVisual::OnOpacityChanged(float /*old*/)
    {
    }

    void UIVisual::OnShownChanged()
    {
    }

    void UIVisual::OnFrameChanged(const UIFramePtr& /*old*/)
    {
    }

    void UIVisual::OnParentChanged(const UIWindowWeakPtr& /*old*/)
    {
    }
}