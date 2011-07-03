#pragma once
#ifndef __HALAK_UIWINDOW_H__
#define __HALAK_UIWINDOW_H__

#   include <Halak/FWD.h>
#   include <Halak/UIPanel.h>
#   include <Halak/Signal.h>
#   include <vector>

    namespace Halak
    {
        class UIWindow : public UIPanel
        {
            public:
                UIWindow();
                explicit UIWindow(int childrenCapacity);
                virtual ~UIWindow();

                inline void AddChild(UIVisual* item);
                inline void InsertChild(int index, UIVisual* item);
                inline bool RemoveChild(UIVisual* item);
                inline bool RemoveChildAt(int index);
                inline void RemoveAllChildren();

                virtual Vector2 GetDesiredSize();

                inline Vector2 GetFixedSize() const;
                inline void SetFixedSize(Vector2 value);

                inline bool GetFixedSizeUsed() const;
                inline void SetFixedSizeUsed(bool value);

            private:
                Vector2 fixedSize;
                bool fixedSizeUsed;
        };
    }

#   include <Halak/UIWindow.inl>

#endif