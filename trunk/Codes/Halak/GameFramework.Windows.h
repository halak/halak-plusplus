#pragma once
#ifndef __HALAK_GAMEFRAMEWORK_WINDOWS_H__
#define __HALAK_GAMEFRAMEWORK_WINDOWS_H__

#   include <Halak/FWD.h>
#   include <Halak/IUpdateable.h>
#   include <Halak/IDrawable.h>
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
                    
                    inline IUpdateable* GetMainTimeline() const;
                    inline void SetMainTimeline(IUpdateable* value);

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

                private:
                    GameStructure* structure;
                    GameWindow* window;
                    GraphicsDevice* graphicsDevice;
                    IUpdateable* mainTimeline;

                    bool  fixedTimeStep;
                    float fixedElapsedTime;
                    float maxTimeInOneFrame;
                    std::deque<float> timestamps;
            };
        }

#       include <Halak/GameFramework.Windows.inl>

#   endif

#endif