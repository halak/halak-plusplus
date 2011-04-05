#pragma once
#ifndef __TH_COLLISION2D_SHAPE_INL__
#define __TH_COLLISION2D_SHAPE_INL__

    namespace TH
    {
        namespace Collision2D
        {
            ShapeType::E Shape::GetType() const
            {
                return type;
            }

            Vector2 Shape::GetPosition() const
            {
                return position;
            }

            float Shape::GetRotation() const
            {
                return rotation;
            }

            float Shape::GetScale() const
            {
                return scale;
            }

            unsigned int Shape::GetSpatialRevision() const
            {
                return revision;
            }
        }
    }

#endif