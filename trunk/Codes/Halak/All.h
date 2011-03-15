#pragma once
#ifndef __HALAK_ALL_H__
#define __HALAK_ALL_H__

    // 01. Foundation
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
        // (SmartPointers)
#           include <Halak/SharedObject.h>
#           include <Halak/SharedPointer.h>
#           include <Halak/WeakPointer.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Any
#           include <Halak/Any.h>
#           include <Halak/AnyPtr.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Disposal
#           include <Halak/GarbageMan.h>
#           include <Halak/IDisposal.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Exceptions
#           include <Halak/Exception.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Timeline
#           include <Halak/Clock.h>
#           include <Halak/GlobalClock.h>
#           include <Halak/ParallelTimeline.h>
#           include <Halak/SubTimeline.h>
#           include <Halak/Timeline.h>

    // Core Routines
#   include <Halak/Assert.h>
#   include <Halak/CheckedRelease.hpp>
#   include <Halak/Clock.h>
#   include <Halak/Delete.h>
#   include <Halak/Math.h>
#   include <Halak/MPL.h>

#   include <Halak/Startup.h>

    // Core System
#   include <Halak/Asset.h>
#   include <Halak/AssetLoader.h>
#   include <Halak/CloningContext.h>
#   include <Halak/GarbageMan.h>
#   include <Halak/ICloneable.h>
#   include <Halak/IDisposable.h>
#   include <Halak/IUpdateable.h>
#   include <Halak/IRevisable.h>
#   include <Halak/ISpatial.h>
#   include <Halak/ISpatial2D.h>
#   include <Halak/Timeline.h>

    // Core Component
#   include <Halak/GameComponent.h>
#   include <Halak/GameFramework.h>
#   include <Halak/GameNode.h>
#   include <Halak/GameStructure.h>

    // Animation
#   include <Halak/IEvaluables.h> // I<T>Evaluable 다 include 되어 있습니다.
#   include <Halak/EvaluableConstants.h>
#   include <Halak/EvaluableSequences.h>

    // Collision
#   include <Halak/IPickable.h>
#   include <Halak/PickingContext.h>

    // Command
#   include <Halak/CommandQueue.h>
#   include <Halak/CommandHistory.h>
#   include <Halak/Command.h>
#       include <Halak/RestorableCommand.h>
#           include <Halak/BatchCommand.h>
#           include <Halak/ChangePropertyCommand.h>

    // Gameplay
#   include <Halak/Entity.h>
#       include <Halak/EffectEntity.h>
#           include <Halak/ParticleEffectEntity.h>
#       include <Halak/RootEntity.h>
#   include <Halak/EntityExtension.h>
#   include <Halak/EntityWorld.h>
#   include <Halak/SpatialNode.h>
#   include <Halak/SpatialObject.h>
#   include <Halak/SpatialObject2D.h>

    // Graphics
#   include <Halak/Effect.h>
#   include <Halak/DisplaySwapChain.h>
#   include <Halak/DrawingContext.h>
#   include <Halak/GraphicsDevice.h>
#   include <Halak/IDrawable.h>
#   include <Halak/Texture2D.h>
#       include <Halak/DynamicTexture2D.h>
#       include <Halak/MemoryTexture2D.h>
#       include <Halak/SourceTexture2D.h>
#   include <Halak/SurfaceFormat.h>
#   include <Halak/Sprite.h>
#   include <Halak/SpriteRenderer.h>

    // Typography
#   include <Halak/Font.h>
#   include <Halak/FontString.h>
#   include <Halak/FreeType.h>

    // Input
#   include <Halak/Keys.h>
#   include <Halak/Mouse.h>
#   include <Halak/MouseState.h>

    // IO
#   include <Halak/Stream.h>
#       include <Halak/FileStream.h>
#   include <Halak/FileInfo.h>
#   include <Halak/DirectoryInfo.h>
#   include <Halak/Hotloader.h>
#   include <Halak/IReloadable.h>

    // JSON
#   include <Halak/JSONDocument.h>
#   include <Halak/JSONNodes.h>

    // Lua
#   include <Halak/LuaRuntimeEnvironment.h>

    // Particle
#   include <Halak/Particle.h>
#       include <Halak/SequentialParticle.h>
#       include <Halak/SimpleParticle.h>
#   include <Halak/ParticleControllers.h>
#   include <Halak/ParticleEmitter.h>
#       include <Halak/SequentialParticleEmitter.h>
#       include <Halak/SimpleParticleEmitter.h>
#   include <Halak/ParticleRenderer.h>
#       include <Halak/SimpleParticleRenderer.h>
#   include <Halak/ParticleSpawnPoints.h>
#   include <Halak/ParticleSpace.h>

    // Reflection
#   include <Halak/DynamicCast.h>
#   include <Halak/RegistrationContexts.h>
#   include <Halak/TypeLibrary.h>
#       include <Halak/Attribute.h>
#           include <Halak/Attributes.h>
#       include <Halak/TypeInfo.h>
#       include <Halak/ClassInfo.h>
#           include <Halak/ConstructorInfo.h>
#           include <Halak/PropertyInfo.h>
#       include <Halak/EnumInfo.h>
#       include <Halak/PrimitiveInfo.h>
#       include <Halak/InstanceInfo.h>

    // Serialization
#   include <Halak/ISerializable.h>
#   include <Halak/StreamReader.h>
#       include <Halak/BinaryStreamReader.h>
#       include <Halak/JSONStreamReader.h>
#   include <Halak/StreamWriter.h>
#       include <Halak/BinaryStreamWriter.h>
#       include <Halak/JSONStreamWriter.h>

    // Workflow
#   include <Halak/Flowchart.h>
#   include <Halak/FlowchartBlock.h>
#   include <Halak/FlowingContext.h>
#   include <Halak/FlowingStatus.h>
#   include <Halak/IFlowchartProcess.h>
#   include <Halak/VariableStorage.h>

    // Framework
#   include <Halak/Window.h>
#       include <Halak/GameWindow.h>
#   include <Halak/WindowsShell.h>


#endif