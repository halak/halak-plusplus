#pragma once
#ifndef __HALAK_TOOLKIT_BASEENTITYTRACKER_H__
#define __HALAK_TOOLKIT_BASEENTITYTRACKER_H__

#   include <Halak/Service.h>

    namespace Halak
    {
        namespace Toolkit
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