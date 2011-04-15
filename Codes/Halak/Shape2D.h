#pragma once
#ifndef __HALAK_SHAPE2D_H__
#define __HALAK_SHAPE2D_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>
#   include <Halak/Ray2D.h>
#   include <Halak/Vector2.h>
#   include <list>

    namespace Halak
    {
        class Shape2D : public SharedObject
        {
            public:
                enum Type
                {
                    PointType,
                    SegmentType,
                    SphereType,
                    AxisAlignedBoxType,
                    BoxType,
                    UserType,
                };

            public:
                virtual ~Shape2D();

                inline Type GetType() const;

                inline Vector2 GetPosition() const;
                       void    SetPosition(Vector2 value);

                inline float GetRotation() const;
                       void  SetRotation(float value);

                inline float GetScale() const;
                       void  SetScale(float value);

                virtual bool Raycast(const Ray2D& ray, RaycastReport2D& outReport, IRaycastCallback2D* callback) = 0;
                virtual void AppendTo(std::list<Vector2>& vertices) = 0;

                static bool Intersect(Shape2D* left, Shape2D* right);

            protected:
                Shape2D(Type type);

                inline unsigned int GetSpatialRevision() const;

            private:
                const Type type;

                Vector2 position;
                float   rotation;
                float   scale;
                unsigned int revision;

            private:
                Shape2D& operator = (const Shape2D&);
        };
    }

#   include <Halak/Shape2D.inl>

#endif