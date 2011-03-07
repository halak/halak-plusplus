#include <Halak/SpatialObject2D.h>

namespace Halak
{
    SpatialObject2D::SpatialObject2D()
        : position(Vector2::Zero),
          rotation(0.0f),
          scale(1.0f),
          revision(1)
    {
    }

    SpatialObject2D::SpatialObject2D(Vector2 position)
        : position(position),
          rotation(0.0f),
          scale(1.0f),
          revision(1)
    {
    }

    SpatialObject2D::SpatialObject2D(Vector2 position, float rotation, float scale)
        : position(position),
          rotation(rotation),
          scale(scale),
          revision(1)
    {
    }

    SpatialObject2D::~SpatialObject2D()
    {
    }

    Vector2 SpatialObject2D::GetPosition()
    {
        return position;
    }

    void SpatialObject2D::SetPosition(Vector2 value)
    {
        if (position != value)
        {
            position = value;
            revision++;
        }
    }

    float SpatialObject2D::GetRotation()
    {
        return rotation;
    }

    void SpatialObject2D::SetRotation(float value)
    {
        if (rotation != value)
        {
            rotation = value;
            revision++;
        }
    }

    float SpatialObject2D::GetScale()
    {
        return scale;
    }

    void SpatialObject2D::SetScale(float value)
    {
        if (scale != value)
        {
            scale = value;
            revision++;
        }
    }

    uint SpatialObject2D::GetRevision() const
    {
        return revision;
    }
}