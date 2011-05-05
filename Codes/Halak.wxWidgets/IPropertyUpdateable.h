#pragma once
#ifndef __HALAK_WXWIDGETS_PROPERTYUPDATEABLE_INTERFACE__
#define __HALAK_WXWIDGETS_PROPERTYUPDATEABLE_INTERFACE__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/AnyPtr.h>
#   include <vector>

    namespace Halak
    {
        namespace wxWidgets
        {
            class IPropertyUpdateable
            {
                public:
                    typedef std::vector<Halak::Toolkit::AnyPtr> AnyPtrCollection;

                public:
                    virtual ~IPropertyUpdateable() { }

                    virtual void UpdateTo(const AnyPtrCollection& targets) = 0;
                    virtual void UpdateFrom(const AnyPtrCollection& targets) = 0;

                public:
                    static void UpdateTo(CommandHistory* history, const AnyPtrCollection& targets, const Halak::Toolkit::PropertyInfo* propertyInfo, const Any& value);
            };
        }
    }

#endif