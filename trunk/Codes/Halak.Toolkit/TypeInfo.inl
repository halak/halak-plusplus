namespace Halak
{
    namespace Toolkit
    {
        uint32 TypeInfo::GetID() const
        {
            return id;
        }

        void TypeInfo::SetID(uint value)
        {
            id = value;
        }

        const char* TypeInfo::GetNamespace() const
        {
            return namespace_;
        }

        void TypeInfo::SetNamespace(const char* value)
        {
            namespace_ = value;
        }

        const char* TypeInfo::GetName() const
        {
            return name;
        }

        void TypeInfo::SetName(const char* value)
        {
            name = value;
        }

        int TypeInfo::GetAllocationSize() const
        {
            return allocationSize;
        }

        bool TypeInfo::IsPrimitive() const
        {
            return (type & Primitive) != 0;
        }

        bool TypeInfo::IsClass() const
        {
            return (type & Class) != 0;
        }

        bool TypeInfo::IsEnum() const
        {
            return (type & Enum) != 0;
        }

        const TypeInfo::AttributeCollection& TypeInfo::GetAttributes() const
        {
            return attributes;
        }
    }
}