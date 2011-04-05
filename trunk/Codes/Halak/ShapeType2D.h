#pragma once
#ifndef __TH_COLLISION2D_SHAPETYPE_H__
#define __TH_COLLISION2D_SHAPETYPE_H__

    namespace TH
    {
        namespace Collision2D
        {
            struct ShapeType
            {
                enum E
                {
                    Point,
                    Segment,
                    Circle,
                    AxisAlignedRectangle,
                    Rectangle,
                    User,
                };
            };
        }
    }

#endif