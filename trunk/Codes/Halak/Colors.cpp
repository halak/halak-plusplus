#include <Halak/PCH.h>
#include <Halak/Colors.h>
#include <Halak/Assert.h>
#include <sstream>

namespace Halak
{
    //Color Colors::Parse(const String& text)
    //{
    //    if (text.GetLength() >= 7 && text[0] == '#')
    //    {
    //        unsigned int colorCode = 0x00000000;

    //        std::istringstream sin(text.Substring(1).CStr());
    //        sin >> std::hex;
    //        sin >> colorCode;

    //        if (text.GetLength() == 7)
    //            colorCode |= 0xFF000000;

    //        return Color(static_cast<byte>((colorCode & 0xFF000000) >> 24),
    //                     static_cast<byte>((colorCode & 0x00FF0000) >> 16),
    //                     static_cast<byte>((colorCode & 0x0000FF00) >> 8),
    //                     static_cast<byte>((colorCode & 0x000000FF) >> 0));
    //    }

    //    if (namedColorDictionary.empty())
    //        FillNamedColors();

    //    StringColorDictionary::const_iterator it = namedColorDictionary.find(text);
    //    if (it != namedColorDictionary.end())
    //        return (*it).second;
    //    else
    //        return Color::TransparentBlack;
    //}

    //bool Color::CanParse(const String& text)
    //{
    //    if (text.GetLength() >= 7 && text[0] == '#')
    //        return true;

    //    if (namedColorDictionary.empty())
    //        FillNamedColors();

    //    return namedColorDictionary.find(text) != namedColorDictionary.end();
    //}

    const Color Colors::TransparentBlack = Color(0, 0, 0, 0);
    const Color Colors::TransparentWhite = Color(255, 255, 255, 0);
    const Color Colors::AliceBlue = Color(0xFFF0F8FF);
    const Color Colors::AntiqueWhite = Color(0xFFFAEBD7);
    const Color Colors::Aqua = Color(0xFF00FFFF);
    const Color Colors::AquaMarine = Color(0xFF7FFFD4);
    const Color Colors::Azure = Color(0xFFF0FFFF);
    const Color Colors::Beige = Color(0xFFF5F5DC);
    const Color Colors::Bisque = Color(0xFFFFE4C4);
    const Color Colors::Black = Color(0xFF000000);
    const Color Colors::BlanchedAlmond = Color(0xFFFFEBCD);
    const Color Colors::Blue = Color(0xFF0000FF);
    const Color Colors::BlueViolet = Color(0xFF8A2BE2);
    const Color Colors::Brown = Color(0xFFA52A2A);
    const Color Colors::BurlyWood = Color(0xFFDEB887);
    const Color Colors::CadetBlue = Color(0xFF5F9EA0);
    const Color Colors::Chartreuse = Color(0xFF7FFF00);
    const Color Colors::Chocolate = Color(0xFFD2691E);
    const Color Colors::Coral = Color(0xFFFF7F50);
    const Color Colors::CornflowerBlue = Color(0xFF6495ED);
    const Color Colors::Cornsilk = Color(0xFFFFF8DC);
    const Color Colors::Crimson = Color(0xFFDC143C);
    const Color Colors::Cyan = Color(0xFF00FFFF);
    const Color Colors::DarkBlue = Color(0xFF00008B);
    const Color Colors::DarkCyan = Color(0xFF008B8B);
    const Color Colors::DarkGoldenRod = Color(0xFFB8860B);
    const Color Colors::DarkGray = Color(0xFFA9A9A9);
    const Color Colors::DarkGreen = Color(0xFF006400);
    const Color Colors::DarkKhaki = Color(0xFFBDB76B);
    const Color Colors::DarkMagenta = Color(0xFF8B008B);
    const Color Colors::DarkOliveGreen = Color(0xFF556B2F);
    const Color Colors::DarkOrange = Color(0xFFFF8C00);
    const Color Colors::DarkOrchid = Color(0xFF9932CC);
    const Color Colors::DarkRed = Color(0xFF8B0000);
    const Color Colors::DarkSalmon = Color(0xFFE9967A);
    const Color Colors::DarkSeaGreen = Color(0xFF8FBC8F);
    const Color Colors::DarkSlateBlue = Color(0xFF483D8B);
    const Color Colors::DarkSlateGray = Color(0xFF2F4F4F);
    const Color Colors::DarkTurquoise = Color(0xFF00CED1);
    const Color Colors::DarkViolet = Color(0xFF9400D3);
    const Color Colors::DeepPink = Color(0xFFFF1493);
    const Color Colors::DeepSkyBlue = Color(0xFF00BFFF);
    const Color Colors::DimGray = Color(0xFF696969);
    const Color Colors::DodgerBlue = Color(0xFF1E90FF);
    const Color Colors::FireBrick = Color(0xFFB22222);
    const Color Colors::FloralWhite = Color(0xFFFFFAF0);
    const Color Colors::ForestGreen = Color(0xFF228B22);
    const Color Colors::Fuchsia = Color(0xFFFF00FF);
    const Color Colors::Gainsboro = Color(0xFFDCDCDC);
    const Color Colors::GhostWhite = Color(0xFFF8F8FF);
    const Color Colors::Gold = Color(0xFFFFD700);
    const Color Colors::GoldenRod = Color(0xFFDAA520);
    const Color Colors::Gray = Color(0xFF808080);
    const Color Colors::Green = Color(0xFF008000);
    const Color Colors::GreenYellow = Color(0xFFADFF2F);
    const Color Colors::HoneyDew = Color(0xFFF0FFF0);
    const Color Colors::HotPink = Color(0xFFFF69B4);
    const Color Colors::IndianRed = Color(0xFFCD5C5C);
    const Color Colors::Indigo = Color(0xFF4B0082);
    const Color Colors::Ivory = Color(0xFFFFFFF0);
    const Color Colors::Khaki = Color(0xFFF0E68C);
    const Color Colors::Lavender = Color(0xFFE6E6FA);
    const Color Colors::LavenderBlush = Color(0xFFFFF0F5);
    const Color Colors::LawnGreen = Color(0xFF7CFC00);
    const Color Colors::LemonChiffon = Color(0xFFFFFACD);
    const Color Colors::LightBlue = Color(0xFFADD8E6);
    const Color Colors::LightCoral = Color(0xFFF08080);
    const Color Colors::LightCyan = Color(0xFFE0FFFF);
    const Color Colors::LightGoldenRodYellow = Color(0xFFFAFAD2);
    const Color Colors::LightGrey = Color(0xFFD3D3D3);
    const Color Colors::LightGreen = Color(0xFF90EE90);
    const Color Colors::LightPink = Color(0xFFFFB6C1);
    const Color Colors::LightSalmon = Color(0xFFFFA07A);
    const Color Colors::LightSeaGreen = Color(0xFF20B2AA);
    const Color Colors::LightSkyBlue = Color(0xFF87CEFA);
    const Color Colors::LightSlateGray = Color(0xFF778899);
    const Color Colors::LightSteelBlue = Color(0xFFB0C4DE);
    const Color Colors::LightYellow = Color(0xFFFFFFE0);
    const Color Colors::Lime = Color(0xFF00FF00);
    const Color Colors::LimeGreen = Color(0xFF32CD32);
    const Color Colors::Linen = Color(0xFFFAF0E6);
    const Color Colors::Magenta = Color(0xFFFF00FF);
    const Color Colors::Maroon = Color(0xFF800000);
    const Color Colors::MediumAquaMarine = Color(0xFF66CDAA);
    const Color Colors::MediumBlue = Color(0xFF0000CD);
    const Color Colors::MediumOrchid = Color(0xFFBA55D3);
    const Color Colors::MediumPurple = Color(0xFF9370D8);
    const Color Colors::MediumSeaGreen = Color(0xFF3CB371);
    const Color Colors::MediumSlateBlue = Color(0xFF7B68EE);
    const Color Colors::MediumSpringGreen = Color(0xFF00FA9A);
    const Color Colors::MediumTurquoise = Color(0xFF48D1CC);
    const Color Colors::MediumVioletRed = Color(0xFFC71585);
    const Color Colors::MidnightBlue = Color(0xFF191970);
    const Color Colors::MintCream = Color(0xFFF5FFFA);
    const Color Colors::MistyRose = Color(0xFFFFE4E1);
    const Color Colors::Moccasin = Color(0xFFFFE4B5);
    const Color Colors::NavajoWhite = Color(0xFFFFDEAD);
    const Color Colors::Navy = Color(0xFF000080);
    const Color Colors::OldLace = Color(0xFFFDF5E6);
    const Color Colors::Olive = Color(0xFF808000);
    const Color Colors::OliveDrab = Color(0xFF6B8E23);
    const Color Colors::Orange = Color(0xFFFFA500);
    const Color Colors::OrangeRed = Color(0xFFFF4500);
    const Color Colors::Orchid = Color(0xFFDA70D6);
    const Color Colors::PaleGoldenRod = Color(0xFFEEE8AA);
    const Color Colors::PaleGreen = Color(0xFF98FB98);
    const Color Colors::PaleTurquoise = Color(0xFFAFEEEE);
    const Color Colors::PaleVioletRed = Color(0xFFD87093);
    const Color Colors::PapayaWhip = Color(0xFFFFEFD5);
    const Color Colors::PeachPuff = Color(0xFFFFDAB9);
    const Color Colors::Peru = Color(0xFFCD853F);
    const Color Colors::Pink = Color(0xFFFFC0CB);
    const Color Colors::Plum = Color(0xFFDDA0DD);
    const Color Colors::PowderBlue = Color(0xFFB0E0E6);
    const Color Colors::Purple = Color(0xFF800080);
    const Color Colors::Red = Color(0xFFFF0000);
    const Color Colors::RosyBrown = Color(0xFFBC8F8F);
    const Color Colors::RoyalBlue = Color(0xFF4169E1);
    const Color Colors::SaddleBrown = Color(0xFF8B4513);
    const Color Colors::Salmon = Color(0xFFFA8072);
    const Color Colors::SandyBrown = Color(0xFFF4A460);
    const Color Colors::SeaGreen = Color(0xFF2E8B57);
    const Color Colors::SeaShell = Color(0xFFFFF5EE);
    const Color Colors::Sienna = Color(0xFFA0522D);
    const Color Colors::Silver = Color(0xFFC0C0C0);
    const Color Colors::SkyBlue = Color(0xFF87CEEB);
    const Color Colors::SlateBlue = Color(0xFF6A5ACD);
    const Color Colors::SlateGray = Color(0xFF708090);
    const Color Colors::Snow = Color(0xFFFFFAFA);
    const Color Colors::SpringGreen = Color(0xFF00FF7F);
    const Color Colors::SteelBlue = Color(0xFF4682B4);
    const Color Colors::Tan = Color(0xFFD2B48C);
    const Color Colors::Teal = Color(0xFF008080);
    const Color Colors::Thistle = Color(0xFFD8BFD8);
    const Color Colors::Tomato = Color(0xFFFF6347);
    const Color Colors::Turquoise = Color(0xFF40E0D0);
    const Color Colors::Violet = Color(0xFFEE82EE);
    const Color Colors::Wheat = Color(0xFFF5DEB3);
    const Color Colors::White = Color(0xFFFFFFFF);
    const Color Colors::WhiteSmoke = Color(0xFFF5F5F5);
    const Color Colors::Yellow = Color(0xFFFFFF00);
    const Color Colors::YellowGreen = Color(0xFF9ACD32);

    void Colors::FillNamedColors()
    {
        HKAssertDebug(namedColorDictionary.empty());

#       define HKAddNamedColor(name) namedColorDictionary.insert(StringColorDictionary::value_type(#name, name));
            HKAddNamedColor(AliceBlue);
            HKAddNamedColor(AntiqueWhite);
            HKAddNamedColor(Aqua);
            HKAddNamedColor(AquaMarine);
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
            HKAddNamedColor(DarkOrange);
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
            HKAddNamedColor(TransparentBlack);
            HKAddNamedColor(TransparentWhite);
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