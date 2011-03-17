namespace Halak
{
    const TypeLibrary::TypeCollection& TypeLibrary::GetItems() const
    {
        return types;
    }

    TypeLibrary& TypeLibrary::GetInstance()
    {
        static TypeLibrary singletonInstance;
        return singletonInstance;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ���Ǿ����ϴ�.
//#include <Halak/MPL.h>
//#include <Halak/PrimitiveInfo.h>
//#include <Halak/ClassInfo.h>
//#include <Halak/EnumInfo.h>
//#include <type_traits>
//template <typename T> const TypeInfo* TypeLibrary::GetType()
//{
//    // T�� ������ ���¸� �����´�. (������� int& Ȥ�� int**�� ��� int�� ��ȯ�Ѵ�)
//    typedef MPL::RemoveReference<MPL::RemoveAllPointers<T>::Result>::Result Type;
//
//    const char* key = typeid(Type).raw_name();
//
//    TypeDictionary::const_iterator it = typeTable.find(key);
//    if (it != typeTable.end())
//        return (*it).second;
//    else
//    {
//        // T�� Primitive���� Enum���� Class������ ���� �´� TypeInfo�� �����Ѵ�.
//        typedef MPL::If<std::tr1::is_enum<Type>::value, EnumInfo, ClassInfo>::Result           EnumOrClassType;
//        typedef MPL::If<MPL::IsPrimitive<Type>::Value, PrimitiveInfo, EnumOrClassType>::Result AdaptedTypeInfo;
//
//        const TypeInfo* typeInfo = new AdaptedTypeInfo(sizeof(Type));
//        typeTable.insert(TypeDictionary::value_type(key, typeInfo));
//        types.push_back(typeInfo);
//        return typeInfo;
//    }
//}
//
//template <typename T> const TypeInfo* TypeLibrary::GetType(T* pointer)
//{
//    // T�� ������ ���¸� �����´�. (������� int& Ȥ�� int**�� ��� int�� ��ȯ�Ѵ�)
//    typedef MPL::RemoveReference<MPL::RemoveAllPointers<T>::Result>::Result Type;
//
//    const char* key = pointer ? typeid(*pointer).raw_name() : typeid(Type).raw_name();
//
//    TypeDictionary::const_iterator it = typeTable.find(key);
//    if (it != typeTable.end())
//        return (*it).second;
//    else
//        return GetType<Type>();
//}