#pragma once
#ifndef __HALAK_UIDOMAIN_H__
#define __HALAK_UIDOMAIN_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class UIDomain : public GameComponent
        {
            HKClassFOURCC('U', 'I', 'D', 'M');
            public:
                UIDomain();
                UIDomain(UIWindow* root);
                virtual ~UIDomain();

                inline UIWindow* GetRoot() const;
                void SetRoot(UIWindow* value);

                virtual UIVisual* GetFocus() const = 0;
                virtual void SetFocus(UIVisual* value) = 0;

            private:
                UIWindowPtr root;
        };
    }

#   include <Halak/UIDomain.inl>

#endif