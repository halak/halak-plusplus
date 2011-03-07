#pragma once
#ifndef __HALAK_WORKFLOW_FLOWCHARTPROCESS_INTERFACE_H__
#define __HALAK_WORKFLOW_FLOWCHARTPROCESS_INTERFACE_H__

#   include <Halak/FWD.h>
#   include <Halak/Any.h>

    namespace Halak
    {
        class IFlowchartProcess
        {
            public:
                virtual ~IFlowchartProcess() { }

                virtual Any Execute(FlowingContext& context) = 0;
        };
    }

#endif