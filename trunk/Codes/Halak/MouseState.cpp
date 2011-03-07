#include <Halak/MouseState.h>

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
}