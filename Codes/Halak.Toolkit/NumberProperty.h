#pragma once
#ifndef __HALAK_TOOLKIT_NUMBERPROPERTY_H__
#define __HALAK_TOOLKIT_NUMBERPROPERTY_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/IPropertyUpdateable.h>
#   include <wx/propgrid/propgrid.h>
#   include <wx/propgrid/propdev.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class NumberProperty : public wxFloatProperty, public IPropertyUpdateable
            {
                WX_PG_DECLARE_PROPERTY_CLASS(NumberProperty)
                public:
                    NumberProperty(const wxString& label = wxPG_LABEL, const wxString& name = wxPG_LABEL, CommandHistory* history = nullptr, const PropertyInfo* propertyInfo = nullptr);
                    virtual ~NumberProperty();

                    virtual void UpdateTo(const AnyPtrCollection& targets);
                    virtual void UpdateFrom(const AnyPtrCollection& targets);

                private:
                    CommandHistory* history;
                    const PropertyInfo* propertyInfo;

            };
        }
    }

#endif