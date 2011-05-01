#pragma once
#ifndef __HALAK_UPDATEABLEOBJECT_H__
#define __HALAK_UPDATEABLEOBJECT_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>
#   include <Halak/IUpdateable.h>

    namespace Halak
    {
        class UpdateableObject : public SharedObject, public IUpdateable
        {
            public:
                UpdateableObject();
                virtual ~UpdateableObject();

                inline Timeline* GetTimeline() const;
                void SetTimeline(Timeline* value);

            protected:
                inline bool Seal(uint timestamp);

            private:
                Timeline* timeline;
                uint lastTimestamp;
        };
    }

#endif