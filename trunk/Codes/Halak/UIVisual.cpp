#include <Halak/PCH.h>
#include <Halak/UIVisual.h>
#include <Halak/Math.h>
#include <Halak/UIFrame.h>
#include <Halak/UIPickingContext.h>
#include <Halak/UIWindow.h>

namespace Halak
{
    UIVisual::UIVisual()
        : opacity(1.0f),
          shown(true),
          frame(nullptr),
          parent(nullptr)
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

    void UIVisual::SetFrame(UIFrame* value)
    {
        if (frame != value)
        {
            UIFramePtr old = frame;

            frame = value;

            OnFrameChanged(old);
        }
    }

    void UIVisual::SetParent(UIWindow* value)
    {
        if (parent != value)
        {
            UIWindowWeakPtr old = parent;

            parent = value;

            OnParentChanged(old);
        }
    }

    bool UIVisual::IsWindow() const
    {
        return false;
    }

    void UIVisual::OnDraw(UIDrawingContext& /*context*/)
    {
    }

    void UIVisual::OnPick(UIPickingContext& context)
    {
        if (context.GetCurrentClippedBounds().Contains(context.GetPoint()))
            context.SetResult(this);
    }

    void UIVisual::OnOpacityChanged(float /*old*/)
    {
    }

    void UIVisual::OnShownChanged()
    {
    }

    void UIVisual::OnFrameChanged(UIFrame* /*old*/)
    {
    }

    void UIVisual::OnParentChanged(UIWindow* /*old*/)
    {
    }
}