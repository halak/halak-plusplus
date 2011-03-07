#pragma once
#ifndef __HALAK_CLONINGCONTEXT_INL__
#define __HALAK_CLONINGCONTEXT_INL__

#   include <Halak/ICloneable.h>

    namespace Halak
    {
        CloningContext::CloningContext()
        {
        }

        CloningContext::~CloningContext()
        {
        }

        template <typename T> T* CloningContext::CloneActually(T* original, T* fallback)
        {
            if (original == nullptr)
                return nullptr;

            if (ICloneable* cloneableOriginal = dynamic_cast<ICloneable*>(original))
            {
                std::map<ICloneable*, ICloneable*>::iterator it = clones.find(cloneableOriginal);
                if (it != clones.end())
                    return dynamic_cast<T*>((*it).second);
                else
                {
                    ICloneable* clone = cloneableOriginal->Clone();
                    clones.insert(std::map<ICloneable*, ICloneable*>::value_type(cloneableOriginal, clone));
                    return dynamic_cast<T*>(clone);
                }
            }
            else
                return fallback;
        }

        template <typename T> shared_ptr<T> CloningContext::CloneActually(shared_ptr<T> original, shared_ptr<T> fallback)
        {
            if (original == nullptr)
                return nullptr;

            if (ICloneablePtr cloneableOriginal = dynamic_pointer_cast<ICloneable>(original))
            {
                std::map<ICloneablePtr, ICloneablePtr>::iterator it = sharedClones.find(cloneableOriginal);
                if (it != sharedClones.end())
                    return dynamic_pointer_cast<T>((*it).second);
                else
                {
                    ICloneablePtr clone(cloneableOriginal->Clone());
                    sharedClones.insert(std::map<ICloneablePtr, ICloneablePtr>::value_type(cloneableOriginal, clone));
                    return dynamic_pointer_cast<T>(clone);
                }
            }
            else
                return fallback;
        }

        template <typename T> T* CloningContext::Clone(T* original)
        {
            return CloneActually(original, original);
        }

        template <typename T> T* CloningContext::CloneOrNull(T* original)
        {
            return CloneActually(original, nullptr);
        }

        template <typename T> shared_ptr<T> CloningContext::Clone(shared_ptr<T> original)
        {
            return CloneActually(original, original);
        }

        template <typename T> shared_ptr<T> CloningContext::CloneOrNull(shared_ptr<T> original)
        {
            return CloneActually(original, nullptr);
        }

        template <typename T> weak_ptr<T> CloningContext::Clone(weak_ptr<T> original)
        {
            return CloneActually(original.lock(), original.lock());
        }

        template <typename T> weak_ptr<T> CloningContext::CloneOrNull(weak_ptr<T> original)
        {
            return CloneActually(original.lock(), nullptr);
        }
    }

#endif