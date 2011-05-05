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
    // 02. Asset
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Adobe Photoshop
#           include <Halak.Toolkit/PhotoshopDescriptor.h>
#           include <Halak.Toolkit/PhotoshopDocument.h>
#           include <Halak.Toolkit/PhotoshopDocumentImporter.h>
#           include <Halak.Toolkit/PhotoshopDocumentReader.h>
#           include <Halak.Toolkit/PhotoshopImageResources.h>
#           include <Halak.Toolkit/PhotoshopLayers.h>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // 02. Design
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Attributes
#           include <Halak.Toolkit/Attributes.h> // 관련 Attribute 모두 include되어있습니다.
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Command
#           include <Halak.Toolkit/ChangePropertyCommand.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Tools
#           include <Halak.Toolkit/Tool.h>
#               include <Halak.Toolkit/ParticleEmitterTool.h>
#                   include <Halak.Toolkit/SimpleParticleEmitterTool.h>

#endif