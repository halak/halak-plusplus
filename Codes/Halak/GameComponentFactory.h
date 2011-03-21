#pragma once
#ifndef __HALAK_GAMECOMPONENTFACTORY_H__
#define __HALAK_GAMECOMPONENTFACTORY_H__

#    include <Halak/FWD.h>

    namespace Halak
    {
        class GameComponentFactory
        {
            HKThisIsStaticClass(GameComponentFactory);
            public:
                typedef GameComponent* (*CreateFunction)();

            public:
                static GameComponent* Create(uint32 id);

                template <typename T> static void AddEntry();
                static void AddEntry(uint32 id, CreateFunction function);
                static void SortEntries();
        };
    }

#    include <Halak/GameComponentFactory.inl>

#endif