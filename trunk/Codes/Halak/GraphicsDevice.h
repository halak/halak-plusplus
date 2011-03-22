#pragma once
#ifndef __HALAK_GRAPHICSDEVICE_H__
#define __HALAK_GRAPHICSDEVICE_H__

#   include <Halak/FWD.h>
#   include <Halak/Color.h>
#   include <Halak/Rectangle.h>
#   include <Halak/GameComponent.h>
#   include <vector>
#   include <d3d9.h>

namespace Halak
{
    class GraphicsDevice : public GameComponent
    {
        HKDeclareGameComponentClassFOURCC('G', 'R', 'P', 'D');
        public:
            GraphicsDevice();
            virtual ~GraphicsDevice();

            void Clear();
            void Clear(Color color);

            void BeginDraw();
            void EndDraw();
            void Present();

            Window* GetWindow() const;
            void SetWindow(Window* value);

            bool GetFullscreen() const;
            void SetFullscreen(bool value);

            const Rectangle& GetViewport() const;
            void SetViewport(const Rectangle& value);

            DisplaySwapChain* GetDefaultSwapChain();

            IDirect3D9*       GetD3DObject();
            IDirect3DDevice9* GetD3DDevice();

        private:
            void InitializeDevice();
            void FinalizeDevice();

            void AcquireDefaultSwapChain();

            void Add(DisplaySwapChain* item);
            void Remove(DisplaySwapChain* item);

        private:
            IDirect3D9*       d3dObject;
            IDirect3DDevice9* d3dDevice;
            Window* window;

            DisplaySwapChain* defaultSwapChain;
            std::vector<DisplaySwapChain*> swapChains;

            Rectangle viewport;
            bool fullscreen;

            friend class DisplaySwapChain;
    };
}

#endif