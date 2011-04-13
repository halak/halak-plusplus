#include <Halak/PCH.h>
#include <Halak/Internal/GlyphTable.h>
#include <Halak/Internal/GlyphSurface.h>
#include <Halak/Internal/Glyph.h>
#include <Halak/Assert.h>

namespace Halak
{
    GlyphTable::GlyphTable(GraphicsDevice* graphicsDevice)
        : graphicsDevice(graphicsDevice)
    {
        glyphs.insert(GlyphDictionary::value_type(L'\0', new Glyph(L'\0', Vector2(1.0f, 0.0f))));
        glyphs.insert(GlyphDictionary::value_type(L'\r', new Glyph(L'\r', Vector2(1.0f, 0.0f))));
        glyphs.insert(GlyphDictionary::value_type(L'\n', new Glyph(L'\n', Vector2(1.0f, 0.0f))));
    }

    GlyphTable::~GlyphTable()
    {
        Clear();
    }

    const Glyph* GlyphTable::Add(wchar_t code, Vector2 advance, Vector2 bitmapOffset, Vector2 bitmapSize, const void* buffer, int width, int height, int pitch)
    {
        std::pair<GlyphSurface*, Rectangle> allocated = AllocateSurface(buffer, width, height, pitch);
        Glyph* newGlyph = nullptr;
        if (allocated.first)
            newGlyph = new Glyph(code, advance, bitmapOffset, bitmapSize, allocated.first, allocated.second);
        else
            newGlyph = new Glyph(code, advance);

        GlyphDictionary::iterator it = glyphs.find(code);
        if (it != glyphs.end())
        {
            const Glyph* oldGlyph = (*it).second;
            (*it).second = newGlyph;
            delete oldGlyph;
        }
        else
        {
            if (glyphs.insert(GlyphDictionary::value_type(code, newGlyph)).second == false)
            {
                delete newGlyph;
                newGlyph = nullptr;
            }
        }

        return newGlyph;
    }

    bool GlyphTable::Remove(wchar_t code)
    {
        GlyphDictionary::const_iterator it = glyphs.find(code);
        if (it != glyphs.end())
        {
            const Glyph* glyph = (*it).second;
            glyphs.erase(it);
            delete glyph;
            return true;
        }
        else
            return false;
    }

    void GlyphTable::Clear()
    {
        GlyphDictionary deletingGlyphs;
        deletingGlyphs.swap(glyphs);

        for (GlyphDictionary::iterator it = deletingGlyphs.begin(); it != deletingGlyphs.end(); it++)
        {
            delete (*it).second;
        }

        SurfaceCollection deletingSurfaces;
        deletingSurfaces.swap(surfaces);

        for (SurfaceCollection::iterator it = deletingSurfaces.begin(); it != deletingSurfaces.end(); it++)
        {
            delete (*it);
        }
    }

    const Glyph* GlyphTable::Find(wchar_t code) const
    {
        GlyphDictionary::const_iterator it = glyphs.find(code);
        if (it != glyphs.end())
            return (*it).second;
        else
            return nullptr;
    }

    const GlyphTable::SurfaceCollection& GlyphTable::GetSurfaces() const
    {
        return surfaces;
    }

    std::pair<GlyphSurface*, Rectangle> GlyphTable::AllocateSurface(const void* buffer, int width, int height, int pitch)
    {
        if (buffer == nullptr || width <= 0 || height <= 0)
            return std::pair<GlyphSurface*, Rectangle>(nullptr, Rectangle::Empty);

        for (SurfaceCollection::iterator it = surfaces.begin(); it != surfaces.end(); ++it)
        {
            Rectangle allocated = (*it)->Allocate(buffer, width, height, pitch);
            if (allocated != Rectangle::Empty)
                return std::pair<GlyphSurface*, Rectangle>(*it, allocated);
        }

        const Point surfaceSize = GetAdaptiveSurfaceSize(surfaces.size(), width, height);
        HKAssert(surfaceSize != Point::Zero);

        GlyphSurface* glyphSurface = new GlyphSurface(graphicsDevice, surfaceSize.X, surfaceSize.Y);
        Rectangle allocated = glyphSurface->Allocate(buffer, width, height, pitch);
        HKAssert(allocated != Rectangle::Empty);

        surfaces.push_back(glyphSurface);

        return std::pair<GlyphSurface*, Rectangle>(glyphSurface, allocated);
    }

    Point GlyphTable::GetAdaptiveSurfaceSize(int numberOfExisting, int width, int height)
    {
        static const Point textureSizes[] =
        {
            Point(128, 128),
            Point(256, 256),
            Point(256, 256),
            Point(512, 512),
            Point(512, 512),
            Point(1024, 512),
            Point(1024, 1024)
        };
        static const int lastTextureSizeIndex = sizeof(textureSizes) / sizeof(textureSizes[0]) - 1;

        const int   index = std::min<int>(numberOfExisting, lastTextureSizeIndex);
        const Point selectedSize = textureSizes[index];
        if (selectedSize.X >= width && selectedSize.Y >= height)
            return selectedSize;
        else
        {
            // ���� �Ҵ��Ϸ��� �ؽ����� ũ�Ⱑ �۸��� ũ�⺸�� ������,
            // ���� �ؽ����� ũ�⸦ �Ҵ��Ѵ�. ���� �ְ� �ؽ��� ũ�⺸�� ũ�ٸ� Point::Zero�� ��ȯ�Ѵ�. (���� ��Ȳ��)
            if (numberOfExisting < lastTextureSizeIndex)
                return GetAdaptiveSurfaceSize(numberOfExisting + 1, width, height);
            else
                return Point::Zero;
        }
    }
}