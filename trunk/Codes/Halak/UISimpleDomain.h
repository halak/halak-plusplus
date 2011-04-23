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
                UISimpleDomain(UIWindow* root, UIWindow* focus);
                virtual ~UISimpleDomain();

                virtual UIWindow* GetFocus() const;
                virtual void SetFocus(UIWindow* value);

            private:
                UIWindowWeakPtr focus;
        };
    }

#endif