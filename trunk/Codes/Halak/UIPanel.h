#pragma once
#ifndef __HALAK_UIPANEL_H__
#define __HALAK_UIPANEL_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisual.h>
#   include <Halak/Signal.h>
#   include <vector>

    namespace Halak
    {
        class UIPanel : public UIVisual
        {
            public:
                typedef std::vector<UIVisualPtr> VisualCollection;

            public:
                UIPanel();
                explicit UIPanel(int childrenCapacity);
                virtual ~UIPanel();

                virtual RectangleF ComputeBounds(UIVisualVisitor& visitor);

                UIVisual* FindChild(const String& name, bool searchAllChildren) const;

                inline Vector2 GetDesiredSize() const;
                void SetDesiredSize(Vector2 value);

                inline const VisualCollection& GetChildren() const;

                virtual bool IsPanel() const;

            protected:
                void Add(UIVisual* item);
                void Insert(int index, UIVisual* item);
                bool Remove(UIVisual* item);
                bool RemoveAt(int index);
                void RemoveAll();

                void DrawChildren(UIDrawingContext& context);

                virtual void OnDraw(UIDrawingContext& context);
                virtual void OnPick(UIPickingContext& context);
                virtual void OnChildAdded(UIVisual* child);
                virtual void OnChildRemoved(UIVisual* child);
                virtual void OnChildrenAdded(const VisualCollection& children);
                virtual void OnChildrenRemoved(const VisualCollection& children);

            private:
                void RemoveByIterator(VisualCollection::iterator it);

                void BringChildToFront(UIVisual* child);
                void SendChildToBack(UIVisual* child);

            private:
                Vector2 desiredSize;
                VisualCollection children;

                friend class UIVisual;
        };
    }

#   include <Halak/UIPanel.inl>

#endif