#ifndef __HALAK_NUMBERPROPERTY_H__
#define __HALAK_NUMBERPROPERTY_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <Halak.wxToolkit/IPropertyUpdateable.h>
#   include <wx/propgrid/propgrid.h>
#   include <wx/propgrid/propdev.h>

    namespace Halak
    {
        namespace wxToolkit
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