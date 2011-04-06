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
                    class StringFormatterAttribute;
                    class UnitAttribute;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Command
                    class ChangePropertyCommand;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Document
                    class Document;
                        class EntityDocument;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // StringFormatters
                    class StringFormatter;
                        class BatchCommandStringFormatter;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Tools
                    HKForwardDeclareSmartPointerClass(Tool);
                        HKForwardDeclareSmartPointerClass(ParticleEmitterTool);
                            HKForwardDeclareSmartPointerClass(SimpleParticleEmitterTool);
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // 03. GUI (wxWidgets)
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // (Integration)
                    class wxWidgetsApplication;
                    class wxWidgetsWindow;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // wxProperties
                    class BooleanProperty;
                    class ColorProperty;
                    class IPropertyUpdateable;
                    class Matrix4Property;
                    class NumberProperty;
                    class PointProperty;
                    class QuaternionProperty;
                    class RectangleProperty;
                    class Vector2Property;
                    class Vector3Property;
                    class Vector4Property;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // wxWindows
                    class EntityTreeWindow;
                    class HistoryWindow;
                    class MainWindow;
                    class PaletteWindow;
                    class PropertiesWindow;
                    class RenderPanel;
                        class EntityRenderPanel;

#           undef HKForwardDeclareSmartPointerClass
        }
    }

#endif