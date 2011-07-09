#pragma once
#ifndef __HALAK_UPDATEABLEGAMECOMPONENT_H__
#define __HALAK_UPDATEABLEGAMECOMPONENT_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/IUpdateable.h>

    namespace Halak
    {
        class UpdateableGameComponent : public GameComponent, public IUpdateable
        {
            HKClassFOURCC('U', 'P', 'G', 'C');
            public:
                UpdateableGameComponent();
                virtual ~UpdateableGameComponent();

                inline Timeline* GetTimeline() const;
                void SetTimeline(Timeline* value);

                virtual IUpdateable* QueryUpdateableInterface();

            protected:
                inline bool Seal(uint timestamp);

            private:
                Timeline* timeline;
                uint lastTimestamp;
        };
    }

#    include <Halak/UpdateableGameComponent.inl>

#endif