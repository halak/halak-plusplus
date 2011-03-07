#include <Halak.wxToolkit/NumberProperty.h>
#include <Halak/AnyPtr.h>
#include <Halak/CommandHistory.h>
#include <Halak/PropertyInfo.h>
using namespace Halak;

namespace Halak
{
    namespace wxToolkit
    {
        WX_PG_IMPLEMENT_PROPERTY_CLASS(NumberProperty, wxFloatProperty, double, double, TextCtrl)

        NumberProperty::NumberProperty(const wxString& label, const wxString& name, CommandHistory* history, const PropertyInfo* propertyInfo)
            : wxFloatProperty(label, name),
              history(history),
              propertyInfo(propertyInfo)
        {
        }
        
        NumberProperty::~NumberProperty()
        {
        }

        void NumberProperty::UpdateTo(const AnyPtrCollection& targets)
        {
            const double value = m_value.GetDouble();
            IPropertyUpdateable::UpdateTo(history, targets, propertyInfo, value);
        }

        void NumberProperty::UpdateFrom(const AnyPtrCollection& targets)
        {
            if (targets.empty() == false)
                SetValue(propertyInfo->GetValue<double>(targets.front()));
        }
   }
}