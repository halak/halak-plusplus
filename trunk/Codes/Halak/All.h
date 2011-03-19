#pragma once
#ifndef __HALAK_ALL_H__
#define __HALAK_ALL_H__

#   include <Halak/Foundation.h>
#   include <Halak/FWD.h>
#   include <Halak/Startup.h>

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // 01. Foundation
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // (BasicTypes)
#           include <Halak/Any.h>
#           include <Halak/AnyPtr.h>
#           include <Halak/AtomicInt.h>
#           include <Halak/Color.h>
#           include <Halak/Matrix4.h>
#           include <Halak/Point.h>
#           include <Halak/Quaternion.h>
#           include <Halak/Range.h>
#           include <Halak/Ray.h>
#           include <Halak/Ray2D.h>
#           include <Halak/Rectangle.h>
#           include <Halak/String.h>
#           include <Halak/UUID.h>
#           include <Halak/Vector2.h>
#           include <Halak/Vector3.h>
#           include <Halak/Vector4.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // (Object)
#           include <Halak/Object.h>
#               include <Halak/SharedObject.h>
#           include <Halak/SharedPointer.h>
#           include <Halak/WeakPointer.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // (Structure)
#           include <Halak/GameComponent.h>
#           include <Halak/GameModule.h>
#           include <Halak/GameNode.h>
#           include <Halak/GameStructure.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Any
#           include <Halak/Any.h>
#           include <Halak/AnyPtr.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Cloning
#           include <Halak/CloningContext.h>
#           include <Halak/ICloneable.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Diagnostics
#           include <Halak/Assert.h>
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Logger
#               include <Halak/GlobalLogger.h>
#               include <Halak/Logger.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Disposal
#           include <Halak/GarbageMan.h>
#           include <Halak/IDisposal.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Exceptions
#           include <Halak/Exception.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // FileSystem
#           include <Halak/FileSystem.h>
#           include <Halak/GlobalFileSystem.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Reflection
#           include <Halak/Attribute.h>
#           include <Halak/ConstructorInfo.h>
#           include <Halak/DynamicCast.h>
#           include <Halak/InstanceInfo.h>
#           include <Halak/PropertyInfo.h>
#           include <Halak/TypeInfo.h>
#               include <Halak/ClassInfo.h>
#               include <Halak/EnumInfo.h>
#               include <Halak/PrimitiveInfo.h>
#           include <Halak/TypeLibrary.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Time
#           include <Halak/Clock.h>
#           include <Halak/GlobalClock.h>
#           include <Halak/ParallelTimeline.h>
#           include <Halak/SubTimeline.h>
#           include <Halak/Timeline.h>

#endif