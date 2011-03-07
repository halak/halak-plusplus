#pragma once
#ifndef __HALAK_SPATIALOBJECT_H__
#define __HALAK_SPATIALOBJECT_H__

#   include <Halak/FWD.h>
#   include <Halak/ISpatial.h>
#   include <Halak/IRevisable.h>

    namespace Halak
    {
        class SpatialObject : public ISpatial, public IRevisable
        {
            public:
                SpatialObject();
                SpatialObject(Vector3 position);
                SpatialObject(Vector3 position, Quaternion rotation, float scale);
                virtual ~SpatialObject();

                virtual Vector3 GetPosition();
                virtual void SetPosition(Vector3 value);

                virtual Quaternion GetRotation();
                virtual void SetRotation(Quaternion value);

                virtual float GetScale();
                virtual void  SetScale(float value);

                virtual uint GetRevision() const;

            private:
                Vector3 position;
                Quaternion rotation;
                float scale;
                uint revision;
        };
    }

#endif