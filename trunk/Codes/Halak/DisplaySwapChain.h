#pragma once
#ifndef __HALAK_DISPLAYSWAPCHAIN_H__
#define __HALAK_DISPLAYSWAPCHAIN_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class DisplaySwapChain : public GameComponent
        {
            HKClassFOURCC('S', 'W', 'C', 'H');
            public:
                DisplaySwapChain(GraphicsDevice* graphicsDevice, Window* window);
                DisplaySwapChain(GraphicsDevice* graphicsDevice, Window* window, Point size);
                virtual ~DisplaySwapChain();

                void BeginDraw();
                void EndDraw();
                void Present();

                GraphicsDevice* GetGraphicsDevice() const;
                Window* GetWindow() const;

                Point GetBackbufferSize() const;

                const Rectangle& GetViewport() const;
                void SetViewport(const Rectangle& value);

            protected:
                DisplaySwapChain(GraphicsDevice* graphicsDevice, Window* window, void* swapChainInterface);

                void Construct(Window* window, Point size);

            private:
                struct Fields;
                Fields* mPointer;
                Fields& m;

                friend class GraphicsDevice;
        };
    }

#endif