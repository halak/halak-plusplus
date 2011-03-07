#ifndef __HALAK_EVALUABLE_INTERFACE_H__
#define __HALAK_EVALUABLE_INTERFACE_H__

#   include <Halak/IBoolEvaluable.h>
#   include <Halak/ICharEvaluable.h>
#   include <Halak/IColorEvaluable.h>
#   include <Halak/IDoubleEvaluable.h>
#   include <Halak/IFloatEvaluable.h>
#   include <Halak/IIntEvaluable.h>
#   include <Halak/ILongEvaluable.h>
#   include <Halak/IPointEvaluable.h>
#   include <Halak/IQuaternionEvaluable.h>
#   include <Halak/IRectangleEvaluable.h>
#   include <Halak/IShortEvaluable.h>
#   include <Halak/ISpriteEvaluable.h>
#   include <Halak/IUCharEvaluable.h>
#   include <Halak/IUIntEvaluable.h>
#   include <Halak/IULongEvaluable.h>
#   include <Halak/IUShortEvaluable.h>
#   include <Halak/IVector2Evaluable.h>
#   include <Halak/IVector3Evaluable.h>
#   include <Halak/IVector4Evaluable.h>

#   include <Halak/IFloatRangeEvaluable.h>

    namespace Halak
    {
        template <typename T> struct SelectEvaluableInterface
        {
        };

        template <> struct SelectEvaluableInterface<bool>            { typedef IBoolEvaluable         Result; };
        template <> struct SelectEvaluableInterface<char>            { typedef ICharEvaluable         Result; };
        template <> struct SelectEvaluableInterface<unsigned char>   { typedef IUCharEvaluable        Result; };
        template <> struct SelectEvaluableInterface<short>           { typedef IShortEvaluable        Result; };
        template <> struct SelectEvaluableInterface<unsigned short>  { typedef IUShortEvaluable       Result; };
        template <> struct SelectEvaluableInterface<int>             { typedef IIntEvaluable          Result; };
        template <> struct SelectEvaluableInterface<unsigned int>    { typedef IUIntEvaluable         Result; };
        template <> struct SelectEvaluableInterface<long>            { typedef ILongEvaluable         Result; };
        template <> struct SelectEvaluableInterface<unsigned long>   { typedef IULongEvaluable        Result; };
        template <> struct SelectEvaluableInterface<float>           { typedef IFloatEvaluable        Result; };
        template <> struct SelectEvaluableInterface<double>          { typedef IDoubleEvaluable       Result; };
        template <> struct SelectEvaluableInterface<Point>           { typedef IPointEvaluable        Result; };
        template <> struct SelectEvaluableInterface<Rectangle>       { typedef IRectangleEvaluable    Result; };
        template <> struct SelectEvaluableInterface<Vector2>         { typedef IVector2Evaluable      Result; };
        template <> struct SelectEvaluableInterface<Vector3>         { typedef IVector3Evaluable      Result; };
        template <> struct SelectEvaluableInterface<Vector4>         { typedef IVector4Evaluable      Result; };
        template <> struct SelectEvaluableInterface<Quaternion>      { typedef IQuaternionEvaluable   Result; };
        template <> struct SelectEvaluableInterface<Color>           { typedef IColorEvaluable        Result; };
        template <> struct SelectEvaluableInterface<Sprite>          { typedef ISpriteEvaluable       Result; };

        template <> struct SelectEvaluableInterface<FloatRange>      { typedef IFloatRangeEvaluable   Result; };
    }

#endif