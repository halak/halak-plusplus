#include <Halak/Keyboard.h>
#include <Halak/Assert.h>
#include <Halak/KeyboardState.h>
#include <Halak/Window.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

#   define WIN32_LEAN_AND_MEAN
#   include <windows.h>

    namespace Halak
    {
        const KeyboardState& Keyboard::GetState()
        {
            HKStaticAssert(sizeof(allowedKeys) == sizeof(state->Keys));

            if (window && window->GetHandle() == GetForegroundWindow())
            {
                uint code = 0;
                for (int i = 0; i < sizeof(allowedKeys) / sizeof(allowedKeys[0]); i++)
                {
                    dword& keyStateField = state->Keys[i];
                    const dword allowField = allowedKeys[i];
                    for (dword k = 0x80000000; k != 0x00000000; k >>= 1, code++)
                    {
                        if ((allowField & k) != 0x00000000)
                        {
                            const int vkCode = static_cast<int>(code); // �ϴ� �״�� Mapping �����Ƿ� ���� ����.

                            if (GetAsyncKeyState(vkCode))
                            {
                                keyStateField |= k;
                            }
                            else
                                keyStateField &= ~k;
                        }
                        else
                            keyStateField &= ~k;
                    }
                }

                return *state;
            }
            else
                return KeyboardState::Empty;
        }
    }

#endif