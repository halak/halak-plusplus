#include <Halak.wxToolkit/Vector3Property.h>
#include <Halak/AnyPtr.h>
#include <Halak/CommandHistory.h>
#include <Halak/PropertyInfo.h>
using namespace Halak;

WX_PG_DECLARE_VARIANT_DATA(Vector3VariantData, Vector3, wxPG_NO_DECL)
WX_PG_IMPLEMENT_VARIANT_DATA(Vector3VariantData, Vector3)

namespace Halak
{
    namespace wxToolkit
    {
        WX_PG_IMPLEMENT_PROPERTY_CLASS(Vector3Property, wxPGProperty, Vector3, const Vector3&, TextCtrl)

        Vector3Property::Vector3Property(const wxString& label, const wxString& name, CommandHistory* history, const PropertyInfo* propertyInfo)
            : wxPGProperty(label, name),
              history(history),
              propertyInfo(propertyInfo)
        {
            AddPrivateChild(new wxFloatProperty("X", wxPG_LABEL, 0.0));
            AddPrivateChild(new wxFloatProperty("Y", wxPG_LABEL, 0.0));
            AddPrivateChild(new wxFloatProperty("Z", wxPG_LABEL, 0.0));
        }
        
        Vector3Property::~Vector3Property()
        {
        }

        void Vector3Property::UpdateTo(const AnyPtrCollection& targets)
        {
            const Vector3 value = Vector3FromVariant(m_value);
            IPropertyUpdateable::UpdateTo(history, targets, propertyInfo, value);
        }

        void Vector3Property::UpdateFrom(const AnyPtrCollection& targets)
        {
            if (targets.empty() == false)
                SetValue(Vector3ToVariant(propertyInfo->GetValue<Vector3>(targets.front())));
        }

        wxString Vector3Property::GetValueAsString(int /*argFlags*/) const
        {
            const Vector3& value = Vector3FromVariant(m_value);
            return wxString::Format("%.4f, %.4f, %.4f", value.X, value.Y, value.Z);
        }

        bool Vector3Property::StringToValue(wxVariant& variant, const wxString& text, int /*argFlags*/) const
        {
            size_t xySeparator = text.find(',', 0);
            size_t yzSeparator = text.find(',', xySeparator + 1);

            Vector3& value = Vector3FromVariant(variant);
            value.X = static_cast<float>(wxAtof(text.substr(0, xySeparator - 1).c_str()));
            value.Y = static_cast<float>(wxAtof(text.substr(xySeparator + 1, yzSeparator - xySeparator - 1).c_str()));
            value.Z = static_cast<float>(wxAtof(text.substr(yzSeparator + 1).c_str()));
            return true;
        }

        void Vector3Property::RefreshChildren()
        {
            if (GetCount() == 0)
                return;

            const Vector3 value = Vector3FromVariant(m_value);
            Item(0)->SetValue(value.X);
            Item(1)->SetValue(value.Y);
            Item(2)->SetValue(value.Z);
        }

        void Vector3Property::ChildChanged(wxVariant& thisValue, int childIndex, wxVariant& childValue) const
        {
            Vector3& value = Vector3FromVariant(thisValue);
            switch (childIndex)
            {
                case 0: value.X = static_cast<float>(childValue.GetDouble()); break;
                case 1: value.Y = static_cast<float>(childValue.GetDouble()); break;
                case 2: value.Z = static_cast<float>(childValue.GetDouble()); break;
            }
        }
    }
}