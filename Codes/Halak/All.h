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
#           include <Halak/Color.h>
#           include <Halak/Matrix4.h>
#           include <Halak/Point.h>
#           include <Halak/Quaternion.h>
#           include <Halak/Range.h>
#           include <Halak/Ray.h>
#           include <Halak/Ray2D.h>
#           include <Halak/Rectangle.h>
#           include <Halak/RectangleF.h>
#           include <Halak/String.h>
#           include <Halak/URI.h>
#           include <Halak/UUID.h>
#           include <Halak/Vector2.h>
#           include <Halak/Vector3.h>
#           include <Halak/Vector4.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // (SmartPointers)
#           include <Halak/NullPointer.h>
#           include <Halak/PointerCasts.h>
#           include <Halak/SharedObject.h>
#           include <Halak/SharedPointer.h>
#           include <Halak/WeakPointer.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // (Any)
#           include <Halak/Any.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Clock
#           include <Halak/Clock.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Containers
#           include <Halak/SequenceDictionary.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Diagnostics
#           include <Halak/Assert.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Exceptions
#           include <Halak/Exception.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // IO
#           include <Halak/BinaryStreamReader.h>
#           include <Halak/BinaryStreamWriter.h>
#           include <Halak/StringReader.h>
#           include <Halak/DirectoryInfo.h>
#           include <Halak/FileInfo.h>
#           include <Halak/FileStream.h>
#           include <Halak/Stream.h>
#           include <Halak/StreamReader.h>
#           include <Halak/StreamWriter.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Mathemetics
#           include <Halak/Geom2D.h>
#           include <Halak/Math.h>
#           include <Halak/NumericLimits.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Memory
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Time
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Utilities
#           include <Halak/CheckedRelease.h>
#           include <Halak/Delete.h>
#           include <Halak/IClassQueryable.h>
#           include <Halak/IRevisable.h>
#           include <Halak/ISpatial.h>
#           include <Halak/ISpatial2D.h>
#           include <Halak/MPL.h>
#           include <Halak/Property.h>
#           include <Halak/RectangleStorage.h>
#           include <Halak/Signal.h>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // 02. GameComponent
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // (Core)
#           include <Halak/GameComponent.h>
#           include <Halak/GameComponentFactory.h>
#           include <Halak/GameModule.h>
#           include <Halak/GameNode.h>
#           include <Halak/GameStructure.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Asset
#           include <Halak/Asset.h>
#           include <Halak/AssetLoader.h>
#           include <Halak/IReloadable.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Cloning
#           include <Halak/CloningContext.h>
#           include <Halak/ICloneable.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Diagnostics
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Logger
#               include <Halak/GlobalLogger.h>
#               include <Halak/Logger.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Disposal
#           include <Halak/GarbageMan.h>
#           include <Halak/IDisposable.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // FileSystem
#           include <Halak/FileSystem.h>
#           include <Halak/GlobalFileSystem.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Serialization
#           include <Halak/ISerializable.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Time
#           include <Halak/IUpdateable.h>
#           include <Halak/ParallelTimeline.h>
#           include <Halak/SubTimeline.h>
#           include <Halak/Timeline.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
    // 03. (NotYet)
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Graphics
#           include <Halak/DisplaySwapChain.h>
#           include <Halak/DrawingContext.h>
#           include <Halak/GraphicsDevice.h>
#           include <Halak/IDrawable.h>
#           include <Halak/Sprite.h>
#           include <Halak/SpriteRenderer.h>
#           include <Halak/SurfaceFormat.h>
#           include <Halak/Texture2D.h>
#               include <Halak/DynamicTexture2D.h>
#               include <Halak/MemoryTexture2D.h>
#               include <Halak/SourceTexture2D.h>
#           include <Halak/Window.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Input
#           include <Halak/Key.h>
#           include <Halak/Keyboard.h>
#           include <Halak/KeyboardState.h>
#           include <Halak/Mouse.h>
#           include <Halak/MouseState.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
    // 04. Application
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Animation
#           include <Halak/ColorRangeSequence.h>
#           include <Halak/ColorSequence.h>
#           include <Halak/ColorSequence.h>
#           include <Halak/EvaluableBlenderTemplate.h>
#           include <Halak/EvaluableConstants.h>
#           include <Halak/EvaluableFloatBlender.h>
#           include <Halak/EvaluableFloatConstant.h>
#           include <Halak/EvaluableFloatPrioritySelector.h>
#           include <Halak/EvaluableFloatRangeSequence.h>
#           include <Halak/EvaluableFloatSequence.h>
#           include <Halak/EvaluablePointSequence.h>
#           include <Halak/EvaluablePrioritySelectorTemplate.h>
#           include <Halak/EvaluableRangeSequenceTemplate.h>
#           include <Halak/EvaluableSequences.h>
#           include <Halak/EvaluableSequenceTemplate.h>
#           include <Halak/EvaluableSpriteConstant.h>
#           include <Halak/EvaluableSpriteSequence.h>
#           include <Halak/FloatRangeSequence.h>
#           include <Halak/FloatSequence.h>
#           include <Halak/IBoolEvaluable.h>
#           include <Halak/ICharEvaluable.h>
#           include <Halak/IColorEvaluable.h>
#           include <Halak/IDoubleEvaluable.h>
#           include <Halak/IEvaluables.h>
#           include <Halak/IFloatEvaluable.h>
#           include <Halak/IFloatRangeEvaluable.h>
#           include <Halak/IIntEvaluable.h>
#           include <Halak/ILongEvaluable.h>
#           include <Halak/IPointEvaluable.h>
#           include <Halak/IQuaternionEvaluable.h>
#           include <Halak/IRectangleEvaluable.h>
#           include <Halak/IShortEvaluable.h>
#           include <Halak/ISpriteEvaluable.h>
#           include <Halak/IUCharEvaluable.h>
#           include <Halak/IUIntEvaluable.h>
#           include <Halak/IULongEvaluable.h>
#           include <Halak/IUShortEvaluable.h>
#           include <Halak/IVector2Evaluable.h>
#           include <Halak/IVector3Evaluable.h>
#           include <Halak/IVector4Evaluable.h>
#           include <Halak/PointSequence.h>
#           include <Halak/SequenceTemplate.h>
#           include <Halak/SpriteSequence.h>
#           include <Halak/Vector2RangeSequence.h>
#           include <Halak/Vector2Sequence.h>
#           include <Halak/Vector3RangeSequence.h>
#           include <Halak/Vector3Sequence.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Collision
#           include <Halak/IPickable.h>
#           include <Halak/PickingContext.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Collision2D
#           include <Halak/CollisionSpace2D.h>
#           include <Halak/RaycastReport2D.h>
#           include <Halak/Shape2D.h>
#               include <Halak/AxisAlignedBoxShape2D.h>
#               include <Halak/BoxShape2D.h>
#               include <Halak/PointShape2D.h>
#               include <Halak/SegmentShape2D.h>
#               include <Halak/SphereShape2D.h>
#               include <Halak/UserShape2D.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Command
#           include <Halak/Command.h>
#               include <Halak/RestorableCommand.h>
#                   include <Halak/BatchCommand.h>
#           include <Halak/CommandHistory.h>
#           include <Halak/CommandQueue.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Framework
#           include <Halak/GameFramework.h>
#           include <Halak/GameWindow.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Gameplay
#           include <Halak/SpatialObject.h>
#           include <Halak/SpatialObject2D.h>
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Entity System
#               include <Halak/Entity.h>
#               include <Halak/EntityWorld.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Lua
#           include <Halak/LuaRuntimeEnvironment.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // OS
#           include <Halak/WindowsShell.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // SFX
#           include <Halak/Effect.h>
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Particle
#               include <Halak/Particle.h>
#               include <Halak/ParticleControllers.h>
#               include <Halak/ParticleEmitter.h>
#               include <Halak/ParticleRenderer.h>
#               include <Halak/ParticleSpace.h>
#               include <Halak/ParticleSpawnPoints.h>
#               include <Halak/SequentialParticle.h>
#               include <Halak/SequentialParticleEmitter.h>
#               include <Halak/SimpleParticle.h>
#               include <Halak/SimpleParticleEmitter.h>
#               include <Halak/SimpleParticleRenderer.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Script
#           include <Halak/Flowchart.h>
#           include <Halak/FlowchartBlock.h>
#           include <Halak/FlowingContext.h>
#           include <Halak/IFlowchartProcess.h>
#           include <Halak/VariableStorage.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Typography
#           include <Halak/Font.h>
#           include <Halak/FontString.h>
#           include <Halak/FreeType.h>
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // UI
#           include <Halak/IWindowTarget.h>
#           include <Halak/UIElement.h>
#           include <Halak/UISimpleWindowTarget.h>
#           include <Halak/UIImage.h>
#           include <Halak/UIMarkupText.h>
#           include <Halak/UIMarkupTextLayout.h>
#           include <Halak/UIRenderer.h>
#           include <Halak/UIVisualVisitor.h>
#               include <Halak/UIDrawingContext.h>
#               include <Halak/UIPickingContext.h>
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Frames
#               include <Halak/UIFrame.h>
#                   include <Halak/UIAlignedFrame.h>
#                   include <Halak/UIAnchoredFrame.h>
#                   include <Halak/UIFittedFrame.h>
#                   include <Halak/UIFixedFrame.h>
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Effects
#               include <Halak/UIEffect.h>
#                   include <Halak/UITintEffect.h>
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Events
#               include <Halak/UIEventArgs.h>
#                   include <Halak/UIGamePadEventArgs.h>
#                   include <Halak/UIKeyboardEventArgs.h>
#                   include <Halak/UIMouseEventArgs.h>
#                   include <Halak/UITouchEventArgs.h>
#               include <Halak/UIEventDispatcher.h>
#                   include <Halak/UIGamePadEventDispatcher.h>
#                   include <Halak/UIKeyboardEventDispatcher.h>
#                   include <Halak/UIMouseEventDispatcher.h>
#                   include <Halak/UITouchEventDispatcher.h>
#               include <Halak/UIEventID.h>
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Windows
#               include <Halak/UIWindow.h>
#                   include <Halak/UIButton.h>
#                   include <Halak/UIEditBox.h>
#                   include <Halak/UIListBox.h>
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Visuals
#               include <Halak/UIVisual.h>
#                   include <Halak/UILabel.h>
#                   include <Halak/UIMarkupLabel.h>
#                   include <Halak/UISprite.h>
#                   include <Halak/UIVideo.h>
#endif