#pragma once
#ifndef __HALAK_MOUSESTATE_H__
#define __HALAK_MOUSESTATE_H__

#   include <Halak/FWD.h>
#   include <Halak/Point.h>

    namespace Halak
    {
        struct MouseState
        {
            Point Position;
            int Wheel;
            bool IsLeftButtonPressed;
            bool IsRightButtonPressed;
            bool IsMiddleButtonPressed;

            inline MouseState();
            inline MouseState(Point position, int wheel, bool isLeftButtonPressed, bool isRightButtonPressed, bool isMiddleButtonPressed);
            inline MouseState(const MouseState& original);

            inline MouseState& operator = (const MouseState& right);
            inline bool operator == (const MouseState& right) const;
            inline bool operator != (const MouseState& right) const;

            static const MouseState Empty;
        };
    }

#   include <Halak/MouseState.inl>

#endif