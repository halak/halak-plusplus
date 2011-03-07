#pragma once
#ifndef __HALAK_SPATIALOBJECT2D_H__
#define __HALAK_SPATIALOBJECT2D_H__

#   include <Halak/FWD.h>
#   include <Halak/ISpatial2D.h>
#   include <Halak/IRevisable.h>

    namespace Halak
    {
        class SpatialObject2D : public ISpatial2D, public IRevisable
        {
            public:
                SpatialObject2D();
                SpatialObject2D(Vector2 position);
                SpatialObject2D(Vector2 position, float rotation, float scale);
                virtual ~SpatialObject2D();

                virtual Vector2 GetPosition();
                virtual void SetPosition(Vector2 value);

                virtual float GetRotation();
                virtual void  SetRotation(float value);

                virtual float GetScale();
                virtual void  SetScale(float value);

                virtual uint GetRevision() const;

            private:
                Vector2 position;
                float rotation;
                float scale;
                uint revision;
        };
    }

#endif