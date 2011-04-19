#include <Halak/PCH.h>
#include <Halak/FileSystem.h>

namespace Halak
{
    FileSystem::FileSystem()
    {
    }

    FileSystem::FileSystem(uint32 id)
        : GameComponent(id)
    {
    }

    FileSystem::~FileSystem()
    {
    }
}