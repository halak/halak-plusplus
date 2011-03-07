#pragma once
#ifndef __HALAK_MOUSESTATE_H__
#define __HALAK_MOUSESTATE_H__

#   include <Halak/FWD.h>
#   include <Halak/Point.h>

    namespace Halak
    {
        struct MouseState
        {
            enum ButtonState
            {
                ReleasedButton,
                PressedButton,
            };

            Point Position;
            int Wheel;
            ButtonState LeftButton;
            ButtonState RightButton;
            ButtonState MiddleButton;

            MouseState();
            MouseState(Point position, int wheel, ButtonState leftButton, ButtonState rightButton, ButtonState middleButton);
        };
    }

#endif