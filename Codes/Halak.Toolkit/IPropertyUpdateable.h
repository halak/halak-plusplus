#ifndef __HALAK_WXTOOLKIT_PROPERTYUPDATEABLE_INTERFACE__
#define __HALAK_WXTOOLKIT_PROPERTYUPDATEABLE_INTERFACE__

#   include <Halak.wxToolkit/FWD.h>
#   include <Halak/AnyPtr.h>
#   include <vector>

    namespace Halak
    {
        namespace wxToolkit
        {
            class IPropertyUpdateable
            {
                public:
                    typedef std::vector<AnyPtr> AnyPtrCollection;

                public:
                    virtual ~IPropertyUpdateable() { }

                    virtual void UpdateTo(const AnyPtrCollection& targets) = 0;
                    virtual void UpdateFrom(const AnyPtrCollection& targets) = 0;

                public:
                    static void UpdateTo(CommandHistory* history, const AnyPtrCollection& targets, const PropertyInfo* propertyInfo, const Any& value);
            };
        }
    }

#endif