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
            // T의 순수한 형태를 가져온다. (예를들어 int& 혹은 int**를 모두 int로 변환한다)
            typedef MPL::RemoveReference<MPL::RemoveAllPointers<T>::Result>::Result Type;
        
            const char* key = typeid(Type).raw_name();
        
            TypeDictionary::const_iterator it = typeTable.find(key);
            if (it != typeTable.end())
                return (*it).second;
            else
            {
                // T가 Primitive인지 Enum인지 Class인지에 따라서 맞는 TypeInfo를 선택한다.
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
            // T의 순수한 형태를 가져온다. (예를들어 int& 혹은 int**를 모두 int로 변환한다)
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