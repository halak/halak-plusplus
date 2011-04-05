#include <TH/Collision2D/CollisionSpace.h>
#include <TH/Collision2D/Shape.h>
#include <TH/Collision2D/RaycastReport.h>
#include <Halak/Assert.h>
#include <Halak/Math.h>
#include <limits>
using namespace Halak;

namespace TH
{
    namespace Collision2D
    {
        CollisionSpace::CollisionSpace()
        {
        }

        CollisionSpace::~CollisionSpace()
        {
        }

        int CollisionSpace::Detect()
        {
            int result = 0;

            const int numberOfGroups = GetNumberOfGroups();
            for (int i = 0; i < numberOfGroups; i++)
            {
                for (int k = i; k < numberOfGroups; k++)
                {
                    if (collisionRelationships[i][k])
                        result += Detect(shapes[i], shapes[k], i, k);
                }
            }

            return result;
        }

        int CollisionSpace::Detect(ShapePtrCollection& groupA, ShapePtrCollection& groupB, int groupANumber, int groupBNumber)
        {
            int result = 0;
            if (groupANumber != groupBNumber)
            {
                const int countA = static_cast<int>(groupA.size());
                const int countB = static_cast<int>(groupB.size());

                for (int i = 0; i < countA; i++)
                {
                    for (int k = 0; k < countB; k++, result++)
                        Detect(groupA[i], groupB[k], groupANumber, groupBNumber);
                }
            }
            else
            {
                const int countA = static_cast<int>(groupA.size());
                for (int i = 0; i < countA - 1; i++)
                {
                    for (int k = i + 1; k < countA; k++, result++)
                        Detect(groupA[i], groupA[k], groupANumber, groupANumber);
                }
            }

            return result;
        }

        void CollisionSpace::Detect(ShapePtr& shapeA, ShapePtr& shapeB, int groupA, int groupB)
        {
            HKAssert(shapeA != shapeB);

            if (Shape::Intersects(shapeA.GetPointee(), shapeB.GetPointee()))
                intersected.Emit(shapeA.GetPointee(), shapeB.GetPointee(), groupA, groupB);
        }

        bool CollisionSpace::Raycast(const Ray2D& ray, int group, __InOut RaycastReport report)
        {
            HKAssert(0 <= group && group < GetNumberOfGroups());

            RaycastReport testReport;
            float minimumDistanceSquared = std::numeric_limits<float>::max();

            struct ClosestHit : public IRaycastCallback
            {
                float* minimumDistanceSquared;

                ClosestHit(float& minimumDistanceSquared)
                    : minimumDistanceSquared(&minimumDistanceSquared)
                {
                }

                bool OnHit(float distanceSquared)
                {
                    return distanceSquared < *minimumDistanceSquared;
                }

            } Callback(minimumDistanceSquared);

            const int numberOfGroups = GetNumberOfGroups();
            for (int i = 0; i < numberOfGroups; i++)
            {
                if (collisionRelationships[group][i])
                {
                    const int count = static_cast<int>(shapes[i].size());
                    for (int k = 0; k < count; k++)
                    {
                        if (shapes[i][k]->Raycast(ray, __InOut testReport, &Callback))
                        {
                            minimumDistanceSquared = testReport.ImpactDistance * testReport.ImpactDistance;
                            report = testReport;

                            // 거리가 0이면 더 이상 가까운 Shape이 있을리가 없으므로 Raycast를 종료합니다.
                            if (Math::Equals(minimumDistanceSquared, 0.0f))
                                return true;
                        }
                    }
                }
            }

            return minimumDistanceSquared != std::numeric_limits<float>::max();
        }

        void CollisionSpace::Add(ShapePtr shape, int group)
        {
            if (Find(shape, nullptr, nullptr))
                throw std::invalid_argument("alreay exists shape.");

            shapes.at(group).push_back(shape);
        }

        void CollisionSpace::Remove(ShapePtr shape)
        {
            int outGroup = 0;
            int outIndex = 0;
            if (Find(shape, &outGroup, &outIndex))
                shapes[outGroup].erase(shapes[outGroup].begin() + outIndex);
        }

        void CollisionSpace::Clear()
        {
            shapes.clear();
        }

        void CollisionSpace::Clear(int group)
        {
            shapes.at(group).clear();
        }

        bool CollisionSpace::Find(ShapePtr shape, int* outGroup, int* outIndex) const
        {
            for (std::vector<ShapePtrCollection>::const_iterator itGroup = shapes.begin(); itGroup != shapes.end(); itGroup++)
            {
                const ShapePtrCollection& shapeGroup = (*itGroup);
                for (ShapePtrCollection::const_iterator itShape = shapeGroup.begin(); itShape != shapeGroup.end(); itShape++)
                {
                    if ((*itShape) == shape)
                    {
                        if (group)
                            (*group) = std::distance(shapes.begin(), itGroup);
                        if (index)
                            (*index) = std::distance(shapeGroup.begin(), itShape);

                        return true;
                    }
                }
            }

            return false;
        }

        int CollisionSpace::GetGroup(ShapePtr shape) const
        {
            int outGroup = 0;
            if (Find(shape, &outGroup, nullptr))
                return group;
            else
                return -1;
        }

        void CollisionSpace::SetGroup(ShapePtr shape, int group)
        {
            int existingGroup = 0;
            int existingIndex = 0;
            if (Find(shape, &existingGroup, &existingIndex))
            {
                shapes[existingGroup].erase(shapes[existingGroup].begin() + existingIndex);
                shapes.at(group).push_back(shape);
            }
        }

        int CollisionSpace::GetNumberOfGroups() const
        {
            return static_cast<int>(shapes.size());
        }

        void CollisionSpace::SetNumberOfGroups(int numberOfGroups)
        {
            std::vector<ShapePtrCollection> newShapes;
            std::vector<BooleanCollection>  newCollisionRelationships;

            // 새로운 공간을 잡습니다.
            newShapes.resize(numberOfGroups);
            newCollisionRelationships.resize(numberOfGroups);
            for (std::vector<BooleanCollection>::iterator it = newCollisionRelationships.begin(); it != newCollisionRelationships.end(); it++)
                (*it).resize(numberOfGroups);

            // 기존 값을 새로운 공간에 대입합니다.
            const int minimumSize = std::min<int>(numberOfGroups, GetNumberOfGroups());
            for (int i = 0; i < minimumSize; i++)
            {
                newShapes[i] = shapes[i];
                for (int k = 0; k < minimumSize; k++)
                    newCollisionRelationships[i][k] = collisionRelationships[i][k];
            }

            shapes = newShapes;
            collisionRelationships = newCollisionRelationships;
        }

        bool CollisionSpace::GetCollisionRelationship(int groupA, int groupB) const
        {
            return collisionRelationships.at(groupA).at(groupB);
        }

        void CollisionSpace::SetCollisionRelationship(int groupA, int groupB, bool detectable)
        {
            collisionRelationships.at(groupA).at(groupB) = detectable;
            collisionRelationships.at(groupB).at(groupA) = detectable;
        }

        Signal<Shape*, Shape*, int, int>& CollisionSpace::Intersected()
        {
            return intersected;
        }
    }
}