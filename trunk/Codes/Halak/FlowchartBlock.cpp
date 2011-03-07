#include <Halak/FlowchartBlock.h>
#include <Halak/IFlowchartProcess.h>

namespace Halak
{
    FlowchartBlock::FlowchartBlock()
    {
    }

    FlowchartBlock::FlowchartBlock(IFlowchartProcessPtr process)
        : process(process)
    {
    }

    FlowchartBlock::~FlowchartBlock()
    {
    }

    FlowchartBlockPtr FlowchartBlock::Execute(FlowingContext& context)
    {
        if (process)
        {
            Any result = process->Execute(context);
            if (result.GetType() != Any::MissingType)
                return FindNextBlock(result);
            else
                return nullptr;
        }
        else
            return defaultNextBlock;
    }

    std::set<FlowchartBlockPtr> FlowchartBlock::Flatten()
    {
        std::set<FlowchartBlockPtr> result;
        FlattenTo(result);
        return result;
    }

    void FlowchartBlock::FlattenTo(std::set<FlowchartBlockPtr>& collection)
    {
        collection.insert(CastTo<FlowchartBlock>());

        for (BlockDictionary::const_iterator it = nextBlocks.begin(); it != nextBlocks.end(); it++)
        {
            if (collection.find((*it).second) == collection.end())
                (*it).second->FlattenTo(collection);
        }
    }

    void FlowchartBlock::AddNextBlock(const Any& key, FlowchartBlockPtr item)
    {
        BlockDictionary::iterator it = nextBlocks.find(key);
        if (it != nextBlocks.end())
            (*it).second = item;
        else
            nextBlocks.insert(BlockDictionary::value_type(key, item));

        if (key.GetType() == Any::NullType)
            defaultNextBlock = item;
    }
        
    bool FlowchartBlock::RemoveNextBlock(const Any& key)
    {
        BlockDictionary::iterator it = nextBlocks.find(key);
        if (it != nextBlocks.end())
        {
            if (key.GetType() == Any::NullType)
                defaultNextBlock.reset();

            nextBlocks.erase(it);
            return true;
        }
        else
            return false;
    }

    void FlowchartBlock::ClearNextBlocks()
    {
        nextBlocks.clear();
        defaultNextBlock.reset();
    }
        
    FlowchartBlockPtr FlowchartBlock::FindNextBlock(const Any& key) const
    {
        if (key.GetType() == Any::NullType)
            return defaultNextBlock;

        BlockDictionary::const_iterator it = nextBlocks.find(key);
        if (it != nextBlocks.end())
            return (*it).second;
        else
            return defaultNextBlock;
    }

    IFlowchartProcessPtr FlowchartBlock::GetProcess() const
    {
        return process;
    }

    void FlowchartBlock::SetProcess(IFlowchartProcessPtr value)
    {
        process = value;
    }

    const FlowchartBlock::BlockDictionary& FlowchartBlock::GetNextBlocks() const
    {
        return nextBlocks;
    }
}