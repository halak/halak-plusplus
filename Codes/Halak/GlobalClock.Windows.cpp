#include <Halak/PCH.h>
#include <Halak/GlobalClock.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

#    include <windows.h>

    namespace Halak
    {
        struct WindowsClock
        {
            static WindowsClock StaticInstance;

            __int64 StartTime;
            double Frequency;
            double FrequencyMilliSeconds;
            bool IsHighResolution;

            WindowsClock()
            {
                LARGE_INTEGER frequencyInteger;
                if (QueryPerformanceFrequency(&frequencyInteger))
                {
                    LARGE_INTEGER startTimeInteger;
                    QueryPerformanceCounter(&startTimeInteger);

                    StartTime = startTimeInteger.QuadPart;
                    Frequency = 1.0 / static_cast<double>(frequencyInteger.QuadPart);
                    FrequencyMilliSeconds = Frequency * 1000.0;
                    IsHighResolution = true;
                }
                else
                {
                    Frequency = 0.0;
                    FrequencyMilliSeconds = 0.0;
                    IsHighResolution = false;
                }
            }

            double GetCurrent()
            {
                if (IsHighResolution)
                {
                    LARGE_INTEGER countInteger;
                    QueryPerformanceCounter(&countInteger);
                    return static_cast<double>(countInteger.QuadPart - StartTime) * Frequency;
                }
                else
                    return static_cast<double>(timeGetTime()) * 0.001f;
            }

            __int64 GetCurrentMilliSeconds()
            {
                if (IsHighResolution)
                {
                    LARGE_INTEGER countInteger;
                    QueryPerformanceCounter(&countInteger);
                    return static_cast<__int64>(static_cast<double>(countInteger.QuadPart - StartTime) * FrequencyMilliSeconds);
                }
                else
                    return static_cast<__int64>(timeGetTime());
            }
        };

        WindowsClock WindowsClock::StaticInstance;

        GlobalClock::GlobalClock()
        {
        }

        GlobalClock::~GlobalClock()
        {
        }

        float GlobalClock::GetCurrent()
        {
            return static_cast<float>(WindowsClock::StaticInstance.GetCurrent());
        }

        uint GlobalClock::GetCurrentMilliSeconds()
        {
            return static_cast<uint>(WindowsClock::StaticInstance.GetCurrentMilliSeconds());
        }

        bool GlobalClock::IsHighResolution()
        {
            return WindowsClock::StaticInstance.IsHighResolution;
        }
    }

#endif