#pragma once
#ifndef __HALAK_WXTOOLKIT_FWD_H__
#define __HALAK_WXTOOLKIT_FWD_H__

#   include <Halak/FWD.h>

    namespace Halak
    {
        namespace wxToolkit
        {
            class AdaptedWxWindow;
            class BaseApplication;
            class SelectedObjects;
            class ToolAssistant;

            class IGlobalSignals;
            class IWIndowSignals;

            HKForwardDeclareSmartPointerClass(DocumentFolder);
            HKForwardDeclareSmartPointerClass(Document);
                HKForwardDeclareSmartPointerClass(EntityDocument);

            HKForwardDeclareSmartPointerClass(Tool);
                HKForwardDeclareSmartPointerClass(ParticleEmitterTool);
                    HKForwardDeclareSmartPointerClass(SimpleParticleEmitterTool);

            class EntityRenderPanel;
            class EntityTreeWindow;
            class HistoryWindow;
            class MainWindow;
            class PaletteWindow;
            class PropertiesWindow;
            class RenderPanel;

            class IPropertyUpdateable;
            class BooleanProperty;
            class ColorProperty;
            class Matrix4Property;
            class NumberProperty;
            class PointProperty;
            class QuaternionProperty;
            class RectanglePropety;
            class Vector2Property;
            class Vector3Property;
            class Vector4Property;
        }
    }

#endif