#pragma once
#ifndef __TH_COLLISION2D_USERSHAPE_H__
#define __TH_COLLISION2D_USERSHAPE_H__

#   include <TH/Collision2D/FWD.h>
#   include <TH/Collision2D/Shape.h>

    namespace TH
    {
        namespace Collision2D
        {
            class IUserShape
            {
                public:
                    virtual ~IUserShape() { }

                    virtual bool IntersectPoint(UserShape* userShape, Vector2 point) = 0;
                    virtual bool IntersectSegment(UserShape* userShape, Vector2 start, Vector2 end) = 0;
                    virtual bool IntersectCircle(UserShape* userShape, Vector2 center, float radius) = 0;
                    virtual bool IntersectAxisAlignedRectangle(UserShape* userShape, Vector2 leftTop, Vector2 rightBottom) = 0;
                    virtual bool IntersectRectangle(UserShape* userShape, Vector2 center, Vector2 orientation, Vector2 up, Vector2 extension) = 0;
                    virtual bool IntersectUserShape(UserShape* userShape, IUserShape* other) = 0;
                    virtual bool Raycast(UserShape* userShape, const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback) = 0;
                    virtual void AppendTo(UserShape* userShape, std::list<Vector2> points) = 0;
            };

            class UserShape : public Shape
            {
                public:
                    UserShape();
                    UserShape(IUserShapePtr userShape);
                    virtual ~UserShape();

                    IUserShapePtr GetUserShape();
                    void SerUserShape(IUserShapePtr value);

                    virtual bool Raycast(const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback);
                    virtual void AppendTo(std::list<Vector2>& vertices);

                private:
                    IUserShapePtr userShape;
            };
        }
    }

#endif