#pragma once
#ifndef __HALAK_UIRENDERER_WINDOWS_H__
#define __HALAK_UIRENDERER_WINDOWS_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        class UIRenderer : public GameComponent
        {
            HKClassFOURCC('U', 'I', 'R', 'R');
            public:
                UIRenderer();
                UIRenderer(GraphicsDevice* graphicsDevice);
                virtual ~UIRenderer();

                inline GraphicsDevice* GetGraphicsDevice() const;
                void SetGraphicsDevice(GraphicsDevice* value);

            private:
                GraphicsDevice* graphicsDevice;
        };
    }

#   include <Halak/UIRenderer.Windows.inl>

#endif