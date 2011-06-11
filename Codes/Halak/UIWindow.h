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
        };
    }

#   include <Halak/UIWindow.inl>

#endif