namespace Halak
{
    Ray2D::Ray2D()
        : Origin(Vector2::Zero),
          Direction(Vector2::Zero),
          Length(0.0f)
    {
    }

    Ray2D::Ray2D(Vector2 origin, Vector2 direction, float length)
        : Origin(origin),
          Direction(direction),
          Length(length)
    {
    }

    Ray2D::Ray2D(Vector2 start, Vector2 end)
        : Origin(start)
    {
        Direction = end - start;
        Length = Direction.Normalize();
    }

    Ray2D::Ray2D(const Ray2D& original)
        : Origin(original.Origin),
          Direction(original.Direction),
          Length(original.Length)
    {
    }

    Ray2D& Ray2D::operator = (const Ray2D& original)
    {
        Origin = original.Origin;
        Direction = original.Direction;
        Length = original.Length;
        return *this;
    }

    bool Ray2D::operator == (const Ray2D& right) const
    {
        return (Origin == right.Origin &&
                Direction == right.Direction &&
                Length == right.Length);
    }

    bool Ray2D::operator != (const Ray2D& right) const
    {
        return !operator == (right);
    }
}