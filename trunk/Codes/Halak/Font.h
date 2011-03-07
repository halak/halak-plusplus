#pragma once
#ifndef __HALAK_FONT_H__
#define __HALAK_FONT_H__

#   include <Halak/FWD.h>
#   include <Halak/Asset.h>
#   include <Halak/Color.h>
#   include <Halak/IRevisable.h>
#   include <vector>

    namespace Halak
    {
        class Font : public Asset, public IRevisable
        {
            public:
                Font(FreeType* freeType);
                Font(const Font& original);
                virtual ~Font();

                Vector2 Measure(const String& text);
                Vector2 Measure(const String& text, float boundary);
                Vector2 Measure(const FontString& fontString);
                Vector2 Measure(const FontString& fontString, float boundary);

                const String& GetFace() const;
                void SetFace(const String& value);

                float GetSize() const;
                void  SetSize(float value);

                float GetStrokeSize() const;
                void  SetStrokeSize(float value);

                float GetWeights() const;
                void  SetWeights(float value);

                bool GetBold() const;
                void SetBold(bool value);

                float GetShear() const;
                void  SetShear(float value);

                bool GetItalic() const;
                void SetItalic(bool value);

                float GetScale() const;
                void  SetScale(float value);

                bool GetHinting() const;
                void SetHinting(bool value);

                bool GetIgnoreBitmap() const;
                void SetIgnoreBitmap(bool value);

                Color GetColor() const;
                void  SetColor(Color value);

                Color GetStrokeColor() const;
                void  SetStrokeColor(Color value);

                float GetSpacing() const;
                void  SetSpacing(float value);

                FreeTypeFontRendererPtr GetRenderer() const;

                const Glyph* GetRegularGlyph(wchar_t code) const;
                const Glyph* GetStrokedGlyph(wchar_t code) const;

                float GetAscender() const;
                float GetDescender() const;
                float GetLineHeight() const;

                virtual uint GetRevision() const;

            private:
                FreeType* freeType;
                unsigned int revision;

                float spacing;
                Color color;
                Color strokeColor;
                FreeTypeFontRendererParameters* parametersPointer;
                FreeTypeFontRendererParameters& parameters;
                mutable FreeTypeFontRendererPtr renderer;
                mutable bool freeTypeFontRendererChanged;

            private:
                Font& operator = (const Font&);
        };
    }

#endif