//#include <Halak/SpatialNode.h>
//
//namespace Halak
//{
//    SpatialNode::SpatialNode()
//        : worldPosition(Vector3::Zero),
//          worldRotation(Quaternion::Identity),
//          worldScale(1.0f),
//          localPosition(Vector3::Zero),
//          localRotation(Quaternion::Identity),
//          localScale(1.0f),
//          revision(1),
//          parentRevision(0),
//          worldTransformChanged(true)
//    {
//    }
//
//    SpatialNode::~SpatialNode()
//    {
//    }
//
//    Vector3 SpatialNode::GetPosition()
//    {
//        return worldPosition;
//    }
//
//    void SpatialNode::SetPosition(Vector3 value)
//    {
//    }
//
//    Quaternion SpatialNode::GetRotation()
//    {
//        return worldRotation;
//    }
//
//    void SpatialNode::SetRotation(Quaternion value)
//    {
//    }
//
//    float SpatialNode::GetScale()
//    {
//        return worldScale;
//    }
//
//    void SpatialNode::SetScale(float value)
//    {
//        worldScale = value;
//    }
//
//    Vector3 SpatialNode::GetLocalPosition() const
//    {
//        return localPosition;
//    }
//
//    void SpatialNode::SetLocalPosition(Vector3 value)
//    {
//        if (localPosition != value)
//        {
//            localPosition = value;
//            revision++;
//        }
//    }
//
//    Quaternion SpatialNode::GetLocalRotation() const
//    {
//        return localRotation;
//    }
//
//    void SpatialNode::SetLocalRotation(Quaternion value)
//    {
//        if (localRotation != value)
//        {
//            localRotation = value;
//            revision++;
//        }
//    }
//
//    float SpatialNode::GetLocalScale() const
//    {
//        return localScale;
//    }
//
//    void SpatialNode::SetLocalScale(float value)
//    {
//        if (localScale != value)
//        {
//            localScale = value;
//            revision++;
//        }
//    }
//
//    uint SpatialNode::GetRevision() const
//    {
//        return revision;
//    }
//
//    void SpatialNode::UpdateWorldTransform() const
//    {
//    }
//}