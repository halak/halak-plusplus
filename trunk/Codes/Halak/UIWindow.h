#pragma once
#ifndef __HALAK_UIWINDOW_H__
#define __HALAK_UIWINDOW_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisual.h>

    namespace Halak
    {
        class UIWindow : public UIVisual
        {
            public:
                UIWindow();
                virtual ~UIWindow();

            private:
        };
    }

#   include <Halak/UIWindow.inl>

#endif