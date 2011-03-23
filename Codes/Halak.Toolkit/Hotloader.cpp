#include <Halak/Hotloader.h>
#include <Halak/IReloadable.h>
#include <Halak/Internal/WindowsError.h>
#include <algorithm>
#include <list>
#include <vector>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace Halak
{
    struct Hotloader::Fields
    {
        HANDLE watcherThreadHandle;
        bool watcherThreadStopped;
        std::list<String> changedFiles;

        Hotloader::ReloadableCollection entries;
        Hotloader::ReloadableCollection changedEntries;
        String directory;
        String platformSpecificDirectory;
        bool autoReload;

        Fields()
            : watcherThreadHandle(nullptr),
              watcherThreadStopped(true),
              autoReload(true)
        {
        }

        struct Overlapped : OVERLAPPED
        {
            Hotloader* Owner;
            HANDLE DirectoryHandle;
            byte Buffer[1024 * 4];
        };

        static DWORD WINAPI   WatchFilesystem(LPVOID tag);
        static VOID  CALLBACK WatchFilesystemIOCallback(DWORD dwErrorCode, DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped);
    };

    Hotloader::Hotloader()
        : mPointer(new Fields()),
          m(*mPointer)
    {
    }

    Hotloader::~Hotloader()
    {
        CloseWatcherThread();
        Clear();
        delete mPointer;
    }

    void Hotloader::Update(float /*dt*/, uint /*timestamp*/)
    {
        // 변경된 File을 원본으로 하는 Asset을 찾아 '변경된 Asset' 목록에 추가합니다.
        std::list<String> temporaryChangedFiles;
        temporaryChangedFiles.swap(m.changedFiles);
        for (std::list<String>::iterator it = temporaryChangedFiles.begin(); it != temporaryChangedFiles.end(); it++)
        {
            for (ReloadableCollection::iterator itHotloadable = m.entries.begin(); itHotloadable != m.entries.end(); itHotloadable++)
            {
                IReloadableWeakPtr item = (*itHotloadable);
                if (item.IsAlive())
                {
                    if (item.Lock()->GetFilename().EqualsIgnoreCase(*it))
                    {
                        m.changedEntries.insert(item);
                        break;
                    }
                }
                else
                    m.entries.erase(itHotloadable++);
            }
        }

        // 변경된 Asset이 있으면 새로 불러옵니다.
        if (GetAutoReload() && m.changedEntries.empty() == false)
            ReloadAll();
    }

    void Hotloader::ReloadAll()
    {
        ReloadableCollection reloadingEntries;
        reloadingEntries.swap(m.changedEntries);

        for (ReloadableCollection::iterator it = reloadingEntries.begin(); it != reloadingEntries.end(); it++)
        {
            IReloadableWeakPtr item = (*it);
            if (item.IsAlive())
                item.Lock()->Reload();
            else
                m.entries.erase(item);
        }
    }

    void Hotloader::Add(IReloadableWeakPtr item)
    {
        if (item.IsAlive() == false)
            throw std::invalid_argument("item is nullptr");

        m.entries.insert(item);
    }

    bool Hotloader::Remove(IReloadableWeakPtr item)
    {
        if (item.IsAlive() == false)
            return false;

        if (m.entries.erase(item))
        {
            m.changedEntries.erase(item);
            return true;
        }
        else
            return false;
    }

    void Hotloader::Clear()
    {
        m.entries.clear();
        m.changedEntries.clear();
        m.changedFiles.clear();
    }

    bool Hotloader::Contains(IReloadableWeakPtr item) const
    {
        return m.entries.find(item) != m.entries.end();
    }

    const String& Hotloader::GetDirectory() const
    {
        return m.directory;
    }

    void Hotloader::SetDirectory(const String& value)
    {
        if (GetDirectory().EqualsIgnoreCase(value) == false)
        {
            m.directory = value;

            // Platform에 적합한 경로로 변환합니다.
            m.platformSpecificDirectory = m.directory;
            m.platformSpecificDirectory.Replace('/', '\\');
            if (m.platformSpecificDirectory[m.platformSpecificDirectory.GetLength() - 1] != '\\')
                m.platformSpecificDirectory += "\\";

            // 기존 Thread를 닫고, 새 Thread를 생성하여 시작합니다.
            CloseWatcherThread();

            m.watcherThreadHandle = CreateThread(NULL, 0, &Hotloader::Fields::WatchFilesystem, this, 0x00000000, NULL);
            if (m.watcherThreadHandle)
            {
                SetThreadPriority(m.watcherThreadHandle, THREAD_PRIORITY_LOWEST);
                m.watcherThreadStopped = false;
            }
            else
                m.watcherThreadStopped = true;
        }
    }

    const String& Hotloader::GetPlatformSpecificDirectory() const
    {
        return m.platformSpecificDirectory;
    }

    bool Hotloader::GetAutoReload() const
    {
        return m.autoReload;
    }

    void Hotloader::SetAutoReload(bool value)
    {
        m.autoReload = value;
    }

    bool Hotloader::IsWatching() const
    {
        return m.watcherThreadStopped == false;
    }

    const Hotloader::ReloadableCollection& Hotloader::GetEntries() const
    {
        return m.entries;
    }
    
    const Hotloader::ReloadableCollection& Hotloader::GetChangedEntries() const
    {
        return m.changedEntries;
    }

    void Hotloader::CloseWatcherThread()
    {
        // watcherThreadStopped을 true로 설정하고, Thread 종료를 기다립니다.
        // Thread에서는 watcherThreadStopped가 true이면 자동으로 종료됩니다.
        m.watcherThreadStopped = true;
        WaitForSingleObject(m.watcherThreadHandle, INFINITE);

        CloseHandle(m.watcherThreadHandle);
    }

    DWORD WINAPI Hotloader::Fields::WatchFilesystem(LPVOID tag)
    {
        Hotloader* owner = reinterpret_cast<Hotloader*>(tag);

        HANDLE directoryHandle = CreateFile(owner->GetPlatformSpecificDirectory().CStr(), FILE_LIST_DIRECTORY, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                                            NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED, NULL);
        if (directoryHandle == INVALID_HANDLE_VALUE)
            return 0;

        Overlapped* overlapped = reinterpret_cast<Overlapped*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(Overlapped)));
        overlapped->hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
        overlapped->Owner = owner;
        overlapped->DirectoryHandle = directoryHandle;

        // Filesystem 감시는 비동기로 수행하며 통지는 Hotloader::WatchFilesystemIOCallback로 받습니다.
        if (ReadDirectoryChangesW(directoryHandle, overlapped->Buffer, sizeof(overlapped->Buffer),
                                  TRUE, FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_CREATION, NULL, overlapped, &Hotloader::Fields::WatchFilesystemIOCallback))
        {
            while (owner->m.watcherThreadStopped == false)
            {
                MsgWaitForMultipleObjectsEx(0, NULL, 1, QS_ALLINPUT, MWMO_ALERTABLE);
            }
        }
        else
        {
            String result = GetWindowsErrorMessage(GetLastError());
            //#LOGGING

            owner->m.watcherThreadStopped = true;
        }

        CancelIo(directoryHandle);

        if (HasOverlappedIoCompleted(overlapped) == FALSE)
            SleepEx(5, TRUE);

        CloseHandle(overlapped->hEvent);
        HeapFree(GetProcessHeap(), 0x00000000, overlapped);

        CloseHandle(directoryHandle);

        return 0;
    }

    VOID CALLBACK Hotloader::Fields::WatchFilesystemIOCallback(DWORD errorCode, DWORD numberOfBytesTransfered, LPOVERLAPPED baseOverlapped)
    {
        Overlapped* overlapped = static_cast<Overlapped*>(baseOverlapped);

        if (errorCode == ERROR_SUCCESS)
        {
            const String directory = overlapped->Owner->GetPlatformSpecificDirectory();
            const FILE_NOTIFY_INFORMATION* notification = nullptr;
            DWORD offset = 0;

            do
            {
                notification = reinterpret_cast<const FILE_NOTIFY_INFORMATION*>(&overlapped->Buffer[offset]);
                if (notification->Action == FILE_ACTION_ADDED ||
                    notification->Action == FILE_ACTION_MODIFIED ||
                    notification->Action == FILE_ACTION_RENAMED_NEW_NAME)
                {
                    std::vector<char> filepath;
                    filepath.resize(notification->FileNameLength * 2, '\0');

                    WideCharToMultiByte(CP_ACP, 0,
                                        notification->FileName, notification->FileNameLength / sizeof(WCHAR),
                                        &filepath[0], filepath.size() - 1,
                                        NULL, NULL);

                    static const String CurrentDirectoryPath = ".\\";
                    if (directory != CurrentDirectoryPath)
                        overlapped->Owner->m.changedFiles.push_back(directory + String(&filepath[0]));
                    else
                        overlapped->Owner->m.changedFiles.push_back(String(&filepath[0]));
                }
                offset += notification->NextEntryOffset;
            } while (notification->NextEntryOffset != 0 && offset < numberOfBytesTransfered);
        }

        // WatcherThread가 살아있다면 반복해서 Filesytem을 감시합니다.
        if (overlapped->Owner->m.watcherThreadStopped == false)
        {
            if (ReadDirectoryChangesW(overlapped->DirectoryHandle, overlapped->Buffer, sizeof(overlapped->Buffer),
                                      TRUE, FILE_NOTIFY_CHANGE_LAST_WRITE, NULL, overlapped, &Hotloader::Fields::WatchFilesystemIOCallback) == FALSE)
            {
                String result = GetWindowsErrorMessage(GetLastError());
                //#LOGGING

                overlapped->Owner->m.watcherThreadStopped = true;
            }
        }
    }
}