#include <Halak/PCH.h>
#include <Halak/ParticleSpawnPoints.h>
#include <Halak/Math.h>

namespace Halak
{
    ParticleSpawnPoint::ParticleSpawnPoint()
    {
    }

    ParticleSpawnPoint::ParticleSpawnPoint(const ParticleSpawnPoint& /*original*/)
    {
    }

    ParticleSpawnPoint::~ParticleSpawnPoint()
    {
    }

    ParticleSpawnPoint* ParticleSpawnPoint::Clone() const
    {
        return new ParticleSpawnPoint(*this);
    }

    ParticleSpawnPoint* ParticleSpawnPoint::CloneWith(CloningContext& /*context*/) const
    {
        return new ParticleSpawnPoint(*this);
    }
    
    Vector3 ParticleSpawnPoint::Spawn(Vector3 position, Quaternion /*rotation*/, float /*scale*/) const
    {
        return position;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    ParticleSpawnSegment::ParticleSpawnSegment()
    {
    }

    ParticleSpawnSegment::~ParticleSpawnSegment()
    {
    }

    Vector3 ParticleSpawnSegment::Spawn(Vector3 /*position*/, Quaternion /*rotation*/, float /*scale*/) const
    {
        return Vector3::Zero;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    ParticleSpawnBox::ParticleSpawnBox()
    {
    }

    ParticleSpawnBox::~ParticleSpawnBox()
    {
    }

    Vector3 ParticleSpawnBox::Spawn(Vector3 /*position*/, Quaternion /*rotation*/, float /*scale*/) const
    {
        return Vector3::Zero;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    ParticleSpawnSphere::ParticleSpawnSphere()
        : ParticleSpawnPoint(),
          radius(0.0f)
    {
    }

    ParticleSpawnSphere::ParticleSpawnSphere(const ParticleSpawnSphere& original)
        : ParticleSpawnPoint(original),
          radius(original.radius)
    {
    }

    ParticleSpawnSphere::~ParticleSpawnSphere()
    {
    }

    ParticleSpawnSphere* ParticleSpawnSphere::Clone() const
    {
        return new ParticleSpawnSphere(*this);
    }

    ParticleSpawnSphere* ParticleSpawnSphere::CloneWith(CloningContext& /*context*/) const
    {
        return new ParticleSpawnSphere(*this);
    }

    Vector3 ParticleSpawnSphere::Spawn(Vector3 position, Quaternion /*rotation*/, float scale) const
    {
        const float yaw   = Math::Random(0.0f, Math::TwoPi);
        const float pitch = Math::Random(0.0f, Math::TwoPi);

        //Vector2 direction2D = Vector2::UnitX;
        //Vector2 direction2D = 
        //direction2D.Rotate(yaw);

        const Vector3 direction = Vector3::Zero;
        return position + (direction * radius * scale * Math::Random(0.0f, 1.0f));
    }

    float ParticleSpawnSphere::GetRadius() const
    {
        return radius;
    }

    void ParticleSpawnSphere::SetRadius(float value)
    {
        radius = value;
    }
}