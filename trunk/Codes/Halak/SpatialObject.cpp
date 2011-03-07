#include <Halak/SpatialObject.h>

namespace Halak
{
    SpatialObject::SpatialObject()
        : position(Vector3::Zero),
          rotation(Quaternion::Identity),
          scale(1.0f),
          revision(1)
    {
    }

    SpatialObject::SpatialObject(Vector3 position)
        : position(position),
          rotation(Quaternion::Identity),
          scale(1.0f),
          revision(1)
    {
    }

    SpatialObject::SpatialObject(Vector3 position, Quaternion rotation, float scale)
        : position(position),
          rotation(rotation),
          scale(scale),
          revision(1)
    {
    }

    SpatialObject::~SpatialObject()
    {
    }

    Vector3 SpatialObject::GetPosition()
    {
        return position;
    }

    void SpatialObject::SetPosition(Vector3 value)
    {
        if (position != value)
        {
            position = value;
            revision++;
        }
    }

    Quaternion SpatialObject::GetRotation()
    {
        return rotation;
    }

    void SpatialObject::SetRotation(Quaternion value)
    {
        if (rotation != value)
        {
            rotation = value;
            revision++;
        }
    }

    float SpatialObject::GetScale()
    {
        return scale;
    }

    void SpatialObject::SetScale(float value)
    {
        if (scale != value)
        {
            scale = value;
            revision++;
        }
    }

    uint SpatialObject::GetRevision() const
    {
        return revision;
    }
}