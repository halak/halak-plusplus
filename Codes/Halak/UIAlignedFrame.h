#pragma once
#ifndef __HALAK_UIALIGNEDFRAME_H__
#define __HALAK_UIALIGNEDFRAME_H__

#   include <Halak/FWD.h>
#   include <Halak/UIFrame.h>
#   include <Halak/Vector2.h>

    namespace Halak
    {
        class UIAlignedFrame : public UIFrame
        {
            public:
                enum Alignment
                {
                    LeftTop,
                    LeftBottom,
                    LeftMiddle,
                    RightTop,
                    RightBottom,
                    RightMiddle,
                    CenterTop,
                    CenterBottom,
                    Center,
                };

            public:
                UIAlignedFrame();
                UIAlignedFrame(Vector2 offset, Vector2 size);
                UIAlignedFrame(Alignment align, Vector2 offset, Vector2 size);
                virtual ~UIAlignedFrame();

                virtual RectangleF ComputeBounds(UIVisualVisitor& visitor);

                inline Alignment GetAlign() const;
                void SetAlign(Alignment value);
                
                inline Vector2 GetOffset() const;
                void SetOffset(Vector2 value);

                inline Vector2 GetSize() const;
                void SetSize(Vector2 value);

            private:
                Alignment align;
                Vector2 offset;
                Vector2 size;
                RectangleF lastBounds;
                RectangleF lastReferenceBounds;
                bool boundsChanged;
        };
    }

#   include <Halak/UIAlignedFrame.inl>

#endif