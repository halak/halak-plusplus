#pragma once
#ifndef __HALAK_UI_H__
#define __HALAK_UI_H__

#   include <Halak/UIDomain.h>
#       include <Halak/UISimpleDomain.h>
#   include <Halak/UIElement.h>
#   include <Halak/UIImage.h>
#   include <Halak/UIMarkupText.h>
#   include <Halak/UIRenderer.h>
#   include <Halak/UIVisualVisitor.h>
#       include <Halak/UIDrawingContext.h>
#           include <Halak/UIHandledDrawingContext.h>
#       include <Halak/UIPickingContext.h>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Frames
#       include <Halak/UIFrame.h>
#           include <Halak/UIAlignedFrame.h>
#           include <Halak/UIAnchoredFrame.h>
#           include <Halak/UIFittedFrame.h>
#           include <Halak/UIFixedFrame.h>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Effects
#       include <Halak/UIEffect.h>
#           include <Halak/UITintEffect.h>
#       include <Halak/UIEffectMap.h>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Events
#       include <Halak/UIAsyncEventQueue.h>
#       include <Halak/UIEventArgs.h>
#           include <Halak/UIGamePadEventArgs.h>
#           include <Halak/UIKeyboardEventArgs.h>
#           include <Halak/UIMouseEventArgs.h>
#               include <Halak/UIMouseButtonEventArgs.h>
#               include <Halak/UIMouseWheelEventArgs.h>
#           include <Halak/UITouchEventArgs.h>
#       include <Halak/UIEventDispatcher.h>
#           include <Halak/UIAppEventDispatcher.h>
#           include <Halak/UIGamePadEventDispatcher.h>
#           include <Halak/UIKeyboardEventDispatcher.h>
#           include <Halak/UIMouseEventDispatcher.h>
#           include <Halak/UITouchEventDispatcher.h>
#       include <Halak/UIEventID.h>
#       include <Halak/UIEventMap.h>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Transforms
#       include <Halak/UITransform.h>
#           include <Halak/UITransform3D.h>
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Visuals
#       include <Halak/UIVisual.h>
#           include <Halak/UILabel.h>
#           include <Halak/UIPanel.h>
#               include <Halak/UIButton.h>
#                   include <Halak/UICheckBox.h>
#               include <Halak/UIEditBox.h>
#               include <Halak/UIFlowPanel.h>
#                   include <Halak/UIListBox.h>
#               include <Halak/UIMarkupTextBox.h>
#               include <Halak/UIWindow.h>
#           include <Halak/UISprite.h>
#           include <Halak/UIVideo.h>

#endif