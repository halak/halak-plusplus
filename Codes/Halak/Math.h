#pragma once
#ifndef __HALAK_MATH_H__
#define __HALAK_MATH_H__

#   include <Halak/FWD.h>
#   include <Halak/Color.h>
#   include <Halak/Point.h>
#   include <Halak/Vector2.h>
#   include <Halak/Vector3.h>
#   include <Halak/Vector4.h>
#   include <vector>

    namespace Halak
    {
        class Math
        {
            public:
                static const float E;
                static const float Log10E;
                static const float Log2E;
                static const float Pi;
                static const float PiOver2;
                static const float PiOver4;
                static const float TwoPi;

                static float Sqrt(float value);
                static float Sin(float radian);
                static float Cos(float radian);
                static float Tan(float radian);
                static float Acos(float radian);
                static float Atan2(float y, float x);

                static short          Abs(short value);
                static int            Abs(int value);
                static long           Abs(long value);
                static float          Abs(float value);
                static double         Abs(double value);

                static short          Clamp(short value, short min, short max);
                static unsigned short Clamp(unsigned short value, unsigned short min, unsigned short max);
                static int            Clamp(int value, int min, int max);
                static unsigned int   Clamp(unsigned int value, unsigned int min, unsigned int max);
                static long           Clamp(long value, long min, long max);
                static unsigned long  Clamp(unsigned long value, unsigned long min, unsigned long max);
                static float          Clamp(float value, float min, float max);
                static double         Clamp(double value, double min, double max);

                static int Wrap(int value, int upper);

                static int  GetNearestMorePowerOfTwo(int value);
                static uint GetNearestMorePowerOfTwo(uint value);

                static bool Equals(float a, float b);
                static bool Equals(Vector2 a, Vector2 b);
                static bool Equals(Vector3 a, Vector3 b);

                static Vector2 GetClosestPoint(Vector2 origin, Vector2 direction, float length, Vector2 point);

                static bool IsClockwise(Vector2 a, Vector2 b, Vector2 c);
                static bool IsClockwise(const std::vector<Vector2>& points);
                static bool IsClockwise(const std::vector<Vector2>& points, int numberOfPoints);

                static inline int     Interpolate(int a, int b, float t);
                static inline float   Interpolate(float a, float b, float t);
                static inline double  Interpolate(double a, double b, float t);
                static inline Point   Interpolate(Point a, Point b, float t);
                static inline Vector2 Interpolate(Vector2 a, Vector2 b, float t);
                static inline Vector3 Interpolate(Vector3 a, Vector3 b, float t);
                static inline Vector4 Interpolate(Vector4 a, Vector4 b, float t);
                static inline Color   Interpolate(Color a, Color b, float t);

                static int     Random(int a, int b);
                static float   Random(float a, float b);
                static Vector2 Random(Vector2 a, Vector2 b);
                static Vector3 Random(Vector3 a, Vector3 b);
                static Vector4 Random(Vector4 a, Vector4 b);
                static Color   Random(Color a, Color b);

            private:
                Math();
                Math(const Math&);
                Math& operator = (const Math&);
        };
    }

#   include <Halak/Math.inl>

#endif