#pragma once
#ifndef __HALAK_WXWIDGETS_FWD_H__
#define __HALAK_WXWIDGETS_FWD_H__

#   include <Halak/FWD.h>
#   include <Halak.Toolkit/FWD.h>

    namespace Halak
    {
        namespace wxWidgets
        {
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Foundation
                class AppFramework;
                class Window;
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // GUI
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // Properties
                    class IPropertyUpdateable;
                    class wxBooleanProperty;
                    class wxColorProperty;
                    class wxMatrix4Property;
                    class wxNumberProperty;
                    class wxPointProperty;
                    class wxQuaternionProperty;
                    class wxRectangleProperty;
                    class wxVector2Property;
                    class wxVector3Property;
                    class wxVector4Property;
                ////////////////////////////////////////////////////////////////////////////////////////////////////
                // wxWindows
                    class wxEntityTreeWindow;
                    class wxHistoryWindow;
                    class wxMainWindow;
                    class wxPaletteWindow;
                    class wxPropertiesWindow;
                    class wxRenderPanel;
                        class wxUILayoutRenderPanel;
        }
    }

#endif