#pragma once
#ifndef __HALAK_TOOLKIT_FWD_H__
#define __HALAK_TOOLKIT_FWD_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        namespace Toolkit
        {
#           define HKForwardDeclareSmartPointerClass(name) class name; \
                                                           typedef SharedPointer<name> name##Ptr; \
                                                           typedef WeakPointer<name>   name##WeakPtr;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // 01. Foundation
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // 02. 
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // 03. GUI (wxWidgets)

#           undef HKForwardDeclareSmartPointerClass
        }
    }

#endif