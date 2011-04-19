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

            inline MouseState();
            inline MouseState(Point position, int wheel, ButtonState leftButton, ButtonState rightButton, ButtonState middleButton);
            inline MouseState(const MouseState& original);

            inline MouseState& operator = (const MouseState& right);
            inline bool operator == (const MouseState& right) const;
            inline bool operator != (const MouseState& right) const;

            static const MouseState Empty;
        };
    }

#   include <Halak/MouseState.inl>

#endif