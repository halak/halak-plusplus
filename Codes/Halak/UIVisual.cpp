#include <Halak/PCH.h>
#include <Halak/UIVisual.h>
#include <Halak/Math.h>
#include <Halak/UIEventMap.h>
#include <Halak/UIFrame.h>
#include <Halak/UIGamePadEventArgs.h>
#include <Halak/UIKeyboardEventArgs.h>
#include <Halak/UIMouseButtonEventArgs.h>
#include <Halak/UIMouseEventArgs.h>
#include <Halak/UIMouseWheelEventArgs.h>
#include <Halak/UIPickingContext.h>
#include <Halak/UIPanel.h>
#include <Halak/UITransform.h>

namespace Halak
{
    const Property<float> UIVisual::OpacityProperty(HKMakeFOURCC('O', 'P', 'A', 'C'), &UIVisual::GetOpacity, &UIVisual::SetOpacity);
    const Property<bool>  UIVisual::ShownProperty(HKMakeFOURCC('S', 'H', 'O', 'W'), &UIVisual::GetShown, &UIVisual::SetShown);

    UIVisual::UIVisual()
        : opacity(1.0f),
          shown(true),
          frame(nullptr),
          transform(nullptr),
          eventMap(nullptr),
          parent(nullptr)
    {
    }

    UIVisual::~UIVisual()
    {
    }

    void UIVisual::BringToFront()
    {
        if (parent)
            parent->BringChildToFront(this);
    }

    void UIVisual::SendToBack()
    {
        if (parent)
            parent->SendChildToBack(this);
    }

    RectangleF UIVisual::ComputeBounds(UIVisualVisitor& visitor)
    {
        return GetFrame()->ComputeBounds(visitor, GetDesiredSize());
    }

    void UIVisual::SetOpacity(float value)
    {
        opacity = Math::Clamp(value, 0.0f, 1.0f);
    }

    void UIVisual::SetFrame(UIFrame* value)
    {
        frame = value;
    }

    void UIVisual::SetTransform(UITransform* value)
    {
        transform = value;
    }

    void UIVisual::SetEventMap(UIEventMap* value)
    {
        eventMap = value;
    }

    void UIVisual::SetParent(UIPanel* value)
    {
        if (parent != value)
        {
            UIPanelWeakPtr old = parent;

            parent = value;

            OnParentChanged(old);
        }
    }

    bool UIVisual::IsPanel() const
    {
        return false;
    }

    void UIVisual::OnDraw(UIDrawingContext& /*context*/)
    {
    }

    void UIVisual::OnPick(UIPickingContext& context)
    {
        if (context.Contains(context.GetCurrentClippedBounds()))
            context.SetResult(this);
    }

    void UIVisual::OnParentChanged(UIPanel* /*old*/)
    {
    }

    bool UIVisual::OnKeyDown(const UIKeyboardEventArgs& /*args*/)
    {
        return false;
    }

    bool UIVisual::OnKeyUp(const UIKeyboardEventArgs& /*args*/)
    {
        return false;
    }

    bool UIVisual::OnKeyPressing(const UIKeyboardEventArgs& /*args*/)
    {
        return false;
    }

    void UIVisual::OnMouseEnter(const UIMouseEventArgs& /*args*/)
    {
    }

    void UIVisual::OnMouseLeave(const UIMouseEventArgs& /*args*/)
    {
    }

    bool UIVisual::OnMouseMove(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIVisual::OnMouseClick(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIVisual::OnMouseButtonDown(const UIMouseButtonEventArgs& /*args*/)
    {
        return false;
    }

    bool UIVisual::OnMouseButtonUp(const UIMouseButtonEventArgs& /*args*/)
    {
        return false;
    }

    bool UIVisual::OnMouseButtonPressing(const UIMouseButtonEventArgs& /*args*/)
    {
        return false;
    }

    bool UIVisual::OnMouseWheel(const UIMouseWheelEventArgs& /*args*/)
    {
        return false;
    }

    bool UIVisual::OnGamePadButtonDown(const UIGamePadEventArgs& /*args*/)
    {
        return false;
    }

    bool UIVisual::OnGamePadButtonUp(const UIGamePadEventArgs& /*args*/)
    {
        return false;
    }

    bool UIVisual::OnGamePadButtonPressing(const UIGamePadEventArgs& /*args*/)
    {
        return false;
    }

    bool UIVisual::OnGamePadTrigger(const UIGamePadEventArgs& /*args*/)
    {
        return false;
    }

    bool UIVisual::OnGamePadThumbstick(const UIGamePadEventArgs& /*args*/)
    {
        return false;
    }

#   define RaiseRoutedEvent(onCallbackMethod, raiseEventMethod, eventID, args) \
                bool handled = onCallbackMethod(args); \
                if (eventMap) \
                    handled = eventMap->RaiseEvent(eventID, args) || handled; \
                \
                if (handled == false) \
                { \
                    if (UIVisual* parent = GetParent()) \
                        parent->raiseEventMethod(args); \
                }

    void UIVisual::RaiseKeyDownEvent(const UIKeyboardEventArgs& args)
    {
        RaiseRoutedEvent(OnKeyDown, RaiseKeyDownEvent, UIEventID::KeyDown, args);
    }

    void UIVisual::RaiseKeyUpEvent(const UIKeyboardEventArgs& args)
    {
        RaiseRoutedEvent(OnKeyUp, RaiseKeyUpEvent, UIEventID::KeyUp, args);
    }

    void UIVisual::RaiseKeyPressingEvent(const UIKeyboardEventArgs& args)
    {
        RaiseRoutedEvent(OnKeyPressing, RaiseKeyPressingEvent, UIEventID::KeyPressing, args);
    }

    void UIVisual::RaiseMouseEnterEvent(const UIMouseEventArgs& args)
    {
        OnMouseEnter(args);
        if (eventMap)
            eventMap->RaiseEvent(UIEventID::MouseEnter, args);
    }

    void UIVisual::RaiseMouseLeaveEvent(const UIMouseEventArgs& args)
    {
        OnMouseLeave(args);
        if (eventMap)
            eventMap->RaiseEvent(UIEventID::MouseLeave, args);
    }

    void UIVisual::RaiseMouseMoveEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseMove, RaiseMouseMoveEvent, UIEventID::MouseMove, args);
    }

    void UIVisual::RaiseMouseClickEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseClick, RaiseMouseClickEvent, UIEventID::MouseClick, args);
    }

    void UIVisual::RaiseMouseButtonDownEvent(const UIMouseButtonEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseButtonDown, RaiseMouseButtonDownEvent, UIEventID::MouseButtonDown, args);
    }

    void UIVisual::RaiseMouseButtonUpEvent(const UIMouseButtonEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseButtonUp, RaiseMouseButtonUpEvent, UIEventID::MouseButtonUp, args);
    }

    void UIVisual::RaiseMouseButtonPressingEvent(const UIMouseButtonEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseButtonPressing, RaiseMouseButtonPressingEvent, UIEventID::MouseButtonPressing, args);
    }

    void UIVisual::RaiseMouseWheelEvent(const UIMouseWheelEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseWheel, RaiseMouseWheelEvent, UIEventID::MouseWheel, args);
    }

    void UIVisual::RaiseGamePadButtonDownEvent(const UIGamePadEventArgs& args)
    {
        RaiseRoutedEvent(OnGamePadButtonDown, RaiseGamePadButtonDownEvent, UIEventID::GamePadButtonDown, args);
    }

    void UIVisual::RaiseGamePadButtonUpEvent(const UIGamePadEventArgs& args)
    {
        RaiseRoutedEvent(OnGamePadButtonUp, RaiseGamePadButtonUpEvent, UIEventID::GamePadButtonUp, args);
    }

    void UIVisual::RaiseGamePadButtonPressingEvent(const UIGamePadEventArgs& args)
    {
        RaiseRoutedEvent(OnGamePadButtonPressing, RaiseGamePadButtonPressingEvent, UIEventID::GamePadButtonPressing, args);
    }

    void UIVisual::RaiseGamePadTriggerEvent(const UIGamePadEventArgs& args)
    {
        RaiseRoutedEvent(OnGamePadTrigger, RaiseGamePadTriggerEvent, UIEventID::GamePadTrigger, args);
    }

    void UIVisual::RaiseGamePadThumbstickEvent(const UIGamePadEventArgs& args)
    {
        RaiseRoutedEvent(OnGamePadThumbstick, RaiseGamePadThumbstickEvent, UIEventID::GamePadThumbstick, args);
    }

#   undef RaiseRoutedEvent
}