#pragma once
#ifndef __HALAK_DYNAMICTEXTURE2D_H__
#define __HALAK_DYNAMICTEXTURE2D_H__

#   include <Halak/FWD.h>
#   include <Halak/Texture2D.h>
#   include <Halak/SurfaceFormat.h>
#   include <Halak/Rectangle.h>

    namespace Halak
    {
        class DynamicTexture2D : public Texture2D
        {
            public:
                class Locker
                {
                    friend class DynamicTexture2D;

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
                };

            public:
                DynamicTexture2D(GraphicsDevice* graphicsDevice, int width, int height, SurfaceFormat::E format);
                virtual ~DynamicTexture2D();

                bool Lock(__Out Locker& locker);
                bool Lock(__Out Locker& locker, const Rectangle& rectangle);
                void Unlock(__Out Locker& locker);

                bool IsLocked() const;

                SurfaceFormat::E GetFormat() const;

            protected:
                virtual D3DTextureInfo CreateD3DTexture();

            private:
                int width;
                int height;
                SurfaceFormat::E format;
                bool isLocked;
        };
    }

#endif