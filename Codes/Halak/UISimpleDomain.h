#pragma once
#ifndef __HALAK_UISIMPLEDOMAIN_H__
#define __HALAK_UISIMPLEDOMAIN_H__

#   include <Halak/FWD.h>
#   include <Halak/UIDomain.h>

    namespace Halak
    {
        class UISimpleDomain : public UIDomain
        {
            HKClassFOURCC('U', 'I', 'S', 'D');
            public:
                UISimpleDomain();
                UISimpleDomain(UIWindow* root);
                UISimpleDomain(UIWindow* root, UIVisual* focus);
                virtual ~UISimpleDomain();

                virtual UIVisual* GetFocus() const;
                virtual void SetFocus(UIVisual* value);

            private:
                UIVisualWeakPtr focus;
        };
    }

#endif