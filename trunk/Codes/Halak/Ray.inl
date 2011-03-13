namespace Halak
{
    Ray::Ray()
        : Origin(Vector3::Zero),
          Direction(Vector3::Zero),
          Length(0.0f)
    {
    }

    Ray::Ray(Vector3 origin, Vector3 direction, float length)
        : Origin(origin),
          Direction(direction),
          Length(length)
    {
    }

    Ray::Ray(Vector3 start, Vector3 end)
        : Origin(start)
    {
        Direction = end - start;
        Length = Direction.Normalize();
    }

    Ray::Ray(const Ray& original)
        : Origin(original.Origin),
          Direction(original.Direction),
          Length(original.Length)
    {
    }

    Ray& Ray::operator = (const Ray& original)
    {
        Origin = original.Origin;
        Direction = original.Direction;
        Length = original.Length;
        return *this;
    }

    bool Ray::operator == (const Ray& right) const
    {
        return (Origin == right.Origin &&
                Direction == right.Direction &&
                Length == right.Length);
    }

    bool Ray::operator != (const Ray& right) const
    {
        return !operator == (right);
    }
}