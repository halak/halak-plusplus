#pragma once
#ifndef __HALAK_WXTOOLKIT_ENTITYSELECTOR_H__
#define __HALAK_WXTOOLKIT_ENTITYSELECTOR_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <Halak/Service.h>

    namespace Halak
    {
        namespace wxToolkit
        {
            class EntitySelector : public Service
            {
                public:
                    EntitySelector();
                    EntitySelector(uint id);

                private:
                    virtual ~EntitySelector();
            };
        }
    }

#endif