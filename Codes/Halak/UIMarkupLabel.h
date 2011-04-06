#pragma once
#ifndef __HALAK_UIMARKUPTEXT_H__
#define __HALAK_UIMARKUPTEXT_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisual.h>

    namespace Halak
    {
        class UIMarkupLabel : public UIVisual
        {
            public:
                UIMarkupLabel();
                virtual ~UIMarkupLabel();

            private:
        };
    }

#   include <Halak/UIMarkupLabel.inl>

#endif