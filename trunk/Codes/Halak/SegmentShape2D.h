#pragma once
#ifndef __TH_COLLISION2D_SEGMENTSHAPE_H__
#define __TH_COLLISION2D_SEGMENTSHAPE_H__

#   include <TH/Collision2D/Shape.h>

    namespace TH
    {
        namespace Collision2D
        {
            class SegmentShape : public Shape
            {
                public:
                    SegmentShape();
                    virtual ~SegmentShape();

                    Vector2 GetDirection() const;
                    void SetDirection(Vector2 value);

                    float GetFrontLength() const;
                    void SetFrontLength(float value);

                    float GetBackLength() const;
                    void SetBackLength(float value);

                    float GetLength() const;

                    Vector2 GetStartPoint();
                    Vector2 GetEndPoint();
                    Vector2 GetRotatedDirection();

                    virtual bool Raycast(const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback);
                    virtual void AppendTo(std::list<Vector2>& vertices);

                private:
                    void UpdateParameters();

                private:
                    Vector2 direction;
                    float frontLength;
                    float backLength;

                    Vector2 startPoint;
                    Vector2 endPoint;
                    Vector2 rotatedDirection;
                    unsigned int revision;

                private:
                    SegmentShape& operator = (const PointShape&);
            };
        }
    }

#endif