#include <Halak/PCH.h>
#include <Halak/FreeType.h>
#include <Halak/Internal/FreeTypeFontRenderer.h>
#include <vector>
#include <windows.h>

namespace Halak
{
    struct FreeType::Fields
    {
        FT_Library library;
    };

    FreeType::FreeType(GraphicsDevice* graphicsDevice)
        : graphicsDevice(graphicsDevice),
          m(new Fields())
    {
        FT_Init_FreeType(&m->library);

        std::vector<char> windowsDirectory;
        windowsDirectory.resize(GetWindowsDirectory(NULL, 0) + 1, '\0');
        GetWindowsDirectory(&windowsDirectory[0], windowsDirectory.size());
        osFontDirectory = &windowsDirectory[0];
        osFontDirectory += "\\Fonts\\";

        alternativeFace = osFontDirectory + "gulim.ttc";
    }

    FreeType::~FreeType()
    {
        renderers.clear();
        FT_Done_FreeType(m->library);
        delete m;
    }

    GraphicsDevice* FreeType::GetGraphicsDevice() const
    {
        return graphicsDevice;
    }

    const String& FreeType::GetOSFontDirectory() const
    {
        return osFontDirectory;
    }

    const String& FreeType::GetAlternativeFace() const
    {
        return alternativeFace;
    }

    FreeTypeFontRendererPtr FreeType::GetRenderer(const FreeTypeFontRendererParameters& parameters)
    {
        const unsigned int hashCode = parameters.GetHashCode();
        for (RendererCollection::iterator it = renderers.begin(); it != renderers.end(); it++)
        {
            if ((*it).first == hashCode &&
                (*it).second->GetParameters() == parameters)
                return (*it).second;
        }

        renderers.push_back(RendererCollection::value_type(parameters.GetHashCode(), FreeTypeFontRendererPtr(new FreeTypeFontRenderer(this, parameters))));
        return renderers.back().second;
    }

    void* FreeType::GetLibrary() const
    {
        return static_cast<void*>(m->library);
    }
}