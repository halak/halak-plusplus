#pragma once
#ifndef __HALAK_COLLISION2D_H__
#define __HALAK_COLLISION2D_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/Signal.h>
#   include <vector>

    namespace Halak
    {
        class CollisionSpace2D : public GameComponent
        {
            HKDeclareGameComponentClassFOURCC('C', 'O', 'S', '2');
            public:
                CollisionSpace2D();
                CollisionSpace2D(uint id);
                virtual ~CollisionSpace2D();

                int Detect();

                bool Raycast(const Ray2D& ray, int group, RaycastReport2D& outReport);

                void Add(Shape2DPtr shape, int group);
                void Remove(Shape2DPtr shape);
                void Clear();
                void Clear(int group);
                bool Find(Shape2DPtr shape, int* outGroup, int* outIndex) const;

                int  GetGroup(Shape2DPtr shape) const;
                void SetGroup(Shape2DPtr shape, int group);

                int  GetNumberOfGroups() const;
                void SetNumberOfGroups(int numberOfGroups);

                bool GetCollisionRelationship(int groupA, int groupB) const;
                void SetCollisionRelationship(int groupA, int groupB, bool detectable);

                Signal<Shape2D*, Shape2D*, int, int>& Intersected();

            private:
                typedef std::vector<Shape2DPtr> ShapeCollection;
                typedef std::vector<bool>       BooleanCollection;

                int  Detect(ShapeCollection& groupA, ShapeCollection& groupB, int groupANumber, int groupBNumber);
                void Detect(Shape2DPtr& shapeA, Shape2DPtr& shapeB, int groupA, int groupB);

            private:
                std::vector<ShapeCollection>   shapes;
                std::vector<BooleanCollection> collisionRelationships;

                Signal<Shape2D*, Shape2D*, int, int> intersected;
        };
    }

#endif