#pragma once
#ifndef __HALAK_UILABEL_H__
#define __HALAK_UILABEL_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisual.h>

    namespace Halak
    {
        class UILabel : public UIVisual
        {
            public:
                UILabel();
                virtual ~UILabel();

            private:
        };
    }

#   include <Halak/UILabel.inl>

#endif