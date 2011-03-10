#pragma once
#ifndef __HALAK_SUBTIMELINE_H__
#define __HALAK_SUBTIMELINE_H__

#   include <Halak/FWD.h>
#   include <Halak/Timeline.h>

    namespace Halak
    {
        class SubTimeline : public Timeline
        {
            public:
                inline SubTimeline();
                inline SubTimeline(uint id);
                virtual ~SubTimeline();

                inline Timeline* GetParent() const;
                void SetParent(Timeline* value);

            private:
                Timeline* parent;
        };
    }

#   include <Halak/SubTimeline.inl>

#endif