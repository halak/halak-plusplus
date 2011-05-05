#include <Halak.wxWidgets/PCH.h>
#include <Halak.wxWidgets/wxNumberProperty.h>
#include <Halak.Toolkit/AnyPtr.h>
#include <Halak.Toolkit/PropertyInfo.h>
#include <Halak/CommandHistory.h>
using namespace Halak;
using namespace Halak::Toolkit;

namespace Halak
{
    namespace wxWidgets
    {
        WX_PG_IMPLEMENT_PROPERTY_CLASS(wxNumberProperty, wxFloatProperty, double, double, TextCtrl)

        wxNumberProperty::wxNumberProperty(const wxString& label, const wxString& name, CommandHistory* history, const PropertyInfo* propertyInfo)
            : wxFloatProperty(label, name),
              history(history),
              propertyInfo(propertyInfo)
        {
        }
        
        wxNumberProperty::~wxNumberProperty()
        {
        }

        void wxNumberProperty::UpdateTo(const AnyPtrCollection& targets)
        {
            const double value = m_value.GetDouble();
            IPropertyUpdateable::UpdateTo(history, targets, propertyInfo, value);
        }

        void wxNumberProperty::UpdateFrom(const AnyPtrCollection& targets)
        {
            if (targets.empty() == false)
                SetValue(propertyInfo->GetValue<double>(targets.front()));
        }
   }
}