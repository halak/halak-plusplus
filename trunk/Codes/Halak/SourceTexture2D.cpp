#include <Halak/SourceTexture2D.h>
#include <Halak/GraphicsDevice.h>

namespace Halak
{
    SourceTexture2D::SourceTexture2D(GraphicsDevice* graphicsDevice, const String& filename)
        : Texture2D(graphicsDevice),
          filename(filename)
    {
    }

    SourceTexture2D::~SourceTexture2D()
    {
    }

    void SourceTexture2D::Reload()
    {
        SetTextureChanged(true);
    }

    const String& SourceTexture2D::GetFilename() const
    {
        return filename;
    }

    Texture2D::D3DTextureInfo SourceTexture2D::CreateD3DTexture()
    {
        D3DXIMAGE_INFO imageInfo = { 0, };

        IDirect3DTexture9* newD3DTexture = NULL;
        HRESULT result = D3DXCreateTextureFromFileEx(GetGraphicsDevice()->GetD3DDevice(),
                                                     filename.CStr(), D3DX_DEFAULT, D3DX_DEFAULT, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT, D3DCOLOR_ARGB(0, 0, 0, 0), &imageInfo, nullptr, &newD3DTexture);

        if (result == D3D_OK)
        {
            D3DSURFACE_DESC surfaceDesc;
            if (newD3DTexture->GetLevelDesc(0, &surfaceDesc) == D3D_OK)
            {
                return D3DTextureInfo(newD3DTexture,
                                      static_cast<int>(imageInfo.Width), static_cast<int>(imageInfo.Height),
                                      static_cast<int>(surfaceDesc.Width), static_cast<int>(surfaceDesc.Height));
            }
            else
                return D3DTextureInfo(newD3DTexture, static_cast<int>(imageInfo.Width), static_cast<int>(imageInfo.Height));
        }
        else
            return D3DTextureInfo();
    }
}