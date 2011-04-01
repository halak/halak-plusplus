#pragma once
#ifndef __HALAK_TOOLKIT_ENTITYCOMPONENTATTRIBUTE_H__
#define __HALAK_TOOLKIT_ENTITYCOMPONENTATTRIBUTE_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/Attribute.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class EntityComponentAttribute : public Attribute
            {
                public:
                    EntityComponentAttribute();
                    virtual ~EntityComponentAttribute();
            };
        }
    }

#endif