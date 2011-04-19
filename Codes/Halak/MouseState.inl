namespace Halak
{
    MouseState::MouseState()
        : Position(Point::Zero),
          Wheel(0),
          LeftButton(MouseState::ReleasedButton),
          RightButton(MouseState::ReleasedButton),
          MiddleButton(MouseState::ReleasedButton)
    {
    }

    MouseState::MouseState(Point position, int wheel, ButtonState leftButton, ButtonState rightButton, ButtonState middleButton)
        : Position(position),
          Wheel(wheel),
          LeftButton(leftButton),
          RightButton(rightButton),
          MiddleButton(middleButton)
    {
    }

    MouseState::MouseState(const MouseState& original)
        : Position(original.Position),
          Wheel(original.Wheel),
          LeftButton(original.LeftButton),
          RightButton(original.RightButton),
          MiddleButton(original.MiddleButton)
    {
    }

    MouseState& MouseState::operator = (const MouseState& right)
    {
        if (this == &right)
            return *this;

        Position = right.Position;
        Wheel = right.Wheel;
        LeftButton = right.LeftButton;
        RightButton = right.RightButton;
        MiddleButton = right.MiddleButton;
        return *this;
    }

    bool MouseState::operator == (const MouseState& right) const
    {
        return Position == right.Position &&
               Wheel == right.Wheel &&
               LeftButton == right.LeftButton &&
               RightButton == right.RightButton &&
               MiddleButton == right.MiddleButton;
    }

    bool MouseState::operator != (const MouseState& right) const
    {
        return !operator == (right);
    }
}