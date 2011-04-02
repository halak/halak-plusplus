#include <Halak.Toolkit/ClassInfo.h>
#include <Halak.Toolkit/EnumInfo.h>
#include <Halak.Toolkit/PrimitiveInfo.h>
#include <Halak/MPL.h>
#include <type_traits>

namespace Halak
{
    namespace Toolkit
    {
        template <typename T> const TypeInfo* TypeLibrary::GetTypeInfo()
        {
            // T�� ������ ���¸� �����´�. (������� int& Ȥ�� int**�� ��� int�� ��ȯ�Ѵ�)
            typedef MPL::RemoveReference<MPL::RemoveAllPointers<T>::Result>::Result Type;
        
            const char* key = typeid(Type).raw_name();
        
            TypeDictionary::const_iterator it = typeTable.find(key);
            if (it != typeTable.end())
                return (*it).second;
            else
            {
                // T�� Primitive���� Enum���� Class������ ���� �´� TypeInfo�� �����Ѵ�.
                typedef MPL::If<std::tr1::is_enum<Type>::value, EnumInfo, ClassInfo>::Result           EnumOrClassType;
                typedef MPL::If<MPL::IsPrimitive<Type>::Value, PrimitiveInfo, EnumOrClassType>::Result AdaptedTypeInfo;
        
                const TypeInfo* typeInfo = new AdaptedTypeInfo(sizeof(Type));
                typeTable.insert(TypeDictionary::value_type(key, typeInfo));
                types.push_back(typeInfo);
                return typeInfo;
            }
        }
        
        template <typename T> const TypeInfo* TypeLibrary::GetTypeInfo(T* pointer)
        {
            // T�� ������ ���¸� �����´�. (������� int& Ȥ�� int**�� ��� int�� ��ȯ�Ѵ�)
            typedef MPL::RemoveReference<MPL::RemoveAllPointers<T>::Result>::Result Type;
        
            const char* key = pointer ? typeid(*pointer).raw_name() : typeid(Type).raw_name();
        
            TypeDictionary::const_iterator it = typeTable.find(key);
            if (it != typeTable.end())
                return (*it).second;
            else
                return GetType<Type>();
        }

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
}