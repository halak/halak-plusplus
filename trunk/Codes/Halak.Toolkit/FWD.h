#pragma once
#ifndef __HALAK_TOOLKIT_FWD_H__
#define __HALAK_TOOLKIT_FWD_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        namespace Toolkit
        {
#           define HKForwardDeclareSmartPointerClass(name) class name; \
                                                           typedef SharedPointer<name> name##Ptr; \
                                                           typedef WeakPointer<name>   name##WeakPtr;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // 01. Foundation
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Any
                    class AnyPtr;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Reflection
                    class Attribte;
                    class ConstructorInfo;
                    class InstanceInfo;
                    class PropertyInfo;
                    class TypeInfo;
                        class ClassInfo;
                        class EnumInfo;
                        class PrimitiveInfo;
                    class TypeLibrary;
                    class RegistrationContext;
                        class ConstructorRegistrationContext;
                        class PropertyRegistrationContext;
                        class PrimitiveRegistrationContext;
                        class ClassRegistrationContext;
                        class EnumRegistrationContext;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // 02. Design
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Attributes
                    class EditorAttribute;
                    class EntityComponentAttribute;
                    class RangeAttribute;
                    class StringFormatterAttribute;
                    class UnitAttribute;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Command
                    class ChangePropertyCommand;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // IO
                    class Hotloader;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // StringFormatters
                    class StringFormatter;
                        class BatchCommandStringFormatter;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // 03. GUI (wxWidgets)

#           undef HKForwardDeclareSmartPointerClass
        }
    }

#endif