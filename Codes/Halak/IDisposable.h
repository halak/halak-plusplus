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
        /// ������ SharedPointer�� �̿��� ���� �������� �ı�� Dispose �ȿ��� �ϴ� ���� �����մϴ�.
        /// SharedPointer�� �̿��Ͽ� ��ȣ������ �� ��쿡�� instance�� �Ҹ���� �ʱ� ������,
        /// Dispose���� ������ ���� �������� �ı��ؾ��մϴ�.
        class IDisposable
        {
            HKInterfaceFOURCC('I', 'D', 'I', 'S');
            public:
                virtual ~IDisposable() { }

                virtual void Dispose() = 0;
        };

#       if (defined(HALAK_RTTI))
            template <typename T> inline bool DyanmicDispose(T* instance);
            template <typename T> inline bool DyanmicDispose(SharedPointer<T> instance);
#       endif
    }

#   include <Halak/IDisposable.inl>

#endif