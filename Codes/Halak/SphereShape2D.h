#pragma once
#ifndef __TH_COLLISION2D_CIRCLESHAPE_H__
#define __TH_COLLISION2D_CIRCLESHAPE_H__

#   include <TH/Collision2D/Shape.h>

    namespace TH
    {
        namespace Collision2D
        {
            class CircleShape : public Shape
            {
                public:
                    CircleShape();
                    virtual ~CircleShape();

                    float GetRadius() const;
                    void  SetRadius(float value);

                    float GetScaledRadius();
                    float GetScaledRadiusSquared();

                    virtual bool Raycast(const Ray2D& ray, RaycastReport& outReport, IRaycastCallback* callback);
                    virtual void AppendTo(std::list<Vector2>& vertices);

                private:
                    void UpdateParameters();

                private:
                    float radius;
                    float radiusSquared;
                    float scaledRadius;
                    float scaledRadiusSquared;
                    unsigned int revision;

                private:
                    CircleShape& operator = (const CircleShape&);
            };
        }
    }

#endif