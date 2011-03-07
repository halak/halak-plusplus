#include <Halak/Color.h>
#include <Halak/Assert.h>
#include <algorithm>
#include <sstream>

namespace Halak
{
    byte Color::Clamp(int value)
    {
        return value < 0 ? 0 : (value > 255 ? 255 : static_cast<byte>(value));
    }

    byte Color::Clamp(float value)
    {
        return value < 0.0f ? 0 : (value > 255.0f ? 255 : static_cast<byte>(value));
    }

    Color::Color()
        : R(0), G(0), B(0), A(0)
    {
    }

    Color::Color(int r, int g, int b)
        : R(Clamp(r)), G(Clamp(g)), B(Clamp(b)), A(255)
    {
    }

    Color::Color(int r, int g, int b, int a)
        : R(Clamp(r)), G(Clamp(g)), B(Clamp(b)), A(Clamp(a))
    {
    }

    Color::Color(unsigned long argb)
        : R(static_cast<byte>((argb & 0x00FF0000) >> 16)),
          G(static_cast<byte>((argb & 0x0000FF00) >> 8)),
          B(static_cast<byte>((argb & 0x000000FF) >> 0)),
          A(static_cast<byte>((argb & 0xFF000000) >> 24))
    {
    }

    Color::Color(const Vector3& rgb)
        : R(Clamp(rgb.X * 255.0f)),
          G(Clamp(rgb.Y * 255.0f)),
          B(Clamp(rgb.Z * 255.0f)),
          A(255)
    {
    }

    Color::Color(const Vector4& rgba)
        : R(Clamp(rgba.X * 255.0f)),
          G(Clamp(rgba.Y * 255.0f)),
          B(Clamp(rgba.Z * 255.0f)),
          A(Clamp(rgba.W * 255.0f))
    {
    }

    Color::Color(const Color& original)
        : R(original.R), G(original.G), B(original.B), A(original.A)
    {
    }

    Vector3 Color::ToVector3() const
    {
        return Vector3(static_cast<float>(R) / 255.0f, static_cast<float>(G) / 255.0f, static_cast<float>(B) / 255.0f);
    }

    Vector4 Color::ToVector4() const
    {
        return Vector4(static_cast<float>(R) / 255.0f, static_cast<float>(G) / 255.0f, static_cast<float>(B) / 255.0f, static_cast<float>(A) / 255.0f);
    }

    unsigned long Color::ToRGBA() const
    {
        return (static_cast<unsigned long>(R) << 24) |
               (static_cast<unsigned long>(G) << 16) |
               (static_cast<unsigned long>(B) << 8)  |
               (static_cast<unsigned long>(A) << 0);
    }

    unsigned long Color::ToARGB() const
    {
        return (static_cast<unsigned long>(A) << 24) |
               (static_cast<unsigned long>(R) << 16) |
               (static_cast<unsigned long>(G) << 8)  |
               (static_cast<unsigned long>(B) << 0);
    }

    Color& Color::operator = (const Color& original)
    {
        R = original.R;
        G = original.G;
        B = original.B;
        A = original.A;
        return *this;
    }

    Color& Color::operator += (Color right)
    {
        R = static_cast<byte>(std::min<int>(R + right.R, 255));
        G = static_cast<byte>(std::min<int>(G + right.G, 255));
        B = static_cast<byte>(std::min<int>(B + right.B, 255));
        A = static_cast<byte>(std::min<int>(A + right.A, 255));
        return *this;
    }

    Color& Color::operator -= (Color right)
    {
        R = static_cast<byte>(std::max<int>(R - right.R, 0));
        G = static_cast<byte>(std::max<int>(G - right.G, 0));
        B = static_cast<byte>(std::max<int>(B - right.B, 0));
        A = static_cast<byte>(std::max<int>(A - right.A, 0));
        return *this;
    }

    Color& Color::operator *= (Color right)
    {
        R = Clamp(static_cast<float>(R) * (static_cast<float>(right.R) / 255.0f));
        G = Clamp(static_cast<float>(G) * (static_cast<float>(right.G) / 255.0f));
        B = Clamp(static_cast<float>(B) * (static_cast<float>(right.B) / 255.0f));
        A = Clamp(static_cast<float>(A) * (static_cast<float>(right.A) / 255.0f));
        return *this;
    }

    Color& Color::operator *= (float right)
    {
        R = Clamp(static_cast<float>(R) * right);
        G = Clamp(static_cast<float>(G) * right);
        B = Clamp(static_cast<float>(B) * right);
        A = Clamp(static_cast<float>(A) * right);
        return *this;
    }

    Color& Color::operator /= (Color right)
    {
        R = Clamp(static_cast<float>(R) / (static_cast<float>(right.R) / 255.0f));
        G = Clamp(static_cast<float>(G) / (static_cast<float>(right.G) / 255.0f));
        B = Clamp(static_cast<float>(B) / (static_cast<float>(right.B) / 255.0f));
        A = Clamp(static_cast<float>(A) / (static_cast<float>(right.A) / 255.0f));
        return *this;
    }

    Color& Color::operator /= (float right)
    {
        R = Clamp(static_cast<float>(R) / right);
        G = Clamp(static_cast<float>(G) / right);
        B = Clamp(static_cast<float>(B) / right);
        A = Clamp(static_cast<float>(A) / right);
        return *this;
    }

    Color Color::operator + (Color right) const
    {
        return Color(std::min<int>(R + right.R, 255),
                     std::min<int>(G + right.G, 255),
                     std::min<int>(B + right.B, 255),
                     std::min<int>(A + right.A, 255));
    }

    Color Color::operator - (Color right) const
    {
        return Color(std::max<int>(R - right.R, 0),
                     std::max<int>(G - right.G, 0),
                     std::max<int>(B - right.B, 0),
                     std::max<int>(A - right.A, 0));
    }

    Color Color::operator * (Color right) const
    {
        return Color(Clamp(static_cast<float>(R) * (static_cast<float>(right.R) / 255.0f)),
                     Clamp(static_cast<float>(G) * (static_cast<float>(right.G) / 255.0f)),
                     Clamp(static_cast<float>(B) * (static_cast<float>(right.B) / 255.0f)),
                     Clamp(static_cast<float>(A) * (static_cast<float>(right.A) / 255.0f)));
    }

    Color Color::operator * (float right) const
    {
        return Color(Clamp(static_cast<float>(R) * right),
                     Clamp(static_cast<float>(G) * right),
                     Clamp(static_cast<float>(B) * right),
                     Clamp(static_cast<float>(A) * right));
    }

    Color Color::operator / (Color right) const
    {
        return Color(Clamp(static_cast<float>(R) / (static_cast<float>(right.R) / 255.0f)),
                     Clamp(static_cast<float>(G) / (static_cast<float>(right.G) / 255.0f)),
                     Clamp(static_cast<float>(B) / (static_cast<float>(right.B) / 255.0f)),
                     Clamp(static_cast<float>(A) / (static_cast<float>(right.A) / 255.0f)));
    }

    Color Color::operator / (float right) const
    {
        return Color(Clamp(static_cast<float>(R) / right),
                     Clamp(static_cast<float>(G) / right),
                     Clamp(static_cast<float>(B) / right),
                     Clamp(static_cast<float>(A) / right));
    }

    bool Color::operator == (Color right) const
    {
        return R == right.R && G == right.G && B == right.B && A == right.A;
    }

    bool Color::operator != (Color right) const
    {
        return !operator == (right);
    }

    bool Color::TryParse(const String& text, __Out Color& color)
    {
        if (text.GetLength() >= 7 && text[0] == '#')
        {
            unsigned int colorCode = 0x00000000;

            std::istringstream sin(text.Substring(1).CStr());
            sin >> std::hex;
            sin >> colorCode;

            if (text.GetLength() == 7)
                colorCode |= 0xFF000000;

            color.A = static_cast<byte>((colorCode & 0xFF000000) >> 24);
            color.R = static_cast<byte>((colorCode & 0x00FF0000) >> 16);
            color.G = static_cast<byte>((colorCode & 0x0000FF00) >> 8);
            color.B = static_cast<byte>((colorCode & 0x000000FF) >> 0);

            return true;
        }

        if (namedColorDictionary.empty())
            FillNamedColors();

        StringColorDictionary::const_iterator it = namedColorDictionary.find(text);
        if (it != namedColorDictionary.end())
        {
            color = (*it).second;
            return true;
        }
        else
            return false;
    }

    const Color Color::TransparentBlack = Color(0, 0, 0, 0);
    const Color Color::TransparentWhite = Color(255, 255, 255, 0);
    const Color Color::AliceBlue = Color(0xFFF0F8FF);
    const Color Color::AntiqueWhite = Color(0xFFFAEBD7);
    const Color Color::Aqua = Color(0xFF00FFFF);
    const Color Color::Aquamarine = Color(0xFF7FFFD4);
    const Color Color::Azure = Color(0xFFF0FFFF);
    const Color Color::Beige = Color(0xFFF5F5DC);
    const Color Color::Bisque = Color(0xFFFFE4C4);
    const Color Color::Black = Color(0xFF000000);
    const Color Color::BlanchedAlmond = Color(0xFFFFEBCD);
    const Color Color::Blue = Color(0xFF0000FF);
    const Color Color::BlueViolet = Color(0xFF8A2BE2);
    const Color Color::Brown = Color(0xFFA52A2A);
    const Color Color::BurlyWood = Color(0xFFDEB887);
    const Color Color::CadetBlue = Color(0xFF5F9EA0);
    const Color Color::Chartreuse = Color(0xFF7FFF00);
    const Color Color::Chocolate = Color(0xFFD2691E);
    const Color Color::Coral = Color(0xFFFF7F50);
    const Color Color::CornflowerBlue = Color(0xFF6495ED);
    const Color Color::Cornsilk = Color(0xFFFFF8DC);
    const Color Color::Crimson = Color(0xFFDC143C);
    const Color Color::Cyan = Color(0xFF00FFFF);
    const Color Color::DarkBlue = Color(0xFF00008B);
    const Color Color::DarkCyan = Color(0xFF008B8B);
    const Color Color::DarkGoldenRod = Color(0xFFB8860B);
    const Color Color::DarkGray = Color(0xFFA9A9A9);
    const Color Color::DarkGreen = Color(0xFF006400);
    const Color Color::DarkKhaki = Color(0xFFBDB76B);
    const Color Color::DarkMagenta = Color(0xFF8B008B);
    const Color Color::DarkOliveGreen = Color(0xFF556B2F);
    const Color Color::Darkorange = Color(0xFFFF8C00);
    const Color Color::DarkOrchid = Color(0xFF9932CC);
    const Color Color::DarkRed = Color(0xFF8B0000);
    const Color Color::DarkSalmon = Color(0xFFE9967A);
    const Color Color::DarkSeaGreen = Color(0xFF8FBC8F);
    const Color Color::DarkSlateBlue = Color(0xFF483D8B);
    const Color Color::DarkSlateGray = Color(0xFF2F4F4F);
    const Color Color::DarkTurquoise = Color(0xFF00CED1);
    const Color Color::DarkViolet = Color(0xFF9400D3);
    const Color Color::DeepPink = Color(0xFFFF1493);
    const Color Color::DeepSkyBlue = Color(0xFF00BFFF);
    const Color Color::DimGray = Color(0xFF696969);
    const Color Color::DodgerBlue = Color(0xFF1E90FF);
    const Color Color::FireBrick = Color(0xFFB22222);
    const Color Color::FloralWhite = Color(0xFFFFFAF0);
    const Color Color::ForestGreen = Color(0xFF228B22);
    const Color Color::Fuchsia = Color(0xFFFF00FF);
    const Color Color::Gainsboro = Color(0xFFDCDCDC);
    const Color Color::GhostWhite = Color(0xFFF8F8FF);
    const Color Color::Gold = Color(0xFFFFD700);
    const Color Color::GoldenRod = Color(0xFFDAA520);
    const Color Color::Gray = Color(0xFF808080);
    const Color Color::Green = Color(0xFF008000);
    const Color Color::GreenYellow = Color(0xFFADFF2F);
    const Color Color::HoneyDew = Color(0xFFF0FFF0);
    const Color Color::HotPink = Color(0xFFFF69B4);
    const Color Color::IndianRed = Color(0xFFCD5C5C);
    const Color Color::Indigo = Color(0xFF4B0082);
    const Color Color::Ivory = Color(0xFFFFFFF0);
    const Color Color::Khaki = Color(0xFFF0E68C);
    const Color Color::Lavender = Color(0xFFE6E6FA);
    const Color Color::LavenderBlush = Color(0xFFFFF0F5);
    const Color Color::LawnGreen = Color(0xFF7CFC00);
    const Color Color::LemonChiffon = Color(0xFFFFFACD);
    const Color Color::LightBlue = Color(0xFFADD8E6);
    const Color Color::LightCoral = Color(0xFFF08080);
    const Color Color::LightCyan = Color(0xFFE0FFFF);
    const Color Color::LightGoldenRodYellow = Color(0xFFFAFAD2);
    const Color Color::LightGrey = Color(0xFFD3D3D3);
    const Color Color::LightGreen = Color(0xFF90EE90);
    const Color Color::LightPink = Color(0xFFFFB6C1);
    const Color Color::LightSalmon = Color(0xFFFFA07A);
    const Color Color::LightSeaGreen = Color(0xFF20B2AA);
    const Color Color::LightSkyBlue = Color(0xFF87CEFA);
    const Color Color::LightSlateGray = Color(0xFF778899);
    const Color Color::LightSteelBlue = Color(0xFFB0C4DE);
    const Color Color::LightYellow = Color(0xFFFFFFE0);
    const Color Color::Lime = Color(0xFF00FF00);
    const Color Color::LimeGreen = Color(0xFF32CD32);
    const Color Color::Linen = Color(0xFFFAF0E6);
    const Color Color::Magenta = Color(0xFFFF00FF);
    const Color Color::Maroon = Color(0xFF800000);
    const Color Color::MediumAquaMarine = Color(0xFF66CDAA);
    const Color Color::MediumBlue = Color(0xFF0000CD);
    const Color Color::MediumOrchid = Color(0xFFBA55D3);
    const Color Color::MediumPurple = Color(0xFF9370D8);
    const Color Color::MediumSeaGreen = Color(0xFF3CB371);
    const Color Color::MediumSlateBlue = Color(0xFF7B68EE);
    const Color Color::MediumSpringGreen = Color(0xFF00FA9A);
    const Color Color::MediumTurquoise = Color(0xFF48D1CC);
    const Color Color::MediumVioletRed = Color(0xFFC71585);
    const Color Color::MidnightBlue = Color(0xFF191970);
    const Color Color::MintCream = Color(0xFFF5FFFA);
    const Color Color::MistyRose = Color(0xFFFFE4E1);
    const Color Color::Moccasin = Color(0xFFFFE4B5);
    const Color Color::NavajoWhite = Color(0xFFFFDEAD);
    const Color Color::Navy = Color(0xFF000080);
    const Color Color::OldLace = Color(0xFFFDF5E6);
    const Color Color::Olive = Color(0xFF808000);
    const Color Color::OliveDrab = Color(0xFF6B8E23);
    const Color Color::Orange = Color(0xFFFFA500);
    const Color Color::OrangeRed = Color(0xFFFF4500);
    const Color Color::Orchid = Color(0xFFDA70D6);
    const Color Color::PaleGoldenRod = Color(0xFFEEE8AA);
    const Color Color::PaleGreen = Color(0xFF98FB98);
    const Color Color::PaleTurquoise = Color(0xFFAFEEEE);
    const Color Color::PaleVioletRed = Color(0xFFD87093);
    const Color Color::PapayaWhip = Color(0xFFFFEFD5);
    const Color Color::PeachPuff = Color(0xFFFFDAB9);
    const Color Color::Peru = Color(0xFFCD853F);
    const Color Color::Pink = Color(0xFFFFC0CB);
    const Color Color::Plum = Color(0xFFDDA0DD);
    const Color Color::PowderBlue = Color(0xFFB0E0E6);
    const Color Color::Purple = Color(0xFF800080);
    const Color Color::Red = Color(0xFFFF0000);
    const Color Color::RosyBrown = Color(0xFFBC8F8F);
    const Color Color::RoyalBlue = Color(0xFF4169E1);
    const Color Color::SaddleBrown = Color(0xFF8B4513);
    const Color Color::Salmon = Color(0xFFFA8072);
    const Color Color::SandyBrown = Color(0xFFF4A460);
    const Color Color::SeaGreen = Color(0xFF2E8B57);
    const Color Color::SeaShell = Color(0xFFFFF5EE);
    const Color Color::Sienna = Color(0xFFA0522D);
    const Color Color::Silver = Color(0xFFC0C0C0);
    const Color Color::SkyBlue = Color(0xFF87CEEB);
    const Color Color::SlateBlue = Color(0xFF6A5ACD);
    const Color Color::SlateGray = Color(0xFF708090);
    const Color Color::Snow = Color(0xFFFFFAFA);
    const Color Color::SpringGreen = Color(0xFF00FF7F);
    const Color Color::SteelBlue = Color(0xFF4682B4);
    const Color Color::Tan = Color(0xFFD2B48C);
    const Color Color::Teal = Color(0xFF008080);
    const Color Color::Thistle = Color(0xFFD8BFD8);
    const Color Color::Tomato = Color(0xFFFF6347);
    const Color Color::Turquoise = Color(0xFF40E0D0);
    const Color Color::Violet = Color(0xFFEE82EE);
    const Color Color::Wheat = Color(0xFFF5DEB3);
    const Color Color::White = Color(0xFFFFFFFF);
    const Color Color::WhiteSmoke = Color(0xFFF5F5F5);
    const Color Color::Yellow = Color(0xFFFFFF00);
    const Color Color::YellowGreen = Color(0xFF9ACD32);

    Color::StringColorDictionary Color::namedColorDictionary;
    void Color::FillNamedColors()
    {
        HKAssertDebug(namedColorDictionary.empty());

#       define HKAddNamedColor(name) namedColorDictionary.insert(StringColorDictionary::value_type(#name, name));
            HKAddNamedColor(TransparentBlack);
            HKAddNamedColor(TransparentWhite);
            HKAddNamedColor(AliceBlue);
            HKAddNamedColor(AntiqueWhite);
            HKAddNamedColor(Aqua);
            HKAddNamedColor(Aquamarine);
            HKAddNamedColor(Azure);
            HKAddNamedColor(Beige);
            HKAddNamedColor(Bisque);
            HKAddNamedColor(Black);
            HKAddNamedColor(BlanchedAlmond);
            HKAddNamedColor(Blue);
            HKAddNamedColor(BlueViolet);
            HKAddNamedColor(Brown);
            HKAddNamedColor(BurlyWood);
            HKAddNamedColor(CadetBlue);
            HKAddNamedColor(Chartreuse);
            HKAddNamedColor(Chocolate);
            HKAddNamedColor(Coral);
            HKAddNamedColor(CornflowerBlue);
            HKAddNamedColor(Cornsilk);
            HKAddNamedColor(Crimson);
            HKAddNamedColor(Cyan);
            HKAddNamedColor(DarkBlue);
            HKAddNamedColor(DarkCyan);
            HKAddNamedColor(DarkGoldenRod);
            HKAddNamedColor(DarkGray);
            HKAddNamedColor(DarkGreen);
            HKAddNamedColor(DarkKhaki);
            HKAddNamedColor(DarkMagenta);
            HKAddNamedColor(DarkOliveGreen);
            HKAddNamedColor(Darkorange);
            HKAddNamedColor(DarkOrchid);
            HKAddNamedColor(DarkRed);
            HKAddNamedColor(DarkSalmon);
            HKAddNamedColor(DarkSeaGreen);
            HKAddNamedColor(DarkSlateBlue);
            HKAddNamedColor(DarkSlateGray);
            HKAddNamedColor(DarkTurquoise);
            HKAddNamedColor(DarkViolet);
            HKAddNamedColor(DeepPink);
            HKAddNamedColor(DeepSkyBlue);
            HKAddNamedColor(DimGray);
            HKAddNamedColor(DodgerBlue);
            HKAddNamedColor(FireBrick);
            HKAddNamedColor(FloralWhite);
            HKAddNamedColor(ForestGreen);
            HKAddNamedColor(Fuchsia);
            HKAddNamedColor(Gainsboro);
            HKAddNamedColor(GhostWhite);
            HKAddNamedColor(Gold);
            HKAddNamedColor(GoldenRod);
            HKAddNamedColor(Gray);
            HKAddNamedColor(Green);
            HKAddNamedColor(GreenYellow);
            HKAddNamedColor(HoneyDew);
            HKAddNamedColor(HotPink);
            HKAddNamedColor(IndianRed);
            HKAddNamedColor(Indigo);
            HKAddNamedColor(Ivory);
            HKAddNamedColor(Khaki);
            HKAddNamedColor(Lavender);
            HKAddNamedColor(LavenderBlush);
            HKAddNamedColor(LawnGreen);
            HKAddNamedColor(LemonChiffon);
            HKAddNamedColor(LightBlue);
            HKAddNamedColor(LightCoral);
            HKAddNamedColor(LightCyan);
            HKAddNamedColor(LightGoldenRodYellow);
            HKAddNamedColor(LightGrey);
            HKAddNamedColor(LightGreen);
            HKAddNamedColor(LightPink);
            HKAddNamedColor(LightSalmon);
            HKAddNamedColor(LightSeaGreen);
            HKAddNamedColor(LightSkyBlue);
            HKAddNamedColor(LightSlateGray);
            HKAddNamedColor(LightSteelBlue);
            HKAddNamedColor(LightYellow);
            HKAddNamedColor(Lime);
            HKAddNamedColor(LimeGreen);
            HKAddNamedColor(Linen);
            HKAddNamedColor(Magenta);
            HKAddNamedColor(Maroon);
            HKAddNamedColor(MediumAquaMarine);
            HKAddNamedColor(MediumBlue);
            HKAddNamedColor(MediumOrchid);
            HKAddNamedColor(MediumPurple);
            HKAddNamedColor(MediumSeaGreen);
            HKAddNamedColor(MediumSlateBlue);
            HKAddNamedColor(MediumSpringGreen);
            HKAddNamedColor(MediumTurquoise);
            HKAddNamedColor(MediumVioletRed);
            HKAddNamedColor(MidnightBlue);
            HKAddNamedColor(MintCream);
            HKAddNamedColor(MistyRose);
            HKAddNamedColor(Moccasin);
            HKAddNamedColor(NavajoWhite);
            HKAddNamedColor(Navy);
            HKAddNamedColor(OldLace);
            HKAddNamedColor(Olive);
            HKAddNamedColor(OliveDrab);
            HKAddNamedColor(Orange);
            HKAddNamedColor(OrangeRed);
            HKAddNamedColor(Orchid);
            HKAddNamedColor(PaleGoldenRod);
            HKAddNamedColor(PaleGreen);
            HKAddNamedColor(PaleTurquoise);
            HKAddNamedColor(PaleVioletRed);
            HKAddNamedColor(PapayaWhip);
            HKAddNamedColor(PeachPuff);
            HKAddNamedColor(Peru);
            HKAddNamedColor(Pink);
            HKAddNamedColor(Plum);
            HKAddNamedColor(PowderBlue);
            HKAddNamedColor(Purple);
            HKAddNamedColor(Red);
            HKAddNamedColor(RosyBrown);
            HKAddNamedColor(RoyalBlue);
            HKAddNamedColor(SaddleBrown);
            HKAddNamedColor(Salmon);
            HKAddNamedColor(SandyBrown);
            HKAddNamedColor(SeaGreen);
            HKAddNamedColor(SeaShell);
            HKAddNamedColor(Sienna);
            HKAddNamedColor(Silver);
            HKAddNamedColor(SkyBlue);
            HKAddNamedColor(SlateBlue);
            HKAddNamedColor(SlateGray);
            HKAddNamedColor(Snow);
            HKAddNamedColor(SpringGreen);
            HKAddNamedColor(SteelBlue);
            HKAddNamedColor(Tan);
            HKAddNamedColor(Teal);
            HKAddNamedColor(Thistle);
            HKAddNamedColor(Tomato);
            HKAddNamedColor(Turquoise);
            HKAddNamedColor(Violet);
            HKAddNamedColor(Wheat);
            HKAddNamedColor(White);
            HKAddNamedColor(WhiteSmoke);
            HKAddNamedColor(Yellow);
            HKAddNamedColor(YellowGreen);
#       undef HKAddNamedColor
    }
}