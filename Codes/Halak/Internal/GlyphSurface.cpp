#include <Halak/PCH.h>
#include <Halak/Internal/GlyphSurface.h>
#include <Halak/DynamicTexture2D.h>
#include <Halak/RectangleStorage.h>

namespace Halak
{
    GlyphSurface::GlyphSurface(GraphicsDevice* graphicsDevice, int width, int height)
        : storage(new RectangleStorage(width, height)),
          texture(new DynamicTexture2D(graphicsDevice, width, height, Texture2D::A8Pixels))
    {
    }

    GlyphSurface::~GlyphSurface()
    {
        delete storage;
    }

    Rectangle GlyphSurface::Allocate(const void* buffer, int width, int height, int pitch)
    {
        // Texture Filtering의 이유로 외곽 1Pixel씩을 비워둡니다.
        Rectangle allocatedRectangle = storage->Allocate(width + 2, height + 2);
        if (allocatedRectangle != Rectangle::Empty)
        {
            DynamicTexture2D::Locker locker;
            if (texture->Lock(locker, allocatedRectangle))
            {
                // 비워둔 외곽을 투명한 Pixel로 채웁니다.
                {
                    byte* destination = static_cast<byte*>(locker.GetBuffer());
                    const int destinationPitch = locker.GetPitch() / sizeof(*destination);

                    for (int x = 0; x < allocatedRectangle.Width; x++)
                        destination[x] = 0x00;

                    destination += destinationPitch;
                    const int yFirst = 1;
                    const int yLast  = allocatedRectangle.Height - 1;
                    const int xFirst = 0;
                    const int xLast  = allocatedRectangle.Width - 1;
                    for (int y = yFirst; y < yLast; y++)
                    {
                        destination[xFirst] = 0x00;
                        destination[xLast]  = 0x00;
                        destination += destinationPitch;
                    }

                    for (int x = 0; x < allocatedRectangle.Width; x++)
                        destination[x] = 0x00;
                }

                // 문자를 기록합니다.
                {
                    byte* destination = static_cast<byte*>(locker.GetBuffer());
                    const int destinationPitch = locker.GetPitch() / sizeof(*destination);
                    const byte* source = static_cast<const byte*>(buffer);
                    const int sourcePitch = pitch;

                    destination += destinationPitch; // y로 한 Step.
                    destination += 1;                // x로 한 Step.
                    for (int y = 0; y < height; ++y)
                    {
                        for (int x = 0; x < width; ++x)
                        {
                            destination[x] = source[x];
                        }
                        destination += destinationPitch;
                        source += sourcePitch;
                    }
                }

                texture->Unlock(locker);
            }

            return Rectangle(allocatedRectangle.X + 1, allocatedRectangle.Y + 1,
                             allocatedRectangle.Width - 2, allocatedRectangle.Height - 2);
        }
        else
            return Rectangle::Empty;
    }

    void GlyphSurface::Deallocate(const Rectangle& rectangle)
    {
        storage->Deallocate(rectangle);
    }

    const RectangleStorage& GlyphSurface::GetStorage() const
    {
        return *storage;
    }

    Texture2D* GlyphSurface::GetTexture() const
    {
        return texture;
    }
}