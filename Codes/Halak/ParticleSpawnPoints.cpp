#include <Halak/PCH.h>
#include <Halak/ParticleSpawnPoints.h>
#include <Halak/Math.h>
#include <random>

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

    Vector3 ParticleSpawnSegment::Spawn(Vector3 position, Quaternion rotation, float scale) const
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

    Vector3 ParticleSpawnBox::Spawn(Vector3 position, Quaternion rotation, float scale) const
    {
        return Vector3::Zero;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    struct ParticleSpawnSphere::Fields
    {
        std::tr1::mt19937 engine;
        std::tr1::uniform_real<float> generator;

        Fields()
            : generator(0.0f, 1.0f)
        {
        }

        Fields(const Fields& original)
            : engine(original.engine),
              generator(original.generator)
        {
        }
    };

    ParticleSpawnSphere::ParticleSpawnSphere()
        : ParticleSpawnPoint(),
          radius(0.0f),
          m(new Fields())
    {
    }

    ParticleSpawnSphere::ParticleSpawnSphere(const ParticleSpawnSphere& original)
        : ParticleSpawnPoint(original),
          radius(original.radius),
          m(new Fields(*original.m))
    {
    }

    ParticleSpawnSphere::~ParticleSpawnSphere()
    {
        delete m;
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
        const float yaw   = m->generator(m->engine) * Math::TwoPi;
        const float pitch = m->generator(m->engine) * Math::TwoPi;

        const Vector3 direction = Vector3::Zero;
        return position + (direction * radius * scale * m->generator(m->engine));
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