#pragma once
#ifndef __TH_COLLISION2D_SHAPE_H__
#define __TH_COLLISION2D_SHAPE_H__

#   include <TH/Collision2D/FWD.h>
#   include <TH/Collision2D/ShapeType.h>
#   include <Halak/Vector2.h>
#   include <Halak/Ray2D.h>
#   include <list>

    namespace TH
    {
        namespace Collision2D
        {
            class Shape
            {
                public:
                    virtual ~Shape();

                    inline ShapeType::E GetType() const;

                    inline Vector2 GetPosition() const;
                           void    SetPosition(Vector2 value);

                    inline float GetRotation() const;
                           void  SetRotation(float value);

                    inline float GetScale() const;
                           void  SetScale(float value);

                    virtual bool Raycast(const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback) = 0;
                    virtual void AppendTo(std::list<Vector2>& vertices) = 0;

                    static bool Intersects(Shape* left, Shape* right);

                protected:
                    Shape(ShapeType::E type);

                    inline unsigned int GetSpatialRevision() const;

                private:
                    const ShapeType::E type;

                    Vector2 position;
                    float   rotation;
                    float   scale;
                    unsigned int revision;

                private:
                    Shape& operator = (const Shape&);
            };
        }
    }

#   include <TH/Collision2D/Shape.inl>

#endif