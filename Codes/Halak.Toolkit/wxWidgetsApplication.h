#pragma once
#ifndef __HALAK_TOOLKIT_WXWIDGETSAPPLICATION_H__
#define __HALAK_TOOLKIT_WXWIDGETSAPPLICATION_H__

#   include <Halak.Toolkit/FWD.h>
#   include <wx/wx.h>
#   include <vector>

    namespace Halak
    {
        namespace Toolkit
        {
            class wxWidgetsApplication : public wxApp
            {
                public:
                    virtual bool OnInit();
                    virtual int  OnExit();

                    GameStructure*  GetStructure() const;
                    GraphicsDevice* GetGraphicsDevice() const;
                    FreeType*       GetFreeType() const;
                    SpriteRenderer* GetSpriteRenderer() const;
                    Timeline*       GetMainTimeline() const;

                    virtual MainWindow* GetMainWindow() = 0;

                public:
                    static wxWidgetsApplication* GetInstance();

                protected:
                    wxWidgetsApplication();

                protected:
                    virtual void OnIdle(wxIdleEvent& event);
                    void OnTimer(wxTimerEvent& event);
                    
                private:
                    wxLocale locale;

                    GameStructure*  structure;
                    GraphicsDevice* graphicsDevice;
                    FreeType*       freeType;
                    SpriteRenderer* spriteRenderer;
                    Timeline*       mainTimeline;

                    float lastUpdatedTime;
                    uint  timestamp;
                    wxTimer idleTimer;

                private:
                    DECLARE_EVENT_TABLE()
            };
        }
    }

#endif