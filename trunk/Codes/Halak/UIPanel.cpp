#include <Halak/PCH.h>
#include <Halak/UIPanel.h>
#include <Halak/Assert.h>
#include <Halak/Math.h>
#include <Halak/UIDrawingContext.h>
#include <Halak/UIFrame.h>
#include <Halak/UIPickingContext.h>
#include <Halak/UIVisual.h>
#include <algorithm>

namespace Halak
{
    UIPanel::UIPanel()
        : desiredSize(Vector2::Zero)
    {
    }

    UIPanel::UIPanel(int childrenCapacity)
        : desiredSize(Vector2::Zero)
    {
        children.reserve(childrenCapacity);
    }

    UIPanel::~UIPanel()
    {
    }

    RectangleF UIPanel::ComputeBounds(UIVisualVisitor& visitor)
    {
        return GetFrame()->ComputeBounds(visitor, desiredSize);
    }

    UIVisual* UIPanel::FindChild(const String& name, bool searchAllChildren) const
    {
        if (searchAllChildren)
        {
            for (VisualCollection::const_iterator it = children.begin(); it != children.end(); it++)
            {
                if ((*it)->GetName() == name)
                    return (*it);

                if ((*it)->IsPanel())
                {
                    if (UIVisual* found = static_cast<UIPanel*>((*it).GetPointee())->FindChild(name, true))
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

     void UIPanel::SetDesiredSize(Vector2 value)
     {
         desiredSize.X = Math::Max(value.X,  0.0f);
         desiredSize.Y = Math::Max(value.Y,  0.0f);
     }

    bool UIPanel::IsPanel() const
    {
        return true;
    }

    void UIPanel::Add(UIVisual* item)
    {
        Insert(children.size(), item);
    }

    void UIPanel::Insert(int index, UIVisual* item)
    {
        index = Math::Clamp(index, 0, static_cast<int>(children.size()));

        if (index < 0 || static_cast<int>(children.size()) < index)
            return;

        if (item->GetParent())
            item->GetParent()->Remove(item);

        HKAssert(item->GetParent() == nullptr);

        item->SetParent(this);

        if (index < static_cast<int>(children.size()))
            children.insert(children.begin() + index, item);
        else
            children.push_back(item);

        OnChildAdded(item);
    }

    bool UIPanel::Remove(UIVisual* item)
    {
        VisualCollection::iterator it = std::find(children.begin(), children.end(), item);
        if (it != children.end())
        {
            RemoveByIterator(it);
            return true;
        }
        else
            return false;
    }

    bool UIPanel::RemoveAt(int index)
    {
        if (0 <= index && index < static_cast<int>(children.size()))
        {
            RemoveByIterator(children.begin() + index);
            return true;
        }
        else
            return false;
    }

    void UIPanel::RemoveByIterator(VisualCollection::iterator it)
    {
        HKAssertDebug(it != children.end() && (*it) != nullptr);

        UIVisualPtr child = (*it);
        children.erase(it);
        child->SetParent(nullptr);
        OnChildRemoved(child);
    }

    void UIPanel::RemoveAll()
    {
        VisualCollection removingChildren;
        removingChildren.swap(children);

        for (VisualCollection::iterator it = removingChildren.begin(); it != removingChildren.end(); it++)
            (*it)->SetParent(nullptr);

        OnChildrenRemoved(removingChildren);
    }

    void UIPanel::DrawChildren(UIDrawingContext& context)
    {
        for (VisualCollection::const_iterator it = children.begin(); it != children.end(); it++)
            context.Draw(*it);
    }

    void UIPanel::OnDraw(UIDrawingContext& context)
    {
        DrawChildren(context);
    }

    void UIPanel::OnPick(UIPickingContext& context)
    {
        if (context.Contains(context.GetCurrentClippedBounds()))
        {
            for (VisualCollection::const_reverse_iterator it = children.rbegin(); it != children.rend(); it++)
            {
                if (context.Pick(*it))
                    return;
            }

            context.SetResult(this);
        }
    }

    void UIPanel::OnChildAdded(UIVisual* /*child*/)
    {
    }

    void UIPanel::OnChildRemoved(UIVisual* /*child*/)
    {
    }

    void UIPanel::OnChildrenAdded(const VisualCollection& /*children*/)
    {
    }

    void UIPanel::OnChildrenRemoved(const VisualCollection& /*children*/)
    {
    }

    void UIPanel::BringChildToFront(UIVisual* child)
    {
        VisualCollection::iterator it = std::find(children.begin(), children.end(), child);
        HKAssert(it != children.end());
        if (it == children.end() - 1)
        {
            children.erase(it);
            children.push_back(child);
        }
    }

    void UIPanel::SendChildToBack(UIVisual* child)
    {
        VisualCollection::iterator it = std::find(children.begin(), children.end(), child);
        HKAssert(it != children.end());

        if (it != children.begin())
        {
            children.erase(it);
            children.insert(children.begin(), child);
        }
    }
}