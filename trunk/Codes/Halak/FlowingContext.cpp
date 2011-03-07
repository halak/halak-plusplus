#include <Halak/FlowingContext.h>
#include <Halak/Assert.h>
#include <Halak/Flowchart.h>
#include <Halak/FlowchartBlock.h>
#include <Halak/VariableStorage.h>
#include <Halak/Any.h>
#include <stdexcept>

namespace Halak
{
    FlowingContext::FlowingContext(FlowchartPtr source)
        : source(source),
          status(FlowingStatus::Finished),
          variables(new VariableStorage())
    {
    }

    FlowingContext::FlowingContext(FlowchartPtr source, VariableStoragePtr parentVariables)
        : source(source),
          status(FlowingStatus::Finished),
          variables(new VariableStorage(parentVariables))
    {
    }

    FlowingContext::~FlowingContext()
    {
    }
    
    void FlowingContext::Execute()
    {
        if (GetStatus() == FlowingStatus::Executing)
            throw std::runtime_error("�̹� �������Դϴ�.");
        if (GetStatus() == FlowingStatus::Suspended)
        {
            Resume(Any::Null);
            return;
        }

        ExecuteActually(source->GetStartupBlock());
    }

    void FlowingContext::Resume(const Any& result)
    {
        if (GetStatus() == FlowingStatus::Executing)
            throw std::runtime_error("�̹� �������Դϴ�.");
        if (GetStatus() == FlowingStatus::Finished)
        {
            Execute();
            return;
        }

        HKAssert(current);

        if (FlowchartBlockPtr block = current->FindNextBlock(result))
            ExecuteActually(block);
        else
            throw std::invalid_argument("result");
    }

    void FlowingContext::ExecuteActually(FlowchartBlockPtr next)
    {
        status = FlowingStatus::Executing;

        while (next)
        {
            current = next;
            next = current->Execute(*this);
        }

        switch (GetStatus())
        {
            case FlowingStatus::Executing:
            case FlowingStatus::Finished:
                // ���������� �����ų� �ߴ�(Break) �Ǿ����ϴ�.
                current.reset();
                status = FlowingStatus::Finished;
                break;
            case FlowingStatus::Suspended:
                // �Ͻ������� ����(Yield) �Ǿ����ϴ�.
                // Current�� �����մϴ�.
                break;
        }
    }

    const Any& FlowingContext::Yield()
    {
        status = FlowingStatus::Suspended;
        return Any::Missing;
    }

    const Any& FlowingContext::Break()
    {
        status = FlowingStatus::Finished;
        return Any::Missing;
    }

    FlowchartPtr FlowingContext::GetSource() const
    {
        return source;
    }

    FlowchartBlockPtr FlowingContext::GetCurrent() const
    {
        return current;
    }

    FlowingStatus::E FlowingContext::GetStatus() const
    {
        return status;
    }

    VariableStoragePtr FlowingContext::GetVariables() const
    {
        return variables;
    }
}