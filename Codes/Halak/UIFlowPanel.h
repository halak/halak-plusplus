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
                    LeftToRight = 0x01,
                    RightToLeft = 0x02,
                    TopDown     = 0x04,
                    BottomUp    = 0x08,
                };

            public:
                UIFlowPanel();
                virtual ~UIFlowPanel();

                inline Direction GetDirection() const;
                void SetDirection(Direction value);

            protected:
                class ArrangedFrame : public UIFrame
                {
                    public:
                        Vector2 Offset;
                        Vector2 Size;
                        bool IsNewLine;

                    public:
                        ArrangedFrame();
                        ArrangedFrame(Vector2 offset, Vector2 size, bool isNewLine);
                        virtual ~ArrangedFrame();

                        virtual RectangleF ComputeBounds(UIVisualVisitor& visitor, Vector2 desiredSize);
                };

        private:
                Direction direction;
        };
    }

#   include <Halak/UIFlowPanel.inl>

#endif