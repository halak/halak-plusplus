#pragma once
#ifndef __TH_COLLISION2D_COLLISIONSPACE_H__
#define __TH_COLLISION2D_COLLISIONSPACE_H__

#   include <TH/Collision2D/FWD.h>
#   include <TH/Object.h>
#   include <Halak/Signal.h>
#   include <vector>

    namespace TH
    {
        namespace Collision2D
        {
            class CollisionSpace : public Object
            {
                public:
                    CollisionSpace();
                    virtual ~CollisionSpace();

                    int Detect();

                    bool Raycast(const Ray2D& ray, int group, __InOut RaycastReport report);

                    void Add(ShapePtr shape, int group);
                    void Remove(ShapePtr shape);
                    void Clear();
                    void Clear(int group);
                    bool Find(ShapePtr shape, int* outGroup, int* outIndex) const;

                    int  GetGroup(ShapePtr shape) const;
                    void SetGroup(ShapePtr shape, int group);

                    int  GetNumberOfGroups() const;
                    void SetNumberOfGroups(int numberOfGroups);

                    bool GetCollisionRelationship(int groupA, int groupB) const;
                    void SetCollisionRelationship(int groupA, int groupB, bool detectable);

                    Halak::Signal<Shape*, Shape*, int, int>& Intersected();

                private:
                    typedef std::vector<ShapePtr> ShapePtrCollection;
                    typedef std::vector<bool>     BooleanCollection;

                    int  Detect(ShapePtrCollection& groupA, ShapePtrCollection& groupB, int groupANumber, int groupBNumber);
                    void Detect(ShapePtr& shapeA, ShapePtr& shapeB, int groupA, int groupB);

                private:
                    std::vector<ShapePtrCollection> shapes;
                    std::vector<BooleanCollection>  collisionRelationships;

                    Halak::Signal<Shape*, Shape*, int, int> intersected;
            };
        }
    }

#endif