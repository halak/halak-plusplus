namespace Halak
{
    namespace Toolkit
    {
        const EnumInfo::ValueCollection& EnumInfo::GetValues() const
        {
            return values;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        const char* EnumInfo::Value::GetName() const
        {
            return name;
        }
        
        int EnumInfo::Value::GetValue() const
        {
            return value;
        }

        const TypeInfo::AttributeCollection& EnumInfo::Value::GetAttributes() const
        {
            return attributes;
        }
    }
}