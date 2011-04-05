#pragma once
#ifndef __TH_COLLISION2D_RAYCASTREPORT_H__
#define __TH_COLLISION2D_RAYCASTREPORT_H__

#   include <TH/Collision2D/FWD.h>
#   include <Halak/Vector2.h>

    namespace TH
    {
        namespace Collision2D
        {
            struct RaycastReport
            {
                Shape*  ImpactShape;
                Vector2 ImpactPoint;
                Vector2 ImpactNormal;
                float   ImpactDistance;

                RaycastReport();
                RaycastReport(Shape* shape, const Vector2& point, const Vector2& normal, float distance);
                RaycastReport(const RaycastReport& original);

                RaycastReport& operator = (const RaycastReport& original);
                
                bool operator == (const RaycastReport& right) const;
                bool operator != (const RaycastReport& right) const;
            };

            struct IRaycastCallback
            {
                virtual bool OnHit(float distanceSquared) = 0;
            };
        }
    }

#endif