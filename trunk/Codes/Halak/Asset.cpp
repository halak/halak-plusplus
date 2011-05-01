#include <Halak/PCH.h>
#include <Halak/Asset.h>

namespace Halak
{
    Asset::Asset()
        : uri(URI::Empty)
    {
    }

    Asset::Asset(const URI& uri)
        : uri(uri)
    {
    }

    Asset::~Asset()
    {
    }
}