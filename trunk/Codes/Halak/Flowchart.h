#pragma once
#ifndef __HALAK_WORKFLOW_FLOWCHART_H__
#define __HALAK_WORKFLOW_FLOWCHART_H__

#   include <Halak/FWD.h>
#   include <Halak/Asset.h>
#   include <set>

    namespace Halak
    {
        class Flowchart : public Asset
        {
            public:
                typedef std::set<FlowchartBlockPtr> BlockCollection;

            public:
                Flowchart();
                virtual ~Flowchart();

                void AddMajorBlock(FlowchartBlockPtr item);
                bool RemoveMajorBlock(FlowchartBlockPtr item);
                void ClearMajorBlocks();

                FlowchartBlockPtr GetStartupBlock() const;
                void SetStartupBlock(FlowchartBlockPtr value);

                const BlockCollection& GetMajorBlocks() const;

            private:
                FlowchartBlockPtr startupBlock;
                BlockCollection majorBlocks;
        };
    }

#endif