#include <Halak/PCH.h>
#include <Halak/UIWindow.h>
#include <Halak/Assert.h>
#include <Halak/Math.h>
#include <Halak/UIDrawingContext.h>
#include <Halak/UIFrame.h>
#include <Halak/UIPickingContext.h>
#include <Halak/UIVisual.h>
#include <algorithm>

namespace Halak
{
    UIWindow::UIWindow()
    {
    }

    UIWindow::UIWindow(int childrenCapacity)
    {
        children.reserve(childrenCapacity);
    }

    UIWindow::~UIWindow()
    {
    }

    void UIWindow::AddChild(UIVisual* item)
    {
        InsertChild(children.size(), item);
    }

    void UIWindow::InsertChild(int index, UIVisual* item)
    {
        index = Math::Clamp(index, 0, static_cast<int>(children.size()));

        if (index < 0 || static_cast<int>(children.size()) < index)
            return;

        if (item->GetParent())
            item->GetParent()->RemoveChild(item);

        HKAssert(item->GetParent() == nullptr);

        item->SetParent(nullptr);

        if (index < static_cast<int>(children.size()))
            children.insert(children.begin() + index, item);
        else
            children.push_back(item);

        OnChildAdded(item);
    }

    bool UIWindow::RemoveChild(UIVisual* item)
    {
        VisualCollection::iterator it = std::find(children.begin(), children.end(), item);
        if (it != children.end())
        {
            RemoveChildByIterator(it);
            return true;
        }
        else
            return false;
    }

    bool UIWindow::RemoveChildAt(int index)
    {
        if (0 <= index && index < static_cast<int>(children.size()))
        {
            RemoveChildByIterator(children.begin() + index);
            return true;
        }
        else
            return false;
    }

    void UIWindow::RemoveChildByIterator(VisualCollection::iterator it)
    {
        HKAssertDebug(it != children.end() && (*it) != nullptr);

        UIVisualPtr child = (*it);
        children.erase(it);
        child->SetParent(nullptr);
        OnChildRemoved(child);
    }

    void UIWindow::RemoveAllChildren()
    {
        VisualCollection removingChildren;
        removingChildren.swap(children);

        for (VisualCollection::iterator it = removingChildren.begin(); it != removingChildren.end(); it++)
            (*it)->SetParent(nullptr);

        OnChildrenRemoved(removingChildren);
    }

    UIVisualPtr UIWindow::Find(const String& name, bool searchAllChildren) const
    {
        if (searchAllChildren)
        {
            for (VisualCollection::const_iterator it = children.begin(); it != children.end(); it++)
            {
                if ((*it)->GetName() == name)
                    return (*it);

                if ((*it)->IsWindow())
                {
                    if (UIVisualPtr found = static_cast<UIWindow*>((*it).GetPointee())->Find(name, true))
                        return found;
                }
            }
        }
        else
        {
            for (VisualCollection::const_iterator it = children.begin(); it != children.end(); it++)
            {
                if ((*it)->GetName() == name)
                    return (*it);
            }
        }

        return nullptr;
    }

    bool UIWindow::IsWindow() const
    {
        return true;
    }

    void UIWindow::DrawChildren(UIDrawingContext& context)
    {
        for (VisualCollection::iterator it = children.begin(); it != children.end(); it++)
            context.Draw(*it);
    }

    void UIWindow::OnDraw(UIDrawingContext& context)
    {
        UIVisual::OnDraw(context);
        DrawChildren(context);
    }

    void UIWindow::OnPick(UIPickingContext& context)
    {
        if (context.GetCurrentClippedBounds().Contains(context.GetPoint()))
        {
            for (VisualCollection::reverse_iterator it = children.rbegin(); it != children.rend(); it++)
            {
                if (context.Pick(*it))
                    return;
            }

            context.SetResult(this);
        }
    }

    void UIWindow::OnChildAdded(UIVisual* /*child*/)
    {
    }

    void UIWindow::OnChildRemoved(UIVisual* /*child*/)
    {
    }

    void UIWindow::OnChildrenAdded(const VisualCollection& /*children*/)
    {
    }

    void UIWindow::OnChildrenRemoved(const VisualCollection& /*children*/)
    {
    }

    bool UIWindow::OnKeyDown(const UIKeyboardEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnKeyUp(const UIKeyboardEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnKeyPressing(const UIKeyboardEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseEnter(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseLeave(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseMove(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseClick(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseButtonDown(const UIMouseButtonEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseButtonUp(const UIMouseButtonEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseButtonPressing(const UIMouseButtonEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseWheel(const UIMouseWheelEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnGamePadButtonDown(const UIGamePadEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnGamePadButtonUp(const UIGamePadEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnGamePadButtonPressing(const UIGamePadEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnGamePadTrigger(const UIGamePadEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnGamePadThumbstick(const UIGamePadEventArgs& /*args*/)
    {
        return false;
    }

#   define RaiseRoutedEvent(onCallbackMethod, raiseEventMethod, eventSignal, args) \
               bool handled = onCallbackMethod(args); \
               eventSignal.Emit(args, handled); \
               \
               if (handled == false) \
               { \
                   if (UIWindow* parent = GetParent()) \
                       parent->raiseEventMethod(args); \
               } \

    void UIWindow::RaiseKeyDownEvent(const UIKeyboardEventArgs& args)
    {
        RaiseRoutedEvent(OnKeyDown, RaiseKeyDownEvent, keyDownEvent, args);
    }

    void UIWindow::RaiseKeyUpEvent(const UIKeyboardEventArgs& args)
    {
        RaiseRoutedEvent(OnKeyUp, RaiseKeyUpEvent, keyUpEvent, args);
    }

    void UIWindow::RaiseKeyPressingEvent(const UIKeyboardEventArgs& args)
    {
        RaiseRoutedEvent(OnKeyPressing, RaiseKeyPressingEvent, keyPressingEvent, args);
    }

    void UIWindow::RaiseMouseEnterEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseEnter, RaiseMouseEnterEvent, mouseEnterEvent, args);
    }

    void UIWindow::RaiseMouseLeaveEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseLeave, RaiseMouseLeaveEvent, mouseLeaveEvent, args);
    }

    void UIWindow::RaiseMouseMoveEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseMove, RaiseMouseMoveEvent, mouseMoveEvent, args);
    }

    void UIWindow::RaiseMouseClickEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseClick, RaiseMouseClickEvent, mouseClickEvent, args);
    }

    void UIWindow::RaiseMouseButtonDownEvent(const UIMouseButtonEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseButtonDown, RaiseMouseButtonDownEvent, mouseButtonDownEvent, args);
    }

    void UIWindow::RaiseMouseButtonUpEvent(const UIMouseButtonEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseButtonUp, RaiseMouseButtonUpEvent, mouseButtonUpEvent, args);
    }

    void UIWindow::RaiseMouseButtonPressingEvent(const UIMouseButtonEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseButtonPressing, RaiseMouseButtonPressingEvent, mouseButtonPressingEvent, args);
    }

    void UIWindow::RaiseMouseWheelEvent(const UIMouseWheelEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseWheel, RaiseMouseWheelEvent, mouseWheelEvent, args);
    }

    void UIWindow::RaiseGamePadButtonDownEvent(const UIGamePadEventArgs& args)
    {
        RaiseRoutedEvent(OnGamePadButtonDown, RaiseGamePadButtonDownEvent, gamePadButtonDownEvent, args);
    }

    void UIWindow::RaiseGamePadButtonUpEvent(const UIGamePadEventArgs& args)
    {
        RaiseRoutedEvent(OnGamePadButtonUp, RaiseGamePadButtonUpEvent, gamePadButtonUpEvent, args);
    }

    void UIWindow::RaiseGamePadButtonPressingEvent(const UIGamePadEventArgs& args)
    {
        RaiseRoutedEvent(OnGamePadButtonPressing, RaiseGamePadButtonPressingEvent, gamePadButtonPressingEvent, args);
    }

    void UIWindow::RaiseGamePadTriggerEvent(const UIGamePadEventArgs& args)
    {
        RaiseRoutedEvent(OnGamePadTrigger, RaiseGamePadTriggerEvent, gamePadTriggerEvent, args);
    }

    void UIWindow::RaiseGamePadThumbstickEvent(const UIGamePadEventArgs& args)
    {
        RaiseRoutedEvent(OnGamePadThumbstick, RaiseGamePadThumbstickEvent, gamePadThumbstickEvent, args);
    }

#   undef RaiseRoutedEvent
}