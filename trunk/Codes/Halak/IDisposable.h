#ifndef __HALAK_DISPOSABLE_INTERFACE__
#define __HALAK_DISPOSABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        /// summary : 소유권을 모두 파기하는 Dispose Method를 제공하는 Interface.
        /// see : GarbageMan
        ///
        /// 소유하는 객체들의 공유/사유 소유권을 모두 파기합니다.
        /// 소유권 파기는 기본적으로 소멸자에서 파기하는 것을 원칙으로 하고 있으며,
        /// 실제 사유 소유권은 언제 수행해도 관계 없습니다.
        /// 하지만 shared_ptr을 이용한 공유 소유권의 파기는 Dispose 안에서 하는 것을 권장합니다.
        /// shared_ptr를 이용하여 상호참조를 할 경우에는 instance가 소멸되지 않기 때문에,
        /// Dispose에서 강제로 공유 소유권을 파기해야합니다.
        class IDisposable
        {
            public:
                virtual ~IDisposable() { }

                virtual void Dispose() = 0;
        };

        template <typename T> inline bool DyanmicDispose(T* instance);
        template <typename T> inline bool DyanmicDispose(shared_ptr<T> instance);
    }

#   include <Halak/IDisposable.inl>

#endif