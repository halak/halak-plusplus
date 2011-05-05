#pragma once
#ifndef __HALAK_WXWIDGETS_NUMBERPROPERTY_H__
#define __HALAK_WXWIDGETS_NUMBERPROPERTY_H__

#   include <Halak.wxWidgets/FWD.h>
#   include <Halak.wxWidgets/IPropertyUpdateable.h>
#   include <wx/propgrid/propgrid.h>
#   include <wx/propgrid/propdev.h>

    namespace Halak
    {
        namespace wxWidgets
        {
            class wxNumberProperty : public wxFloatProperty, public IPropertyUpdateable
            {
                WX_PG_DECLARE_PROPERTY_CLASS(wxNumberProperty)
                public:
                    wxNumberProperty(const wxString& label = wxPG_LABEL, const wxString& name = wxPG_LABEL,
                                     CommandHistory* history = nullptr,
                                     const Halak::Toolkit::PropertyInfo* propertyInfo = nullptr);
                    virtual ~wxNumberProperty();

                    virtual void UpdateTo(const AnyPtrCollection& targets);
                    virtual void UpdateFrom(const AnyPtrCollection& targets);

                private:
                    CommandHistory* history;
                    const Halak::Toolkit::PropertyInfo* propertyInfo;

            };
        }
    }

#endif