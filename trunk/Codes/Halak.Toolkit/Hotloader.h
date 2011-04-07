#pragma once
#ifndef __HALAK_TOOLKIT_HOTLOADER_H__
#define __HALAK_TOOLKIT_HOTLOADER_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/IUpdateable.h>
#   include <Halak/String.h>
#   include <set>

    namespace Halak
    {
        namespace Toolkit
        {
            /// Summary :
            ///   Filesystem을 감시하여 특정 File이 바뀌면,
            ///   해당 File을 원본으로 하는 Asset에게 Reload를 통지하는 Component입니다.
            class Hotloader : public GameComponent, public IUpdateable
            {
                HKDeclareGameComponentClassFOURCC('H', 'L', 'D', 'R');
                public:
                    typedef std::set<IReloadableWeakPtr> ReloadableCollection;

                public:
                    Hotloader();
                    virtual ~Hotloader();

                    virtual void Update(float dt, uint timestamp);

                    void ReloadAll();

                    void Add(IReloadableWeakPtr item);
                    bool Remove(IReloadableWeakPtr item);
                    void Clear();
                    bool Contains(IReloadableWeakPtr item) const;

                    /// Summary : 감시하고 있는 Directory 경로를 가져오거나 설정합니다.
                    const String& GetDirectory() const;
                    void SetDirectory(const String& value);

                    /// Summary : File의 내용이 바뀌면 바로 Reload할지 여부를 가져오거나 설정합니다.
                    bool GetAutoReload() const;
                    void SetAutoReload(bool value);

                    /// Summary : 현재 Filesystem을 감시하고 있는지 확인합니다.
                    bool IsWatching() const;

                    const ReloadableCollection& GetEntries() const;
                    const ReloadableCollection& GetChangedEntries() const;

                private:
                    /// Summary : Windows에 가장 적합하게 조정된 Directory 경로를 가져옵니다.
                    const String& GetPlatformSpecificDirectory() const;
                    /// Summary : 감시 Thread를 종료합니다. (Method 내부에서 Thread가 종료될 때까지 대기합니다)
                    void CloseWatcherThread();

                private:
                    struct Fields;
                    Fields* mPointer;
                    Fields& m;
            };
        }
    }

#endif