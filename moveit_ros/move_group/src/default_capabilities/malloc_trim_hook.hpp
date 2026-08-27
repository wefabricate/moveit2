#pragma once


#if defined(__GLIBC__)
#include <cstdlib>
#include <malloc.h>
#endif

namespace move_group
{
    
    /** Returns free glibc arena pages back to the OS. Call at end of a request, never mid-plan. */
    inline void trimHeapAfterRequest()
    {
        #if defined(__GLIBC__)

        static const bool enabled = std::getenv("MOVEIT_NO_MALLOC_TRIM") == nullptr;
        if (enabled)
        {
            malloc_trim(0);
        }
        
        #endif
    }
    
} // namespace move_group