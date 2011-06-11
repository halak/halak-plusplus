#include <Halak/PCH.h>
#include <Halak/UIRenderer.Windows.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

    namespace Halak
    {
        UIRenderer::UIRenderer()
            : graphicsDevice(nullptr)
        {
        }

        UIRenderer::UIRenderer(GraphicsDevice* graphicsDevice)
            : graphicsDevice(graphicsDevice)
        {
        }

        UIRenderer::~UIRenderer()
        {
        }

        void UIRenderer::SetGraphicsDevice(GraphicsDevice* value)
        {
            graphicsDevice = value;
        }
    }

#endif