#ifndef __HALAK_GARBAGEMAN_H__
#define __HALAK_GARBAGEMAN_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <list>

    namespace Halak
    {
        /// summary : IDisposable instance들을 일괄적으로 파기하는 Component.
        /// see : IDisposable
        class GarbageMan : public GameComponent
        {
            public:
                typedef std::list<IDisposableWeakPtr> DisposableCollection;

            public:
                GarbageMan();

                void DisposeAll();

                void Add(IDisposableWeakPtr item);
                bool Remove(IDisposableWeakPtr item);
                void Clear();
                bool Contains(IDisposableWeakPtr item) const;

                const DisposableCollection& GetEntries() const;

            private:
                virtual ~GarbageMan();

            private:
                DisposableCollection entries;
        };
    }

#endif