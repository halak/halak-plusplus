#pragma once
#ifndef __HALAK_COLOR_H__
#define __HALAK_COLOR_H__

#   include <Halak/FWD.h>
#   include <Halak/String.h>
#   include <Halak/Vector3.h>
#   include <Halak/Vector4.h>
#   include <map>

    namespace Halak
    {
        struct Color
        {
            HKDeclareStructFOURCC('C', 'O', 'L', 'R');

            byte A;
            byte R;
            byte G;
            byte B;

            inline Color();
            inline Color(int r, int g, int b);
            inline Color(int r, int g, int b, int a);
            inline Color(unsigned long argb);
            inline explicit Color(Vector3 rgb);
            inline explicit Color(Vector4 rgba);
            inline Color(const Color& original);

            inline Vector3 ToVector3() const;
            inline Vector4 ToVector4() const;
            inline unsigned long ToRGBA() const;
            inline unsigned long ToARGB() const;

            inline Color& operator = (const Color& original);
            inline Color& operator += (Color right);
            inline Color& operator -= (Color right);
            inline Color& operator *= (Color right);
            inline Color& operator *= (float right);
            inline Color& operator /= (Color right);
            inline Color& operator /= (float right);

            inline Color operator + (Color right) const;
            inline Color operator - (Color right) const;
            inline Color operator * (Color right) const;
            inline Color operator * (float right) const;
            inline Color operator / (Color right) const;
            inline Color operator / (float right) const;

            inline bool operator == (Color right) const;
            inline bool operator != (Color right) const;

            static Color Parse(const String& text);
            static bool  CanParse(const String& text);

            static const Color TransparentBlack;
            static const Color TransparentWhite;
            static const Color AliceBlue;
            static const Color AntiqueWhite;
            static const Color Aqua;
            static const Color AquaMarine;
            static const Color Azure;
            static const Color Beige;
            static const Color Bisque;
            static const Color Black;
            static const Color BlanchedAlmond;
            static const Color Blue;
            static const Color BlueViolet;
            static const Color Brown;
            static const Color BurlyWood;
            static const Color CadetBlue;
            static const Color Chartreuse;
            static const Color Chocolate;
            static const Color Coral;
            static const Color CornflowerBlue;
            static const Color Cornsilk;
            static const Color Crimson;
            static const Color Cyan;
            static const Color DarkBlue;
            static const Color DarkCyan;
            static const Color DarkGoldenRod;
            static const Color DarkGray;
            static const Color DarkGreen;
            static const Color DarkKhaki;
            static const Color DarkMagenta;
            static const Color DarkOliveGreen;
            static const Color DarkOrange;
            static const Color DarkOrchid;
            static const Color DarkRed;
            static const Color DarkSalmon;
            static const Color DarkSeaGreen;
            static const Color DarkSlateBlue;
            static const Color DarkSlateGray;
            static const Color DarkTurquoise;
            static const Color DarkViolet;
            static const Color DeepPink;
            static const Color DeepSkyBlue;
            static const Color DimGray;
            static const Color DodgerBlue;
            static const Color FireBrick;
            static const Color FloralWhite;
            static const Color ForestGreen;
            static const Color Fuchsia;
            static const Color Gainsboro;
            static const Color GhostWhite;
            static const Color Gold;
            static const Color GoldenRod;
            static const Color Gray;
            static const Color Green;
            static const Color GreenYellow;
            static const Color HoneyDew;
            static const Color HotPink;
            static const Color IndianRed;
            static const Color Indigo;
            static const Color Ivory;
            static const Color Khaki;
            static const Color Lavender;
            static const Color LavenderBlush;
            static const Color LawnGreen;
            static const Color LemonChiffon;
            static const Color LightBlue;
            static const Color LightCoral;
            static const Color LightCyan;
            static const Color LightGoldenRodYellow;
            static const Color LightGrey;
            static const Color LightGreen;
            static const Color LightPink;
            static const Color LightSalmon;
            static const Color LightSeaGreen;
            static const Color LightSkyBlue;
            static const Color LightSlateGray;
            static const Color LightSteelBlue;
            static const Color LightYellow;
            static const Color Lime;
            static const Color LimeGreen;
            static const Color Linen;
            static const Color Magenta;
            static const Color Maroon;
            static const Color MediumAquaMarine;
            static const Color MediumBlue;
            static const Color MediumOrchid;
            static const Color MediumPurple;
            static const Color MediumSeaGreen;
            static const Color MediumSlateBlue;
            static const Color MediumSpringGreen;
            static const Color MediumTurquoise;
            static const Color MediumVioletRed;
            static const Color MidnightBlue;
            static const Color MintCream;
            static const Color MistyRose;
            static const Color Moccasin;
            static const Color NavajoWhite;
            static const Color Navy;
            static const Color OldLace;
            static const Color Olive;
            static const Color OliveDrab;
            static const Color Orange;
            static const Color OrangeRed;
            static const Color Orchid;
            static const Color PaleGoldenRod;
            static const Color PaleGreen;
            static const Color PaleTurquoise;
            static const Color PaleVioletRed;
            static const Color PapayaWhip;
            static const Color PeachPuff;
            static const Color Peru;
            static const Color Pink;
            static const Color Plum;
            static const Color PowderBlue;
            static const Color Purple;
            static const Color Red;
            static const Color RosyBrown;
            static const Color RoyalBlue;
            static const Color SaddleBrown;
            static const Color Salmon;
            static const Color SandyBrown;
            static const Color SeaGreen;
            static const Color SeaShell;
            static const Color Sienna;
            static const Color Silver;
            static const Color SkyBlue;
            static const Color SlateBlue;
            static const Color SlateGray;
            static const Color Snow;
            static const Color SpringGreen;
            static const Color SteelBlue;
            static const Color Tan;
            static const Color Teal;
            static const Color Thistle;
            static const Color Tomato;
            static const Color Turquoise;
            static const Color Violet;
            static const Color Wheat;
            static const Color White;
            static const Color WhiteSmoke;
            static const Color Yellow;
            static const Color YellowGreen;

            private:
                typedef std::map<String, Color> StringColorDictionary;
                static StringColorDictionary namedColorDictionary;
                static void FillNamedColors();

                static inline byte Clamp(int value);
                static inline byte Clamp(float value);
        };
    }

#   include <Halak/Color.inl>

#endif