#pragma once
#ifndef __HALAK_UIPICKINGCONTEXT_H__
#define __HALAK_UIPICKINGCONTEXT_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisualVisitor.h>

    namespace Halak
    {
        class UIPickingContext : public UIVisualVisitor
        {
            public:
                UIPickingContext();
                virtual ~UIPickingContext();

            protected:
                virtual void OnVisit(UIVisual* target);
        };
    }

#   include <Halak/UIPickingContext.inl>

#endif