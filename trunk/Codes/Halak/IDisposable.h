#ifndef __HALAK_DISPOSABLE_INTERFACE__
#define __HALAK_DISPOSABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        /// summary : �������� ��� �ı��ϴ� Dispose Method�� �����ϴ� Interface.
        /// see : GarbageMan
        ///
        /// �����ϴ� ��ü���� ����/���� �������� ��� �ı��մϴ�.
        /// ������ �ı�� �⺻������ �Ҹ��ڿ��� �ı��ϴ� ���� ��Ģ���� �ϰ� ������,
        /// ���� ���� �������� ���� �����ص� ���� �����ϴ�.
        /// ������ shared_ptr�� �̿��� ���� �������� �ı�� Dispose �ȿ��� �ϴ� ���� �����մϴ�.
        /// shared_ptr�� �̿��Ͽ� ��ȣ������ �� ��쿡�� instance�� �Ҹ���� �ʱ� ������,
        /// Dispose���� ������ ���� �������� �ı��ؾ��մϴ�.
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