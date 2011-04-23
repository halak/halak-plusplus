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

                virtual UIWindow* GetFocus() const = 0;
                virtual void SetFocus(UIWindow* value) = 0;

            private:
                UIWindowPtr root;
        };
    }

#endif