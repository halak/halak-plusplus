#ifndef __HALAK_TOOLKIT_ALL_H__
#define __HALAK_TOOLKIT_ALL_H__

#   include <Halak/All.h>

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // 01. Foundation
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Any
#           include <Halak.Toolkit/AnyPtr.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // IO
#           include <Halak.Toolkit/Hotloader.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // JSON
#           include <Halak.Toolkit/JSONDocument.h>
#           include <Halak.Toolkit/JSONNodes.h>
#           include <Halak.Toolkit/JSONStreamReader.h>
#           include <Halak.Toolkit/JSONStreamWriter.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Reflection
#           include <Halak.Toolkit/Attribute.h>
#           include <Halak.Toolkit/ClassInfo.h>
#           include <Halak.Toolkit/ConstructorInfo.h>
#           include <Halak.Toolkit/DynamicCast.h>
#           include <Halak.Toolkit/EnumInfo.h>
#           include <Halak.Toolkit/InstanceInfo.h>
#           include <Halak.Toolkit/PrimitiveInfo.h>
#           include <Halak.Toolkit/PropertyInfo.h>
#           include <Halak.Toolkit/RegistrationContexts.h>
#           include <Halak.Toolkit/TypeInfo.h>
#           include <Halak.Toolkit/TypeLibrary.h>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // 02. Design
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Attributes
#           include <Halak.Toolkit/Attributes.h> // 관련 Attribute 모두 include되어있습니다.
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Command
#           include <Halak.Toolkit/ChangePropertyCommand.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Document
#           include <Halak.Toolkit/Document.h>
#               include <Halak.Toolkit/EntityDocument.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // StringFormatters
#           include <Halak.Toolkit/Tool.h>
#               include <Halak.Toolkit/ParticleEmitterTool.h>
#                   include <Halak.Toolkit/SimpleParticleEmitterTool.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Tools
#           include <Halak.Toolkit/StringFormatter.h>
#               include <Halak.Toolkit/CommandStringFormatters.h>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // 03. GUI (wxWidgets)
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // (Integration)
#           include <Halak.Toolkit/wxWidgetsApplication.h>
#           include <Halak.Toolkit/wxWidgetsWindow.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // wxProperties
#           include <Halak.Toolkit/BooleanProperty.h>
#           include <Halak.Toolkit/ColorProperty.h>
#           include <Halak.Toolkit/IPropertyUpdateable.h>
#           include <Halak.Toolkit/Matrix4Property.h>
#           include <Halak.Toolkit/NumberProperty.h>
#           include <Halak.Toolkit/PointProperty.h>
#           include <Halak.Toolkit/QuaternionProperty.h>
#           include <Halak.Toolkit/RectangleProperty.h>
#           include <Halak.Toolkit/Vector2Property.h>
#           include <Halak.Toolkit/Vector3Property.h>
#           include <Halak.Toolkit/Vector4Property.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // wxWindows
#           include <Halak.Toolkit/EntityTreeWindow.h>
#           include <Halak.Toolkit/HistoryWindow.h>
#           include <Halak.Toolkit/MainWindow.h>
#           include <Halak.Toolkit/PaletteWindow.h>
#           include <Halak.Toolkit/PropertiesWindow.h>
#           include <Halak.Toolkit/RenderPanel.h>
#               include <Halak.Toolkit/EntityRenderPanel.h>

#endif