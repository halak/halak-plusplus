namespace Halak
{
    UIHandledDrawingContext::IHandler* UIHandledDrawingContext::GetHandler() const
    {
        return handler;
    }

    void UIHandledDrawingContext::SetHandler(IHandler* value)
    {
        handler = value;
    }
}