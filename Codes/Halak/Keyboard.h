#pragma once
#ifndef __HALAK_KEYBOARD_H__
#define __HALAK_KEYBOARD_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/Key.h>

    namespace Halak
    {
        class Keyboard : public GameComponent
        {
            HKClassFOURCC('K', 'B', 'D', '_');
            public:
                Keyboard();
                Keyboard(Window* window);
                virtual ~Keyboard();

                inline bool GetAllowKey(Key::Code code) const;
                inline void SetAllowKey(Key::Code code, bool allow);

                const KeyboardState& GetState();

                Window* GetWindow() const;
                void SetWindow(Window* value);

            private:
                void AllowDefaultKeys();

            private:
                Window* window;
                KeyboardState* state;
                dword allowedKeys[Key::Count / (sizeof(dword) * 8)];
        };
    }

#   include <Halak/Keyboard.inl>

#endif