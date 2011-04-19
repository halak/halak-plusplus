namespace Halak
{
    Point UIMouseEventArgs::GetPosition() const
    {
        return position;
    }

    int UIMouseEventArgs::GetWheelDelta() const
    {
        return wheelDelta;
    }

    bool UIMouseEventArgs::GetLeftButton() const
    {
        return leftButton;
    }

    bool UIMouseEventArgs::GetRightButton() const
    {
        return rightButton;
    }

    bool UIMouseEventArgs::GetMiddleButton() const
    {
        return middleButton;
    }
}