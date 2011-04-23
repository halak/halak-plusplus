#include <Halak/PCH.h>
#include <Halak/UIDomain.h>
#include <Halak/UIWindow.h>

namespace Halak
{
    UIDomain::UIDomain()
        : root(nullptr)
    {
    }
    
    UIDomain::UIDomain(UIWindow* root)
        : root(root)
    {
    }

    UIDomain::~UIDomain()
    {
    }

    UIWindow* UIDomain::GetRoot() const
    {
        return root;
    }

    void UIDomain::SetRoot(UIWindow* value)
    {
        root = value;
    }
}