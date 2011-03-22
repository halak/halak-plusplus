#include <Halak/PCH.h>
#include <Halak/GameFramework.Windows.h>
#include <Halak/Assert.h>
#include <Halak/Clock.h>
#include <Halak/GameStructure.h>
#include <Halak/GameNode.h>
#include <Halak/GameWindow.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/Math.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

    namespace Halak
    {
        GameFramework::GameFramework()
            : structure(new GameStructure()),
              window(new GameWindow()),
              graphicsDevice(new GraphicsDevice()),
              mainTimeline(nullptr),
              desiredElapsedTime(0.0f),
              fixedTimeStep(true)
        {
            structure->GetRoot()->AttachChild(window);
            structure->GetRoot()->AttachChild(graphicsDevice);

            SYSTEM_INFO systemInfo = { 0, };
            GetSystemInfo(&systemInfo);
            HKAssert(systemInfo.dwNumberOfProcessors > 0);
            if (systemInfo.dwNumberOfProcessors == 1)
                sleepDuration = 1;
            else
                sleepDuration = 0;

            SetDesiredElapsedTime(1.0f / 60.0f);
        }

        GameFramework::~GameFramework()
        {
            delete structure;
        }

        void GameFramework::Run()
        {
            Initialize();

            uint  timestamp = 0;
            float previousTime = Clock::GetCurrent();
            timestamps.push_back(previousTime);

            MSG msg = { 0, };
            for (;;)
            {
                if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);

                    if (msg.message == WM_QUIT)
                    {
                        Finalize();
                        break;
                    }
                }
                else
                {
                    const float currentTime = Clock::GetCurrent();
                    const float elapsedTime = currentTime - previousTime;

                    if (fixedTimeStep)
                    {
                        for (/**/; currentTime - previousTime > desiredElapsedTime; previousTime += desiredElapsedTime)
                            Update(desiredElapsedTime, ++timestamp);
                    }
                    else
                    {
                        Update(currentTime - previousTime, ++timestamp);
                        previousTime = currentTime;
                    }

                    BeginDraw();
                    Draw();
                    EndDraw();

                    if (sleepDuration > 0)
                        Sleep(sleepDuration);
                }
            }
        }

        void GameFramework::SetFixedTimeStep(bool value)
        {
            fixedTimeStep = value;
        }

        void GameFramework::SetDesiredElapsedTime(float value)
        {
            desiredElapsedTime = Math::Max(value, 0.0001f);
            desiredFPS = static_cast<uint>(1.0f / desiredElapsedTime);
        }

        float GameFramework::GetFPS() const
        {
            if (timestamps.size() >= 2)
                return static_cast<float>(timestamps.size() - 1) / (timestamps.back() - timestamps.front());
            else
                return 0.0f;
        }

        void GameFramework::Initialize()
        {
            if (window->GetSize() == Point::Zero)
                window->SetSize(Point(800, 600));

            graphicsDevice->SetWindow(window);
            window->SetVisible(true);
        }

        void GameFramework::Finalize()
        {
            window->SetVisible(false);
        }

        void GameFramework::Update(float dt, uint timestamp)
        {
            if (mainTimeline)
                mainTimeline->Update(dt, timestamp);
        }

        void GameFramework::Draw()
        {
        }

        void GameFramework::BeginDraw()
        {
            graphicsDevice->BeginDraw();
        }

        void GameFramework::EndDraw()
        {
            graphicsDevice->EndDraw();
            graphicsDevice->Present();
        }
    }

#endif

//
//    #include <TH/GameFramework.h>
//#include <Halak/Assert.h>
//#include <Halak/Clock.h>
//#include <Halak/GameWindow.h>
//#include <Halak/GraphicsDevice.h>
//#include <Halak/ServiceContainer.h>
//#include <deque>
//#include <limits>
//using namespace TH;
//using namespace Halak;
//
//namespace TH
//{
//    GameFramework::GameFramework()
//        : services(nullptr),
//          window(nullptr),
//          graphicsDevice(nullptr),
//          desiredElapsedTime(0.0f),
//          fixedTimeStep(true)
//    {
//        services = new ServiceContainer();
//        window = new GameWindow();
//        graphicsDevice = new GraphicsDevice();
//
//        GetServices()->Add(window);
//        GetServices()->Add(graphicsDevice);
//
//        // CPU 개수에 따라서 Sleep 주기를 결정합니다.
//        // CPU가 2개 이상이면 Sleep를 걸어줄 필요가 없습니다.
//        SYSTEM_INFO systemInfo = { 0, };
//        GetSystemInfo(&systemInfo);
//        HKAssert(systemInfo.dwNumberOfProcessors > 0);
//        if (systemInfo.dwNumberOfProcessors == 1)
//            sleepDuration = 1;
//        else
//            sleepDuration = 0;
//
//        // 기본 목표 FPS는 60으로 합니다.
//        SetDesiredElapsedTime(1.0f / 60.0f);
//        SetFrameLimiter(true);
//    }
//
//    GameFramework::~GameFramework()
//    {
//        delete services;
//    }
//
//    void GameFramework::Run()
//    {
//        //try
//        {
//            Initialize();
//        }
//        //catch (const std::exception& e)
//        //{
//        //    MessageBox(NULL, e.what(), "ALERT", MB_OK | MB_ICONERROR);
//        //    GetWindow()->Close();
//        //}
//
//        uint timestamp = 0;
//        float previousTime = Halak::Clock::GetCurrent();
//        timeStamps.push_back(previousTime);
//
//        MSG msg = { 0, };
//        for (;;)
//        {
//            if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
//            {
//                TranslateMessage(&msg);
//                DispatchMessage(&msg);
//
//                if (msg.message == WM_QUIT)
//                {
//                    Finalize();
//                    break;
//                }
//            }
//            else
//            {
//                const float currentTime = Halak::Clock::GetCurrent();
//                
//                if(GetFrameLimiter() && currentTime - previousTime < GetDesiredElapsedTime())
//                {
//                    if(GetDesiredElapsedTime() - (currentTime - previousTime) > 0.001f)
//                        Sleep(1);
//                    continue;
//                }
//
//                timeStamps.push_back(currentTime);
//                while(currentTime - timeStamps.front() >= 1.0f)
//                    // 바로 직전에 currentTime 을 추가했으므로 timeStamps 가 비었는지 검사할 필요는 없습니다.
//                    timeStamps.pop_front();
//                
//                BeginUpdate();
//                Update(currentTime - previousTime, timestamp++);
//                EndUpdate();
//
//                BeginDraw();
//                Draw();
//                EndDraw();
//
//                previousTime = currentTime;
//
//                if (sleepDuration > 0)
//                    Sleep(sleepDuration);
//            }
//        }
//    }
//
//    ServiceContainer* GameFramework::GetServices()
//    {
//        return services;
//    }
//
//    GameWindow* GameFramework::GetWindow()
//    {
//        return window;
//    }
//
//    GraphicsDevice* GameFramework::GetGraphicsDevice()
//    {
//        return graphicsDevice;
//    }
//
//    bool GameFramework::GetFixedTimeStep() const
//    {
//        return fixedTimeStep;
//    }
//
//    void GameFramework::SetFixedTimeStep(bool value)
//    {
//        fixedTimeStep = value;
//    }
//
//    float GameFramework::GetDesiredElapsedTime() const
//    {
//        return desiredElapsedTime;
//    }
//
//    void GameFramework::SetDesiredElapsedTime(float value)
//    {
//        value = std::max<float>(value, 0.000001f);
//        desiredElapsedTime = value;
//        desiredFPS = static_cast<unsigned int>(1.0f / value);
//    }
//
//    bool GameFramework::GetFrameLimiter() const
//    {
//        return frameLimiter;
//    }
//
//    void GameFramework::SetFrameLimiter(bool value)
//    {
//        frameLimiter = value;
//    }
//
//    float GameFramework::GetFPS() const
//    {
//        if (timeStamps.size() >= 2)
//            return static_cast<float>(timeStamps.size() - 1) / static_cast<float>(timeStamps.back() - timeStamps.front());
//        else
//            return std::numeric_limits<float>::quiet_NaN();
//    }
//
//    void GameFramework::Initialize()
//    {
//        if (GetWindow()->GetSize() == Point::Zero)
//            GetWindow()->SetSize(Point(800, 600));
//
//        GetGraphicsDevice()->SetWindow(GetWindow());
//        GetWindow()->SetVisible(true);
//    }
//
//    void GameFramework::Finalize()
//    {
//        GetWindow()->SetVisible(false);
//    }
//
//    void GameFramework::Update(float dt, uint timestamp)
//    {
//        GetServices()->Update(dt, timestamp);
//    }
//
//    void GameFramework::Draw()
//    {
//    }
//
//    void GameFramework::BeginUpdate()
//    {
//    }
//
//    void GameFramework::EndUpdate()
//    {
//    }
//
//    void GameFramework::BeginDraw()
//    {
//        graphicsDevice->BeginDraw();
//    }
//
//    void GameFramework::EndDraw()
//    {
//        graphicsDevice->EndDraw();
//        graphicsDevice->Present();
//    }
//}