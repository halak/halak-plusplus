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
            HKClassFOURCC('M', 'O', 'U', 'S');
            public:
                Mouse();
                Mouse(Window* window);
                virtual ~Mouse();

                const MouseState& GetState();

                void SetPosition(Point value);

                Window* GetWindow();
                void SetWindow(Window* value);
                
            private:
                void OnMouseWheel(int delta);

            private:
                Window* window;
                MouseState* state;
        };
    }

#endif