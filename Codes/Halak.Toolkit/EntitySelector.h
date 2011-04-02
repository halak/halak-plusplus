#pragma once
#ifndef __HALAK_TOOLKIT_ENTITYSELECTOR_H__
#define __HALAK_TOOLKIT_ENTITYSELECTOR_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/Service.h>

    namespace Halak
    {
        namespace Toolkit
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