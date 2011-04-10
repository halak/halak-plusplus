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
}