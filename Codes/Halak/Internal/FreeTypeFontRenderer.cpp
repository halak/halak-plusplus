#include <Halak/Internal/FreeTypeFontRenderer.h>
#include <Halak/Internal/GlyphTable.h>
#include <Halak/Internal/Glyph.h>
#include <Halak/FreeType.h>

namespace Halak
{
    static FT_Matrix UnitMatrix = { 0x10000L, 0, 0, 0x10000L };
    static FT_Vector ZeroVector = { 0, 0 };

    // FreeType 26.6 실수계와 C++ float 좌표계를 상호 변환한다.
    // http://freetype.sourceforge.net/freetype2/docs/glyphs/glyphs-3.html
    static inline float F26D6ToFloat(FT_F26Dot6 value)
    {
        return static_cast<float>(value) / 64.0f;
    }

    static inline FT_F26Dot6 FloatToF26D6(float value)
    {
        return static_cast<FT_F26Dot6>(value * 64.0f);
    }

    static inline float F16D16ToFloat(FT_Fixed value)
    {
        return static_cast<float>(value) / 65536.0f;
    }

    static inline FT_Fixed FloatToF16D16(float value)
    {
        return static_cast<FT_F26Dot6>(value * 65536.0f);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    FreeTypeFontRendererParameters::FreeTypeFontRendererParameters()
        : Face(),
          FontSize(10.0f),
          StrokeSize(0.0f),
          Weights(0.0f),
          Shear(0.0f),
          Scale(1.0f),
          Hinting(true),
          IgnoreBitmap(false)
    {
    }

    FreeTypeFontRendererParameters::FreeTypeFontRendererParameters(const String& face, float size)
        : Face(face),
          FontSize(size),
          StrokeSize(0.0f),
          Weights(0.0f),
          Shear(0.0f),
          Scale(1.0f),
          Hinting(true),
          IgnoreBitmap(false)
    {
    }

    FreeTypeFontRendererParameters::FreeTypeFontRendererParameters(const String& face, float fontSize, float strokeSize, float weights, float shear, float scale, bool hinting, bool ignoreBitmap)
        : Face(face),
          FontSize(fontSize),
          StrokeSize(strokeSize),
          Weights(weights),
          Shear(shear),
          Scale(scale),
          Hinting(hinting),
          IgnoreBitmap(ignoreBitmap)
    {
    }

    FreeTypeFontRendererParameters::FreeTypeFontRendererParameters(const String& face, float fontSize, float strokeSize, bool bold, bool italic, float scale, bool hinting, bool ignoreBitmap)
        : Face(face),
          FontSize(fontSize),
          StrokeSize(strokeSize),
          Weights(bold ? 1.0f : 0.0f),
          Shear(italic ? 1.0f : 0.0f),
          Scale(scale),
          Hinting(hinting),
          IgnoreBitmap(ignoreBitmap)
    {
    }

    unsigned int FreeTypeFontRendererParameters::GetHashCode() const
    {
        unsigned int result = 0;
        result += Face.GetLength() * 65536;
        result += static_cast<unsigned int>(FontSize * 64.0f);
        result += static_cast<unsigned int>(StrokeSize * 64.0f);
        result += static_cast<unsigned int>(Weights * 64.0f);
        result += static_cast<unsigned int>(Shear * 64.0f);
        result += static_cast<unsigned int>(Scale * 64.0f);
        result += Hinting      ? 0x08000000 : 0;
        result += IgnoreBitmap ? 0x00800000 : 0;
        return result;
    }

    bool FreeTypeFontRendererParameters::operator == (const FreeTypeFontRendererParameters& right) const
    {
        return Face == right.Face &&
               FloatToF26D6(FontSize)   == FloatToF26D6(right.FontSize) &&
               FloatToF26D6(StrokeSize) == FloatToF26D6(right.StrokeSize) &&
               FloatToF26D6(Weights)    == FloatToF26D6(right.Weights) &&
               FloatToF16D16(Shear)     == FloatToF16D16(right.Shear) &&
               FloatToF26D6(Scale)      == FloatToF26D6(right.Scale) &&
               Hinting == right.Hinting &&
               IgnoreBitmap == right.IgnoreBitmap;
    }

    bool FreeTypeFontRendererParameters::operator != (const FreeTypeFontRendererParameters& right) const
    {
        return !operator == (right);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    FreeTypeFontRenderer::FreeTypeFontRenderer(FreeType* freeType, const FreeTypeFontRendererParameters& parameters)
        : freeType(freeType),
          parameters(parameters),
          primaryFace(nullptr),
          alternativeFace(nullptr),
          stroker(nullptr),
          transform(UnitMatrix),
          ascender(0.0f),
          descender(0.0f),
          lineHeight(0.0f),
          regularGlyphTable(nullptr),
          strokedGlyphTable(nullptr)
    {
        String faceFilename = parameters.Face;
        int    faceIndex    = 0; // *.ttc 파일일 경우 폰트가 존재하는 위치 (TTC = TrueTypeCollection)

        int separatorIndex = parameters.Face.ReverseFind('?');
        if (separatorIndex != -1)
        {
            faceFilename = parameters.Face.Substring(0, separatorIndex);
            faceIndex    = atoi(parameters.Face.Substring(separatorIndex + 1).CStr());
        }

        if (FT_Error error = FT_New_Face(static_cast<FT_Library>(freeType->GetLibrary()), faceFilename.CStr(), faceIndex, &primaryFace))
        {
            const String newFaceFilepath = freeType->GetOSFontDirectory() + faceFilename;
            if (FT_New_Face(static_cast<FT_Library>(freeType->GetLibrary()), newFaceFilepath.CStr(), faceIndex, &primaryFace))
            {
                // ERROR 처리 (return하지는 않음)
            }
        }

        if (FT_Error error = FT_New_Face(static_cast<FT_Library>(freeType->GetLibrary()), freeType->GetAlternativeFace().CStr(), 0, &alternativeFace))
        {
            // ERROR 처리 (return하지는 않음)
        }

        const FT_F26Dot6 scaledFontSize = FloatToF26D6(parameters.FontSize * parameters.Scale);

        if (primaryFace)
            FT_Set_Char_Size(primaryFace, 0, scaledFontSize, 96, 96);
        if (alternativeFace)
            FT_Set_Char_Size(alternativeFace, 0, scaledFontSize, 96, 96);

        if (parameters.StrokeSize > 0.0f)
        {
            if (FT_Error error = FT_Stroker_New(static_cast<FT_Library>(freeType->GetLibrary()), &stroker))
            {
                // ERROR 처리
            }

            const FT_F26Dot6 scaledStrokeSize = FloatToF26D6(parameters.StrokeSize * parameters.Scale);

            if (stroker)
                FT_Stroker_Set(stroker, scaledStrokeSize, FT_STROKER_LINECAP_BUTT, FT_STROKER_LINEJOIN_ROUND, 0);
        }

        if (parameters.Shear != 0.0f)
        {
            transform.xx = FloatToF16D16(1.0f);
            transform.xy = FloatToF16D16(parameters.Shear);
            transform.yx = FloatToF16D16(0.0f);
            transform.yy = FloatToF16D16(1.0f);
        }

        const FT_Face metricsFont = primaryFace ? primaryFace : alternativeFace;
        const FT_Size_Metrics& metrics = metricsFont->size->metrics;
        ascender   = F26D6ToFloat(metrics.ascender) / parameters.Scale;
        descender  = F26D6ToFloat(metrics.descender) / parameters.Scale;
        lineHeight = F26D6ToFloat(metrics.height) / parameters.Scale;

        regularGlyphTable = new GlyphTable(freeType->GetGraphicsDevice());

        if (stroker)
            strokedGlyphTable = new GlyphTable(freeType->GetGraphicsDevice());
    }

    FreeTypeFontRenderer::~FreeTypeFontRenderer()
    {
        delete strokedGlyphTable;
        delete regularGlyphTable;

        if (stroker)
            FT_Stroker_Done(stroker);
        if (alternativeFace)
            FT_Done_Face(alternativeFace);
        if (primaryFace)
            FT_Done_Face(primaryFace);
    }

    const Glyph* FreeTypeFontRenderer::GetGlyph(wchar_t code)
    {
        if (const Glyph* result = regularGlyphTable->Find(code))
            return result;
        else
        {
            struct SelectFace
            {
                // 두 Face에서 Code를 찾아서 반환합니다.
                static std::pair<FT_Face, unsigned int> Do(FT_Face primary, FT_Face alternative, wchar_t code)
                {
                    if (primary)
                    {
                        const unsigned int index = FT_Get_Char_Index(primary, code);
                        if (index != 0)
                            return std::pair<FT_Face, unsigned int>(primary, index);
                    }

                    if (alternative)
                    {
                        const unsigned int index = FT_Get_Char_Index(alternative, code);
                        if (index != 0)
                            return std::pair<FT_Face, unsigned int>(alternative, index);
                    }

                    return std::pair<FT_Face, unsigned int>(nullptr, 0);
                }
            };

            // Grayscale을 보장하는 Bitmap 구조체.
            // 원본 Bitmap이 8bpp라면 그대로 보관하고,
            // 만약 8pp가 아니라면 8pp로 변환합니다.
            // 새로이 생성된 Bitmap은 자동으로 삭제됩니다.
            struct GrayscaleBitmap
            {
                FT_Library Library;
                FT_Bitmap* Bitmap;
                bool isNewBitmap;

                GrayscaleBitmap(FT_Library library, FT_Bitmap& source)
                    : Library(library)
                {
                    if (source.pixel_mode == FT_PIXEL_MODE_GRAY)
                    {
                        Bitmap = &source;
                        isNewBitmap = false;
                    }
                    else
                    {
                        Bitmap = new FT_Bitmap();
                        FT_Bitmap_Convert(Library, &source, Bitmap, 8);
                        isNewBitmap = true;

                        const byte scale = static_cast<byte>(255 / (Bitmap->num_grays - 1));
                        byte* destination = static_cast<byte*>(Bitmap->buffer);
                        for (int y = 0; y < Bitmap->rows; y++)
                        {
                            for (int x = 0; x < Bitmap->width; x++)
                            {
                                destination[x] *= scale;
                            }
                            destination += Bitmap->pitch;
                        }
                    }
                }

                ~GrayscaleBitmap()
                {
                    if (isNewBitmap)
                    {
                        FT_Bitmap_Done(Library, Bitmap);
                        delete Bitmap;
                    }
                }
            };

            std::pair<FT_Face, unsigned int> faceGlyphIndex = SelectFace::Do(primaryFace, alternativeFace, code);
            if (faceGlyphIndex.first == nullptr)
                faceGlyphIndex = SelectFace::Do(primaryFace, alternativeFace, L'?');

            FT_Int32 loadFlags = FT_LOAD_DEFAULT;
            if (parameters.IgnoreBitmap)
                loadFlags |= FT_LOAD_NO_BITMAP;
            if (parameters.Hinting == false)
                loadFlags |= FT_LOAD_NO_HINTING;
            
            FT_Set_Transform(faceGlyphIndex.first, &transform, &ZeroVector);

            if (parameters.StrokeSize > 0.0f)
            {
                FT_Error result = 0;
                FT_Glyph strokedGlyph = nullptr;
                FT_Load_Glyph(faceGlyphIndex.first, faceGlyphIndex.second, loadFlags | FT_LOAD_NO_BITMAP);
                FT_Get_Glyph(faceGlyphIndex.first->glyph, &strokedGlyph);
                if (FT_Glyph_Stroke(&strokedGlyph, stroker, 1) == 0)
                {
                    result = FT_Glyph_To_Bitmap(&strokedGlyph, FT_RENDER_MODE_NORMAL, nullptr, 1);

                    FT_BitmapGlyph strokedGlyphBitmap = reinterpret_cast<FT_BitmapGlyph>(strokedGlyph);

                    if (parameters.Weights > 0.0f)
                        FT_Bitmap_Embolden(static_cast<FT_Library>(freeType->GetLibrary()), &strokedGlyphBitmap->bitmap, FloatToF26D6(parameters.Weights), 0);

                    GrayscaleBitmap glyphBitmap(static_cast<FT_Library>(freeType->GetLibrary()), strokedGlyphBitmap->bitmap);

                    const Vector2 advance = Vector2(F16D16ToFloat(strokedGlyph->advance.x), F16D16ToFloat(strokedGlyph->advance.y));
                    const Vector2 bitmapOffset = Vector2(static_cast<float>(strokedGlyphBitmap->left), GetAscender() - static_cast<float>(strokedGlyphBitmap->top));
                    const Vector2 bitmapSize   = Vector2(glyphBitmap.Bitmap->width, glyphBitmap.Bitmap->rows);
                    strokedGlyphTable->Add(code,
                                           advance, bitmapOffset / parameters.Scale, bitmapSize / parameters.Scale,
                                           glyphBitmap.Bitmap->buffer,
                                           glyphBitmap.Bitmap->width,
                                           glyphBitmap.Bitmap->rows,
                                           glyphBitmap.Bitmap->pitch);
                }
                FT_Done_Glyph(strokedGlyph);
            }

            FT_Load_Glyph(faceGlyphIndex.first, faceGlyphIndex.second, loadFlags);
            FT_Render_Glyph(faceGlyphIndex.first->glyph, FT_RENDER_MODE_NORMAL);

            if (parameters.Weights > 0.0f)
                FT_Bitmap_Embolden(static_cast<FT_Library>(freeType->GetLibrary()), &faceGlyphIndex.first->glyph->bitmap, FloatToF26D6(parameters.Weights), 0);

            GrayscaleBitmap glyphBitmap(static_cast<FT_Library>(freeType->GetLibrary()), faceGlyphIndex.first->glyph->bitmap);

            FT_GlyphSlot renderedGlyph = faceGlyphIndex.first->glyph;
            const Vector2 advance = Vector2(F26D6ToFloat(renderedGlyph->advance.x), F26D6ToFloat(renderedGlyph->advance.y));
            const Vector2 bitmapOffset = Vector2(static_cast<float>(renderedGlyph->bitmap_left), GetAscender() - static_cast<float>(renderedGlyph->bitmap_top));
            const Vector2 bitmapSize   = Vector2(glyphBitmap.Bitmap->width, glyphBitmap.Bitmap->rows);

            return regularGlyphTable->Add(code,
                                          advance / parameters.Scale, bitmapOffset / parameters.Scale, bitmapSize / parameters.Scale,
                                          glyphBitmap.Bitmap->buffer,
                                          glyphBitmap.Bitmap->width,
                                          glyphBitmap.Bitmap->rows,
                                          glyphBitmap.Bitmap->pitch);
        }
    }

    FreeType* FreeTypeFontRenderer::GetFreeType() const
    {
        return freeType;
    }

    const FreeTypeFontRendererParameters& FreeTypeFontRenderer::GetParameters() const
    {
        return parameters;
    }

    float FreeTypeFontRenderer::GetAscender() const
    {
        return ascender;
    }

    float FreeTypeFontRenderer::GetDescender() const
    {
        return descender;
    }

    float FreeTypeFontRenderer::GetLineHeight() const
    {
        return lineHeight;
    }

    const GlyphTable* FreeTypeFontRenderer::GetRegularGlyphTable() const
    {
        return regularGlyphTable;
    }

    const GlyphTable* FreeTypeFontRenderer::GetStrokedGlyphTable() const
    {
        return strokedGlyphTable;
    }
}