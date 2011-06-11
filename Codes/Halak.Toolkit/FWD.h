#pragma once
#ifndef __HALAK_TOOLKIT_FWD_H__
#define __HALAK_TOOLKIT_FWD_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        namespace Toolkit
        {
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // 01. Foundation
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Any
                    class AnyPtr;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // IO
                    class Hotloader;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // JSON
                    HKForwardDeclareSmartPointerClass(JSONDocument);
                    HKForwardDeclareSmartPointerClass(JSONNode);
                        HKForwardDeclareSmartPointerClass(JSONArray);
                        HKForwardDeclareSmartPointerClass(JSONObject);
                    HKForwardDeclareSmartPointerClass(JSONStreamReader);
                    HKForwardDeclareSmartPointerClass(JSONStreamWriter);
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Reflection
                    class Attribute;
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
            // 03. Asset
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Adobe Photoshop
                    HKForwardDeclareSmartPointerClass(PhotoshopDescriptor);
                    HKForwardDeclareSmartPointerClass(PhotoshopDocument);
                    HKForwardDeclareSmartPointerClass(PhotoshopDocumentReader);
                    HKForwardDeclareSmartPointerClass(PhotoshopImageResource);
                        HKForwardDeclareSmartPointerClass(PhotoshopAlphaChannelNames);
                        HKForwardDeclareSmartPointerClass(PhotoshopResolutionInfo);
                    HKForwardDeclareSmartPointerClass(PhotoshopLayer);
                    HKForwardDeclareSmartPointerClass(PhotoshopChannel);
                    HKForwardDeclareSmartPointerClass(PhotoshopMask);
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // 02. Design
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Attributes
                    class EditorAttribute;
                    class EntityComponentAttribute;
                    class RangeAttribute;
                    class UnitAttribute;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Command
                    class ChangePropertyCommand;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Tools
                    HKForwardDeclareSmartPointerClass(Tool);
                        HKForwardDeclareSmartPointerClass(ParticleEmitterTool);
                            HKForwardDeclareSmartPointerClass(SimpleParticleEmitterTool);
        }
    }

#endif