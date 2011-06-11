namespace Halak
{
    void UIWindow::AddChild(UIVisual* item)
    {
        Add(item);
    }

    void UIWindow::InsertChild(int index, UIVisual* item)
    {
        Insert(index, item);
    }

    bool UIWindow::RemoveChild(UIVisual* item)
    {
        return Remove(item);
    }

    bool UIWindow::RemoveChildAt(int index)
    {
        return RemoveAt(index);
    }

    void UIWindow::RemoveAllChildren()
    {
        RemoveAll();
    }
}