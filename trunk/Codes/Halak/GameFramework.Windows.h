#pragma once
#ifndef __HALAK_GAMEFRAMEWORK_WINDOWS_H__
#define __HALAK_GAMEFRAMEWORK_WINDOWS_H__

#   include <Halak/FWD.h>
#   include <Halak/IDrawable.h>
#   include <Halak/IUpdateable.h>
#   include <deque>

#   if (defined(HALAK_PLATFORM_WINDOWS))

        namespace Halak
        {
            class GameFramework : public IUpdateable
            {
                public:
                    virtual ~GameFramework();

                    void Run();

                    inline GameStructure*  GetStructure() const;
                    inline GameWindow*     GetWindow() const;
                    inline GraphicsDevice* GetGraphicsDevice() const;
                    inline Timeline*       GetMainTimeline() const;

                    inline bool GetFixedTimeStep() const;
                           void SetFixedTimeStep(bool value);

                    inline float GetFixedElapsedTime() const;
                           void  SetFixedElapsedTime(float value);

                    inline float GetMaxTimeInOneFrame() const;
                           void  SetMaxTimeInOneFrame(float value);

                    float GetFPS() const;

                protected:
                    GameFramework();

                    virtual void Initialize();
                    virtual void Finalize();

                    virtual void Update(float dt, uint timestamp);
                    virtual void Draw();

                    virtual void BeginDraw();
                    virtual void EndDraw();

                    void ForceUpdateAllComponents(float dt, uint timestamp);

                private:
                    static void ForceUpdateComponent(GameNode* node, float dt, uint timestamp);

                private:
                    GameStructure* structure;
                    GameWindow* window;
                    GraphicsDevice* graphicsDevice;
                    Timeline* mainTimeline;

                    bool  fixedTimeStep;
                    float fixedElapsedTime;
                    float maxTimeInOneFrame;
                    uint  desiredFPS;
                    std::deque<float> timestamps;
            };
        }

#       include <Halak/GameFramework.Windows.inl>

#   endif

#endif