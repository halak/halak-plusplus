#pragma once
#ifndef __HALAK_TOOLKIT_VECTOR3PROPERTY_H__
#define __HALAK_TOOLKIT_VECTOR3PROPERTY_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/IPropertyUpdateable.h>
#   include <Halak/Vector3.h>
#   include <wx/propgrid/propgrid.h>
#   include <wx/propgrid/propdev.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class Vector3Property : public wxPGProperty, public IPropertyUpdateable
            {
                WX_PG_DECLARE_PROPERTY_CLASS(Vector3Property)
                public:
                    Vector3Property(const wxString& label = wxPG_LABEL, const wxString& name = wxPG_LABEL, CommandHistory* history = nullptr, const PropertyInfo* propertyInfo = nullptr);
                    virtual ~Vector3Property();

                    virtual void UpdateTo(const AnyPtrCollection& targets);
                    virtual void UpdateFrom(const AnyPtrCollection& targets);

                    WX_PG_DECLARE_BASIC_TYPE_METHODS()
                    WX_PG_DECLARE_PARENTAL_METHODS()

                private:
                    CommandHistory* history;
                    const PropertyInfo* propertyInfo;
            };
        }
    }

#endif