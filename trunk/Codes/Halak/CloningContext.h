#pragma once
#ifndef __HALAK_CLONINGCONTEXT_H__
#define __HALAK_CLONINGCONTEXT_H__

#   include <Halak/FWD.h>
#   include <map>

    namespace Halak
    {
        class CloningContext
        {
            public:
                inline CloningContext();
                inline ~CloningContext();

                template <typename T> inline T* Clone(T* original);
                template <typename T> inline T* CloneOrNull(T* original);
                template <typename T> inline shared_ptr<T> Clone(shared_ptr<T> original);
                template <typename T> inline shared_ptr<T> CloneOrNull(shared_ptr<T> original);
                template <typename T> inline weak_ptr<T> Clone(weak_ptr<T> original);
                template <typename T> inline weak_ptr<T> CloneOrNull(weak_ptr<T> original);

            private:
                template <typename T> inline T* CloneActually(T* original, T* fallback);
                template <typename T> inline shared_ptr<T> CloneActually(shared_ptr<T> original, shared_ptr<T> fallback);

            private:
                std::map<ICloneable*, ICloneable*> clones;
                std::map<ICloneablePtr, ICloneablePtr> sharedClones;
        };
    }

#   include <Halak/CloningContext.inl>

#endif