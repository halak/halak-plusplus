#pragma once
#ifndef __HALAK_WXTOOLKIT_BASEENTITYTRACKER_H__
#define __HALAK_WXTOOLKIT_BASEENTITYTRACKER_H__

#   include <Halak/Service.h>

    namespace Halak
    {
        namespace wxToolkit
        {
            class BaseEntityTracker : public Service
            {
                public:
                    BaseEntityTracker();
                    virtual ~BaseEntityTracker();

                private:
            };
        }
    }

#endif