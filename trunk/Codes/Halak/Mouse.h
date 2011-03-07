#pragma once
#ifndef __HALAK_MOUSE_H__
#define __HALAK_MOUSE_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/Point.h>

    namespace Halak
    {
        class Mouse : public GameComponent
        {
            public:
                Mouse(Window* window);

                const MouseState& GetState();

                void SetPosition(Point value);

            protected:
                virtual ~Mouse();

            private:
                void OnMouseWheel(int delta);

            private:
                Window* window;
                MouseState* state;
        };
    }

#endif