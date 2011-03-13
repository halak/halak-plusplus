#pragma once
#ifndef __HALAK_PARALLELTIMELINE_WINDOWS_H__
#define __HALAK_PARALLELTIMELINE_WINDOWS_H__

#   include <Halak/FWD.h>
#   include <Halak/BuildConfiguration.h>
#   include <Halak/Timeline.h>

#   if (defined(HALAK_PLATFORM_WINDOWS))

        namespace Halak
        {
            class ParallelTimeline : public Timeline
            {
                public:
                    ParallelTimeline();
                    explicit ParallelTimeline(uint id);
                    virtual ~ParallelTimeline();

                protected:
                    virtual void OnStatusChanged(Status old);

                private:
            };
        }

#       include <Halak/ParallelTimeline.Windows.inl>

#   endif

#endif