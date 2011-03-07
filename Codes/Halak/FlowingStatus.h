#pragma once
#ifndef __HALAK_WORKFLOW_FLOWINGSTATUS_H__
#define __HALAK_WORKFLOW_FLOWINGSTATUS_H__

    namespace Halak
    {
        struct FlowingStatus
        {
            enum E
            {
                Executing,
                Suspended,
                Finished,
            };
        };
    }

#endif