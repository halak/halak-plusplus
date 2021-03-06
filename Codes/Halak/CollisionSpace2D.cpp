#include <Halak/PCH.h>
#include <Halak/CollisionSpace2D.h>
#include <Halak/Assert.h>
#include <Halak/Geom2D.h>
#include <Halak/Math.h>
#include <Halak/NumericLimits.h>
#include <Halak/RaycastReport2D.h>
#include <Halak/Shape2D.h>

namespace Halak
{
    CollisionSpace2D::CollisionSpace2D()
    {
    }

    CollisionSpace2D::CollisionSpace2D(uint32 id)
        : GameComponent(id)
    {
    }

    CollisionSpace2D::~CollisionSpace2D()
    {
    }

    int CollisionSpace2D::Detect()
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

    int CollisionSpace2D::Detect(ShapeCollection& groupA, ShapeCollection& groupB, int groupANumber, int groupBNumber)
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

    void CollisionSpace2D::Detect(Shape2D* shapeA, Shape2D* shapeB, int groupA, int groupB)
    {
        HKAssert(shapeA != shapeB);

        if (Shape2D::Intersect(shapeA, shapeB))
            intersected.Emit(shapeA, shapeB, groupA, groupB);
    }

    bool CollisionSpace2D::Raycast(const Ray2D& ray, int group, RaycastReport2D& outReport)
    {
        HKAssert(0 <= group && group < GetNumberOfGroups());

        RaycastReport2D testReport;
        float minimumDistanceSquared = NumericLimits::MaxFloat;

        struct ClosestHit : public IRaycastCallback2D
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
                    if (shapes[i][k]->Raycast(ray, testReport, &Callback))
                    {
                        minimumDistanceSquared = testReport.ImpactDistance * testReport.ImpactDistance;
                        outReport = testReport;

                        // 거리가 0이면 더 이상 가까운 Shape이 있을리가 없으므로 Raycast를 종료합니다.
                        if (Math::Equals(minimumDistanceSquared, 0.0f))
                            return true;
                    }
                }
            }
        }

        return minimumDistanceSquared != NumericLimits::MaxFloat;
    }

    void CollisionSpace2D::Add(Shape2DPtr shape, int group)
    {
        if (Find(shape, nullptr, nullptr))
            throw std::invalid_argument("alreay exists shape.");

        shapes.at(group).push_back(shape);
    }

    void CollisionSpace2D::Remove(Shape2DPtr shape)
    {
        int outGroup = 0;
        int outIndex = 0;
        if (Find(shape, &outGroup, &outIndex))
            shapes[outGroup].erase(shapes[outGroup].begin() + outIndex);
    }

    void CollisionSpace2D::Clear()
    {
        shapes.clear();
    }

    void CollisionSpace2D::Clear(int group)
    {
        shapes.at(group).clear();
    }

    bool CollisionSpace2D::Find(Shape2DPtr shape, int* outGroup, int* outIndex) const
    {
        for (std::vector<ShapeCollection>::const_iterator itGroup = shapes.begin(); itGroup != shapes.end(); itGroup++)
        {
            const ShapeCollection& shapeGroup = (*itGroup);
            for (ShapeCollection::const_iterator itShape = shapeGroup.begin(); itShape != shapeGroup.end(); itShape++)
            {
                if ((*itShape) == shape)
                {
                    if (outGroup)
                        (*outGroup) = std::distance(shapes.begin(), itGroup);
                    if (outIndex)
                        (*outIndex) = std::distance(shapeGroup.begin(), itShape);

                    return true;
                }
            }
        }

        return false;
    }

    int CollisionSpace2D::GetGroup(Shape2DPtr shape) const
    {
        int group = 0;
        if (Find(shape, &group, nullptr))
            return group;
        else
            return -1;
    }

    void CollisionSpace2D::SetGroup(Shape2DPtr shape, int group)
    {
        int existingGroup = 0;
        int existingIndex = 0;
        if (Find(shape, &existingGroup, &existingIndex))
        {
            shapes[existingGroup].erase(shapes[existingGroup].begin() + existingIndex);
            shapes.at(group).push_back(shape);
        }
    }

    int CollisionSpace2D::GetNumberOfGroups() const
    {
        return static_cast<int>(shapes.size());
    }

    void CollisionSpace2D::SetNumberOfGroups(int numberOfGroups)
    {
        std::vector<ShapeCollection> newShapes;
        std::vector<BooleanCollection>  newCollisionRelationships;

        // 새로운 공간을 잡습니다.
        newShapes.resize(numberOfGroups);
        newCollisionRelationships.resize(numberOfGroups);
        for (std::vector<BooleanCollection>::iterator it = newCollisionRelationships.begin(); it != newCollisionRelationships.end(); it++)
            (*it).resize(numberOfGroups);

        // 기존 값을 새로운 공간에 대입합니다.
        const int minimumSize = Math::Min(numberOfGroups, GetNumberOfGroups());
        for (int i = 0; i < minimumSize; i++)
        {
            newShapes[i] = shapes[i];
            for (int k = 0; k < minimumSize; k++)
                newCollisionRelationships[i][k] = collisionRelationships[i][k];
        }

        shapes = newShapes;
        collisionRelationships = newCollisionRelationships;
    }

    bool CollisionSpace2D::GetCollisionRelationship(int groupA, int groupB) const
    {
        return collisionRelationships.at(groupA).at(groupB);
    }

    void CollisionSpace2D::SetCollisionRelationship(int groupA, int groupB, bool detectable)
    {
        collisionRelationships.at(groupA).at(groupB) = detectable;
        collisionRelationships.at(groupB).at(groupA) = detectable;
    }

    Signal<Shape2D*, Shape2D*, int, int>& CollisionSpace2D::Intersected()
    {
        return intersected;
    }
}