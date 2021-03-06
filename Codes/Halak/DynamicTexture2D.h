#pragma once
#ifndef __HALAK_DYNAMICTEXTURE2D_H__
#define __HALAK_DYNAMICTEXTURE2D_H__

#   include <Halak/FWD.h>
#   include <Halak/Texture2D.h>
#   include <Halak/Rectangle.h>

    namespace Halak
    {
        class DynamicTexture2D : public Texture2D
        {
            public:
                class Locker
                {
                    public:
                        Locker();
                        ~Locker();

                        void* GetBuffer();
                        int   GetPitch() const;

                    private:
                        void SetData(DynamicTexture2DPtr texture, void* buffer, int pitch);

                    private:
                        DynamicTexture2DPtr texture;
                        void* buffer;
                        int   pitch;

                    private:
                        Locker(const Locker&);
                        Locker& operator = (const Locker&);

                        friend class DynamicTexture2D;
                };

            public:
                DynamicTexture2D(GraphicsDevice* graphicsDevice, int width, int height, PixelFormat format);
                virtual ~DynamicTexture2D();

                bool Lock(Locker& outLocker);
                bool Lock(Locker& outLocker, const Rectangle& rectangle);
                void Unlock(Locker& outLocker);

                bool IsLocked() const;

                PixelFormat GetFormat() const;

            protected:
                virtual D3DTextureInfo CreateD3DTexture();

            private:
                int width;
                int height;
                PixelFormat format;
                bool isLocked;
        };
    }

#endif