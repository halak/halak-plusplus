#pragma once
#ifndef __HALAK_PICKINGCONTEXT_INL__
#define __HALAK_PICKINGCONTEXT_INL__

    namespace Halak
    {
        const Ray& PickingContext::GetRay() const
        {
            return ray;
        }

        bool PickingContext::IsOrdered() const
        {
            return (options & OrderedFlag) != 0x00000000;
        }

        bool PickingContext::IsFindAll() const
        {
            return (options & FindAllFlag) != 0x00000000;
        }

        bool PickingContext::IsDebug() const
        {
            return (options & DebugFlag) != 0x00000000;
        }

        const PickingContext::ResultCollection& PickingContext::GetResults() const
        {
            return results;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        PickResult::PickResult(float distance, Vector3 point, Vector3 normal, IPickable* object, const Any& extraData)
            : Distance(distance),
              Point(point),
              Normal(normal),
              Object(object),
              ExtraData(extraData)
        {
        }

        PickResult::PickResult(float distance, Vector3 point, Vector3 normal, IPickablePtr sharedObject, const Any& extraData)
            : Distance(distance),
              Point(point),
              Normal(normal),
              Object(sharedObject.get()),
              SharedObject(sharedObject),
              ExtraData(extraData)
        {
        }

        PickResult::PickResult(const PickResult& original)
            : Distance(original.Distance),
              Point(original.Point),
              Normal(original.Normal),
              Object(original.Object),
              SharedObject(original.SharedObject),
              ExtraData(original.ExtraData)
        {
        }

        PickResult& PickResult::operator = (const PickResult& right)
        {
            Distance = right.Distance;
            Point = right.Point;
            Normal = right.Normal;
            Object = right.Object;
            SharedObject = right.SharedObject;
            ExtraData = right.ExtraData;
            return *this;
        }

        bool PickResult::operator == (const PickResult& right) const
        {
            return (Distance == right.Distance &&
                    Point == right.Point &&
                    Normal == right.Normal &&
                    Object == right.Object &&
                    SharedObject == right.SharedObject &&
                    ExtraData == right.ExtraData);
        }

        bool PickResult::operator != (const PickResult& right) const
        {
            return !operator == (right);
        }
    }

#endif