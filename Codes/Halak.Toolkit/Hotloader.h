#pragma once
#ifndef __HALAK_HOTLOADER_H__
#define __HALAK_HOTLOADER_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/IUpdateable.h>
#   include <Halak/String.h>
#   include <set>

    namespace Halak
    {
        /// Summary :
        ///   Filesystem�� �����Ͽ� Ư�� File�� �ٲ��,
        ///   �ش� File�� �������� �ϴ� Asset���� Reload�� �����ϴ� Component�Դϴ�.
        class Hotloader : public GameComponent, public IUpdateable
        {
            public:
                typedef std::set<IReloadableWeakPtr> ReloadableCollection;

            public:
                Hotloader();

                virtual void Update(float dt, uint timestamp);

                void ReloadAll();

                void Add(IReloadableWeakPtr item);
                bool Remove(IReloadableWeakPtr item);
                void Clear();
                bool Contains(IReloadableWeakPtr item) const;

                /// Summary : �����ϰ� �ִ� Directory ��θ� �������ų� �����մϴ�.
                const String& GetDirectory() const;
                void SetDirectory(const String& value);

                /// Summary : File�� ������ �ٲ�� �ٷ� Reload���� ���θ� �������ų� �����մϴ�.
                bool GetAutoReload() const;
                void SetAutoReload(bool value);

                /// Summary : ���� Filesystem�� �����ϰ� �ִ��� Ȯ���մϴ�.
                bool IsWatching() const;

                const ReloadableCollection& GetEntries() const;
                const ReloadableCollection& GetChangedEntries() const;

            protected:
                virtual ~Hotloader();

            private:
                /// Summary : Windows�� ���� �����ϰ� ������ Directory ��θ� �����ɴϴ�.
                const String& GetPlatformSpecificDirectory() const;
                /// Summary : ���� Thread�� �����մϴ�. (Method ���ο��� Thread�� ����� ������ ����մϴ�)
                void CloseWatcherThread();

            private:
                struct Fields;
                Fields* mPointer;
                Fields& m;
        };
    }

#endif