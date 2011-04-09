#pragma once
#ifndef __HALAK_UIWINDOW_H__
#define __HALAK_UIWINDOW_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisual.h>
#   include <vector>

    namespace Halak
    {
        class UIWindow : public UIVisual
        {
            public:
                typedef std::vector<UIVisualPtr> VisualCollection;

            public:
                UIWindow();
                explicit UIWindow(int childrenCapacity);
                virtual ~UIWindow();

                void AddChild(const UIVisualPtr& item);
                void InsertChild(int index, const UIVisualPtr& item);
                bool RemoveChild(const UIVisualPtr& item);
                bool RemoveChildAt(int index);
                void RemoveAllChildren();

                UIVisualPtr Find(const String& name, bool searchAllChildren) const;

                inline const VisualCollection& GetChildren() const;

                virtual bool IsWindow() const;

            protected:
                void DrawChildren(UIDrawingContext& context);

                virtual void OnDraw(UIDrawingContext& context);
                virtual void OnChildAdded(const UIVisualPtr& child);
                virtual void OnChildRemoved(const UIVisualPtr& child);
                virtual void OnChildrenAdded(const VisualCollection& children);
                virtual void OnChildrenRemoved(const VisualCollection& children);

            private:
                void RemoveChildByIterator(VisualCollection::iterator it);

            private:
                VisualCollection children;
        };
    }

#   include <Halak/UIWindow.inl>

#endif