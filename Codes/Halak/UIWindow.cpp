#include <Halak/PCH.h>
#include <Halak/UIWindow.h>
#include <Halak/Assert.h>
#include <Halak/Math.h>
#include <Halak/UIDrawingContext.h>
#include <Halak/UIFrame.h>
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

    void UIWindow::AddChild(const UIVisualPtr& item)
    {
        InsertChild(children.size(), item);
    }

    void UIWindow::InsertChild(int index, const UIVisualPtr& item)
    {
        index = Math::Clamp(index, 0, static_cast<int>(children.size()));

        if (index < 0 || static_cast<int>(children.size()) < index)
            return;

        if (item->GetParent().IsAlive())
            item->GetParent().Lock()->RemoveChild(item);

        HKAssert(item->GetParent().IsAlive() == false);

        item->SetParent(nullptr);

        if (index < static_cast<int>(children.size()))
            children.insert(children.begin() + index, item);
        else
            children.push_back(item);

        OnChildAdded(item);
    }

    bool UIWindow::RemoveChild(const UIVisualPtr& item)
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
        for (VisualCollection::iterator it = children.begin(); it != children.end(); ++it)
            context.Visit(*it);
    }

    void UIWindow::OnDraw(UIDrawingContext& context)
    {
        UIVisual::OnDraw(context);
        DrawChildren(context);
    }

    void UIWindow::OnChildAdded(const UIVisualPtr& /*child*/)
    {
    }

    void UIWindow::OnChildRemoved(const UIVisualPtr& /*child*/)
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

    bool UIWindow::OnMouseLeftDown(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseLeftUp(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseRightDown(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseRightUp(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseMiddleDown(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseMiddleUp(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseWheel(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnMouseClick(const UIMouseEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnButtonDown(const UIGamePadEventArgs& /*args*/)
    {
        return false;
    }

    bool UIWindow::OnButtonUp(const UIGamePadEventArgs& /*args*/)
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

    void UIWindow::RaiseMouseLeftDownEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseLeftDown, RaiseMouseLeftDownEvent, mouseLeftDownEvent, args);
    }

    void UIWindow::RaiseMouseLeftUpEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseLeftUp, RaiseMouseLeftUpEvent, mouseLeftUpEvent, args);
    }

    void UIWindow::RaiseMouseRightDownEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseRightDown, RaiseMouseRightDownEvent, mouseRightDownEvent, args);
    }

    void UIWindow::RaiseMouseRightUpEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseRightUp, RaiseMouseRightUpEvent, mouseRightUpEvent, args);
    }

    void UIWindow::RaiseMouseMiddleDownEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseMiddleDown, RaiseMouseMiddleDownEvent, mouseMiddleDownEvent, args);
    }

    void UIWindow::RaiseMouseMiddleUpEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseMiddleUp, RaiseMouseMiddleUpEvent, mouseMiddleUpEvent, args);
    }

    void UIWindow::RaiseMouseWheelEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseWheel, RaiseMouseWheelEvent, mouseWheelEvent, args);
    }

    void UIWindow::RaiseMouseClickEvent(const UIMouseEventArgs& args)
    {
        RaiseRoutedEvent(OnMouseClick, RaiseMouseClickEvent, mouseClickEvent, args);
    }

    void UIWindow::RaiseButtonDownEvent(const UIGamePadEventArgs& args)
    {
        RaiseRoutedEvent(OnButtonDown, RaiseButtonDownEvent, buttonDownEvent, args);
    }

    void UIWindow::RaiseButtonUpEvent(const UIGamePadEventArgs& args)
    {
        RaiseRoutedEvent(OnButtonUp, RaiseButtonUpEvent, buttonUpEvent, args);
    }

#   undef RaiseRoutedEvent
}