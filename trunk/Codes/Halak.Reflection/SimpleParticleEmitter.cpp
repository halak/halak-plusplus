#include <Halak/SimpleParticleEmitter.h>
#include <Halak/Attributes.h>
#include <Halak/RegistrationContexts.h>

namespace Halak
{
    void SimpleParticleEmitter::__Startup__()
    {
        Class<SimpleParticleEmitter>()
            .SetID(HKMakeFOURCC('S','P','E','M'), "Halak", "SimpleParticleEmitter")
            .Inherits<ParticleEmitter>()
            .Add(new ConstructorInfo(ConstructorInfo::Make<SimpleParticleEmitter>())).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('L','I','F','1'), "Lifespan1", &GetLifespan1, &SetLifespan1))
                .Add(new UnitAttribute("Seconds"))
                .Close()
            .Add(new PropertyInfo(HKMakeFOURCC('L','N','F','2'), "Lifespan2", &GetLifespan2, &SetLifespan2))
                .Add(new UnitAttribute("Seconds"))
                .Close()
            .Add(new PropertyInfo(HKMakeFOURCC('L','N','V','1'), "LinearVelocity1", &GetLinearVelocity1, &SetLinearVelocity1)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('L','N','V','2'), "LinearVelocity2", &GetLinearVelocity2, &SetLinearVelocity2)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('L','N','A','1'), "LinearAccelerationForce1", &GetLinearAccelerationForce1, &SetLinearAccelerationForce1)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('L','N','A','2'), "LinearAccelerationForce2", &GetLinearAccelerationForce2, &SetLinearAccelerationForce2)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('R','O','T','1'), "Rotation1", &GetRotation1, &SetRotation1)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('R','O','T','2'), "Rotation2", &GetRotation2, &SetRotation2)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('A','G','V','1'), "AngularVelocity1", &GetAngularVelocity1, &SetAngularVelocity1)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('A','G','V','2'), "AngularVelocity2", &GetAngularVelocity2, &SetAngularVelocity2)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('A','G','A','1'), "AngularAccelerationForce1", &GetAngularAccelerationForce1, &SetAngularAccelerationForce1)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('A','G','A','2'), "AngularAccelerationForce2", &GetAngularAccelerationForce2, &SetAngularAccelerationForce2)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('S','C','L','1'), "Scale1", &GetScale1, &SetScale1)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('S','C','L','2'), "Scale2", &GetScale2, &SetScale2)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('S','T','V','1'), "StrainVelocity1", &GetStrainVelocity1, &SetStrainVelocity1)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('S','T','V','2'), "StrainVelocity2", &GetStrainVelocity2, &SetStrainVelocity2)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('S','T','A','1'), "StrainAccelerationForce1", &GetStrainAccelerationForce1, &SetStrainAccelerationForce1)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('S','T','A','2'), "StrainAccelerationForce2", &GetStrainAccelerationForce2, &SetStrainAccelerationForce2)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('S','T','N','1'), "StartTint1", &GetStartTint1, &SetStartTint1)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('S','T','N','2'), "StartTint2", &GetStartTint2, &SetStartTint2)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('E','T','N','1'), "EndTint1", &GetEndTint1, &SetEndTint1)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('E','T','N','2'), "EndTint2", &GetEndTint2, &SetEndTint2)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('L','C','O','D'), "LocalCoordinates", &GetLocalCoordinates, &SetLocalCoordinates)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('R','T','K','S'), "RatioKeepScale", &GetRatioKeepScale, &SetRatioKeepScale)).Close()
            .Add(new PropertyInfo(HKMakeFOURCC('S','P','R','P'), "SpritePalette", &GetSpritePalette, &SetSpritePalette)).Close();
    }
}