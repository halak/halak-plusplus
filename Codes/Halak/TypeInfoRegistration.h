#pragma once
#ifndef __HALAK_TYPEINFOREGISTRATION_H__
#define __HALAK_TYPEINFOREGISTRATION_H__

    namespace Halak
    {
        class TypeInfoRegistration
        {
            public:
                static void Add(void (*registerTypeInfo)());
                static void Startup();
        };
    }

#endif