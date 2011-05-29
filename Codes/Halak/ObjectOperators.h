#pragma once
#ifndef __HALAK_OBJECTOPERATORS_H__
#define __HALAK_OBJECTOPERATORS_H__

#   include <Halak/FWD.h>
#   include <Halak/Any.h>
#   include <Halak/GameComponent.h>

    namespace Halak
    {
        /// void*로 upcast된 객체를 조작하는 객체.
        /// 위험한 객체기 때문에 조심하여 사용해야합니다.
        class ObjectOperator : public GameComponent
        {
            HKClassFOURCC('O', 'B', 'O', 'P');
            public:
                ObjectOperator();
                virtual ~ObjectOperator() { }

                virtual Any Command(void* object, const String& name, const Any& arg1, const Any& arg2, const Any& arg3, const Any& arg4);

                virtual void Destruct(void* object) = 0;
        };

        class GameComponentOperator : public ObjectOperator
        {
            HKClassFOURCC('G', 'C', 'O', 'P');
            public:
                GameComponentOperator();
                virtual ~GameComponentOperator() { }

                virtual void Destruct(void* object);
        };

        class SharedObjectOperator : public ObjectOperator
        {
            HKClassFOURCC('S', 'O', 'O', 'P');
            public:
                SharedObjectOperator();
                virtual ~SharedObjectOperator() { }

                virtual void Destruct(void* object);
        };

        template <typename T, uint32 ClassID> class StructOperator : public ObjectOperator
        {
            HKClassID(ClassID);
            public:
                virtual ~StructOperator() { }

                virtual void Destruct(void* object);
        };
    }

#   include <Halak/ObjectOperators.inl>

#endif