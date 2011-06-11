namespace Halak
{
    const UIFunctionTable* UIFunctionEventHandler::GetTable() const
    {
        return table;
    }

    const String& UIFunctionEventHandler::GetFunctionName() const
    {
        return functionName;
    }
}