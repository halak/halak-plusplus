#pragma once
#ifndef __TH_COLLISION2D_RECTANGLESHAPE_H__
#define __TH_COLLISION2D_RECTANGLESHAPE_H__

#   include <TH/Collision2D/Shape.h>

    namespace TH
    {
        namespace Collision2D
        {
            class RectangleShape : public Shape
            {
                public:
                    RectangleShape();
                    virtual ~RectangleShape();

                    Vector2 GetOrientation() const;
                    void SetOrientation(Vector2 value);

                    Vector2 GetExtension() const;
                    void SetExtension(Vector2 value);

                    Vector2 GetCenter();
                    Vector2 GetRotatedOrientation();
                    Vector2 GetRotatedUp();
                    Vector2 GetScaledExtension();
                    Vector2 GetP0();
                    Vector2 GetP1();
                    Vector2 GetP2();
                    Vector2 GetP3();

                    virtual bool Raycast(const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback);
                    virtual void AppendTo(std::list<Vector2>& vertices);

                private:
                    void UpdateParameters();

                private:
                    Vector2 orientation;
                    Vector2 extension;

                    Vector2 center;
                    Vector2 rotatedOrientation;
                    Vector2 rotatedUp;
                    Vector2 scaledExtension;
                    Vector2 p0, p1, p2, p3;
                    unsigned revision;

                private:
                    RectangleShape& operator = (const RectangleShape&);
            };
        }
    }

#endif