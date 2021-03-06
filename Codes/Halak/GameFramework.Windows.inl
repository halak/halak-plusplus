namespace Halak
{
    GameStructure* GameFramework::GetStructure() const
    {
        return structure;
    }

    GameWindow* GameFramework::GetWindow() const
    {
        return window;
    }

    GraphicsDevice* GameFramework::GetGraphicsDevice() const
    {
        return graphicsDevice;
    }

    Timeline* GameFramework::GetMainTimeline() const
    {
        return mainTimeline;
    }

    bool GameFramework::GetFixedTimeStep() const
    {
        return fixedTimeStep;
    }

    float GameFramework::GetFixedElapsedTime() const
    {
        return fixedElapsedTime;
    }

    float GameFramework::GetMaxTimeInOneFrame() const
    {
        return maxTimeInOneFrame;
    }
}