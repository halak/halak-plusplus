#include <Halak/PCH.h>
#include <Halak/ParallelTimeline.Windows.h>

#if (defined(HALAK_PLATFORM_WINDOWS))

    namespace Halak
    {
        ParallelTimeline::ParallelTimeline()
        {
        }

        ParallelTimeline::ParallelTimeline(uint id)
            : Timeline(id)
        {
        }
        
        ParallelTimeline::~ParallelTimeline()
        {
        }

        void ParallelTimeline::OnStatusChanged(Status /*old*/)
        {
        }
    }

#endif