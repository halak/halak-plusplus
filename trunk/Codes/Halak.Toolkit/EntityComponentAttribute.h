#pragma once
#ifndef __HALAK_ENTITYCOMPONENTATTRIBUTE_H__
#define __HALAK_ENTITYCOMPONENTATTRIBUTE_H__

#   include <Halak/FWD.h>
#   include <Halak/Attribute.h>

    namespace Halak
    {
        class EntityComponentAttribute : public Attribute
        {
            public:
                EntityComponentAttribute();
                virtual ~EntityComponentAttribute();
        };
    }

#endif