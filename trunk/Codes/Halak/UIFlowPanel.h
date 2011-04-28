#pragma once
#ifndef __HALAK_UIFLOWPANEL_H__
#define __HALAK_UIFLOWPANEL_H__

#   include <Halak/FWD.h>
#   include <Halak/UIWindow.h>
#   include <Halak/UIFrame.h>
#   include <Halak/UIPickingContext.h>
#   include <Halak/UIDrawingContext.h>

    namespace Halak
    {
        class UIFlowPanel : public UIWindow
        {
            public:
                enum Direction
                {
                    LeftToRight,
                    RightToLeft,
                    TopDown,
                    BottomUp,
                };

            public:
                UIFlowPanel();
                virtual ~UIFlowPanel();

                inline Direction GetDirection() const;
                void SetDirection(Direction value);

            protected:
                virtual void OnDraw(UIDrawingContext& context);
                virtual void OnPick(UIPickingContext& context);
                virtual void OnChildAdded(UIVisual* child);
                virtual void OnChildRemoved(UIVisual* child);
                virtual void OnChildrenAdded(const VisualCollection& children);
                virtual void OnChildrenRemoved(const VisualCollection& children);

            protected:
                class ArrangedFrame : public UIFrame
                {
                    public:
                        ArrangedFrame();
                        virtual ~ArrangedFrame();

                        virtual RectangleF ComputeBounds(UIVisualVisitor& context);
                };

                class DrawingContext : public UIDrawingContext
                {
                    public:
                        DrawingContext();
                        virtual ~DrawingContext();
                };

                class PickingContext : public UIPickingContext
                {
                    public:
                        PickingContext();
                        virtual ~PickingContext();
                };

            private:
                Direction direction;
        };
    }

#   include <Halak/UIFlowPanel.inl>

#endif