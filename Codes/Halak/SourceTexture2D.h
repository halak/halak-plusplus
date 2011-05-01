#pragma once
#ifndef __HALAK_SOURCETEXTURE2D_H__
#define __HALAK_SOURCETEXTURE2D_H__

#   include <Halak/FWD.h>
#   include <Halak/Texture2D.h>
#   include <Halak/IReloadable.h>

    namespace Halak
    {
        class SourceTexture2D : public Texture2D, public IReloadable
        {
            public:
                SourceTexture2D(GraphicsDevice* graphicsDevice, const URI& uri);
                virtual ~SourceTexture2D();

                virtual void Reload();

                virtual const URI& GetURI() const;

            protected:
                virtual Texture2D::D3DTextureInfo CreateD3DTexture();

            private:
                URI uri;
        };
    }

#endif