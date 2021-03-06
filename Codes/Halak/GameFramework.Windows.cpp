#include <Halak/PCH.h>
#include <Halak/GameFramework.Windows.h>
#include <Halak/Assert.h>
#include <Halak/Clock.h>
#include <Halak/GameStructure.h>
#include <Halak/GameNode.h>
#include <Halak/GameWindow.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/Math.h>
#include <Halak/Timeline.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

    namespace Halak
    {
        static const uint GeneralFPS = 60;

        GameFramework::GameFramework()
            : structure(new GameStructure()),
              window(new GameWindow()),
              graphicsDevice(new GraphicsDevice()),
              mainTimeline(new Timeline()),
              fixedTimeStep(true),
              fixedElapsedTime(1.0f / static_cast<float>(GeneralFPS)),
              maxTimeInOneFrame(1.0f),
              desiredFPS(GeneralFPS)
        {
            structure->GetRoot()->AttachChild(window);
            structure->GetRoot()->AttachChild(graphicsDevice);
            structure->GetRoot()->AttachChild(mainTimeline);

            //SYSTEM_INFO systemInfo = { 0, };
            //GetSystemInfo(&systemInfo);
            //HKAssert(systemInfo.dwNumberOfProcessors > 0);
            //if (systemInfo.dwNumberOfProcessors == 1)
            //    sleepDuration = 1;
            //else
            //    sleepDuration = 0;
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
                        const float dt = fixedElapsedTime;
                        float time = Math::Min(elapsedTime, maxTimeInOneFrame);
                        if (time < dt)
                        {
                            Sleep(1);
                            continue;
                        }

                        for (/**/; time >= dt; time -= dt, previousTime += dt)
                            Update(dt, timestamp++);
                    }
                    else
                    {
                        Update(currentTime - previousTime, timestamp++);
                        previousTime = currentTime;
                    }

                    BeginDraw();
                    Draw();
                    EndDraw();

                    timestamps.push_back(currentTime);
                    if (static_cast<uint>(timestamps.size()) > desiredFPS)
                        timestamps.pop_front();

                    Sleep(1);
                }
            }
        }

        void GameFramework::SetFixedTimeStep(bool value)
        {
            fixedTimeStep = value;
        }

        void GameFramework::SetFixedElapsedTime(float value)
        {
            fixedElapsedTime = Math::Max(value, 0.0001f);
            desiredFPS = Math::Min(static_cast<uint>(1.0f / fixedElapsedTime), GeneralFPS);
        }

        void GameFramework::SetMaxTimeInOneFrame(float value)
        {
            maxTimeInOneFrame = Math::Max(value, 0.0001f);
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

        void GameFramework::ForceUpdateAllComponents(float dt, uint timestamp)
        {
            ForceUpdateComponent(structure->GetRoot(), dt, timestamp);
        }

        void GameFramework::ForceUpdateComponent(GameNode* node, float dt, uint timestamp)
        {
            if (node->GetComponent())
            {
                if (IUpdateable* updateableComponent = node->GetComponent()->QueryUpdateableInterface())
                    updateableComponent->Update(dt, timestamp);
            }

            const GameNode::NodeCollection& children = node->GetChildren();
            for (GameNode::NodeCollection::const_iterator it = children.begin(); it != children.end(); it++)
                ForceUpdateComponent(*it, dt, timestamp);
        }
    }

#endif