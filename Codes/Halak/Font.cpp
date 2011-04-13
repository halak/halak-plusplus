#include <Halak/PCH.h>
#include <Halak/Font.h>
#include <Halak/Assert.h>
#include <Halak/FontString.h>
#include <Halak/FreeType.h>
#include <Halak/NumericLimits.h>
#include <Halak/String.h>
#include <Halak/Internal/FreeTypeFontRenderer.h>
#include <Halak/Internal/Glyph.h>
#include <Halak/Internal/GlyphTable.h>
#include <Halak/Internal/TypingContext.h>

namespace Halak
{
    Font::Font(FreeType* freeType)
        : freeType(freeType),
          revision(0),
          color(Color::Black),
          strokeColor(Color::Black),
          spacing(1.0f),
          parametersPointer(new FreeTypeFontRendererParameters()),
          parameters(*parametersPointer),
          freeTypeFontRendererChanged(true)
    {
        HKAssert(freeType);
    }

    Font::Font(const Font& original)
        : freeType(original.freeType),
          revision(original.revision),
          color(original.color),
          strokeColor(original.strokeColor),
          spacing(original.spacing),
          parametersPointer(new FreeTypeFontRendererParameters(original.parameters)),
          parameters(*parametersPointer),
          renderer(original.renderer),
          freeTypeFontRendererChanged(original.freeTypeFontRendererChanged)
    {
        HKAssert(freeType);
    }

    Font::~Font()
    {
        delete parametersPointer;
    }

    Vector2 Font::Measure(const String& text)
    {
        return Measure(text, NumericLimits::MaxFloat);
    }

    Vector2 Font::Measure(const String& text, float boundary)
    {
        return Measure(FontString(This<Font>(), text), boundary);
    }

    Vector2 Font::Measure(const FontString& fontString)
    {
        return Measure(fontString, NumericLimits::MaxFloat);
    }
    
    Vector2 Font::Measure(const FontString& fontString, float boundary)
    {
        HKAssert(fontString.GetFont().GetPointee() == this);

       TypingContext context(fontString, boundary);

        Vector2 result = Vector2::Zero;
        while (context.MoveNext())
        {
            const Vector2 current = context.GetPosition();
            result.X = std::max<float>(result.X, current.X + context.GetRegularGlyph()->GetAdvance().X);
            result.Y = std::max<float>(result.Y, current.Y + GetLineHeight());
        }

        return result;
    }

    const String& Font::GetFace() const
    {
        return parameters.Face;
    }

    void Font::SetFace(const String& value)
    {
        if (parameters.Face != value)
        {
            parameters.Face = value;
            freeTypeFontRendererChanged = true;
            revision++;
        }
    }

    float Font::GetSize() const
    {
        return parameters.FontSize;
    }

    void Font::SetSize(float value)
    {
        value = std::max<float>(value, 0.0f);
        if (parameters.FontSize != value)
        {
            parameters.FontSize = value;
            freeTypeFontRendererChanged = true;
            revision++;
        }
    }

    float Font::GetStrokeSize() const
    {
        return parameters.StrokeSize;
    }

    void Font::SetStrokeSize(float value)
    {
        value = std::max<float>(value, 0.0f);
        if (parameters.StrokeSize != value)
        {
            parameters.StrokeSize = value;
            freeTypeFontRendererChanged = true;
            revision++;
        }
    }

    float Font::GetWeights() const
    {
        return parameters.Weights;
    }

    void Font::SetWeights(float value)
    {
        value = std::max<float>(value, 0.0f);
        if (parameters.Weights != value)
        {
            parameters.Weights = value;
            freeTypeFontRendererChanged = true;
            revision++;
        }
    }

    bool Font::GetBold() const
    {
        return parameters.Weights > 0.0f;
    }

    void Font::SetBold(bool value)
    {
        if (GetBold() != value)
        {
            parameters.Weights = value ? 1.0f : 0.0f;
            freeTypeFontRendererChanged = true;
            revision++;
        }
    }

    float Font::GetShear() const
    {
        return parameters.Shear;
    }

    void Font::SetShear(float value)
    {
        value = std::max<float>(value, 0.0f);
        if (parameters.Shear != value)
        {
            parameters.Shear = value;
            freeTypeFontRendererChanged = true;
            revision++;
        }
    }

    bool Font::GetItalic() const
    {
        return parameters.Shear > 0.0f;
    }

    void Font::SetItalic(bool value)
    {
        if (GetItalic() != value)
        {
            parameters.Shear = value ? 0.2f : 0.0f;
            freeTypeFontRendererChanged = true;
            revision++;
        }
    }

    float Font::GetScale() const
    {
        return parameters.Scale;
    }

    void Font::SetScale(float value)
    {
        value = std::max<float>(value, 0.0f);
        if (parameters.Scale != value)
        {
            parameters.Scale = value;
            freeTypeFontRendererChanged = true;
            revision++;
        }
    }

    bool Font::GetHinting() const
    {
        return parameters.Hinting;
    }

    void Font::SetHinting(bool value)
    {
        if (parameters.Hinting != value)
        {
            parameters.Hinting = value;
            freeTypeFontRendererChanged = true;
            revision++;
        }
    }

    bool Font::GetIgnoreBitmap() const
    {
        return parameters.IgnoreBitmap;
    }

    void Font::SetIgnoreBitmap(bool value)
    {
        if (parameters.IgnoreBitmap != value)
        {
            parameters.IgnoreBitmap = value;
            freeTypeFontRendererChanged = true;
            revision++;
        }
    }

    Color Font::GetColor() const
    {
        return color;
    }

    void Font::SetColor(Color value)
    {
        if (color != value)
        {
            color = value;
            revision++;
        }
    }

    Color Font::GetStrokeColor() const
    {
        return strokeColor;
    }

    void Font::SetStrokeColor(Color value)
    {
        if (strokeColor != value)
        {
            strokeColor = value;
            revision++;
        }
    }

    float Font::GetSpacing() const
    {
        return spacing;
    }

    void Font::SetSpacing(float value)
    {
        value = std::max<float>(value, 0.0f);
        if (spacing != value)
        {
            spacing = value;
            revision++;
        }
    }

    FreeTypeFontRendererPtr Font::GetRenderer() const
    {
        if (freeTypeFontRendererChanged)
        {
            freeTypeFontRendererChanged = false;
            renderer = freeType->GetRenderer(parameters);
        }

        return renderer;
    }

    const Glyph* Font::GetRegularGlyph(wchar_t code) const
    {
        return GetRenderer()->GetGlyph(code);
    }

    const Glyph* Font::GetStrokedGlyph(wchar_t code) const
    {
        if (const GlyphTable* t = GetRenderer()->GetStrokedGlyphTable())
            return t->Find(code);
        else
            return nullptr;
    }

    float Font::GetAscender() const
    {
        return GetRenderer()->GetAscender();
    }

    float Font::GetDescender() const
    {
        return GetRenderer()->GetDescender();
    }

    float Font::GetLineHeight() const
    {
        return GetRenderer()->GetLineHeight();
    }

    uint Font::GetRevision() const
    {
        return revision;
    }
}