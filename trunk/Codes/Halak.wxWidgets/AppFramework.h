#pragma once
#ifndef __HALAK_WXWIDGET_APPFRAMEWORK_H__
#define __HALAK_WXWIDGET_APPFRAMEWORK_H__

#   include <Halak.wxWidgets/FWD.h>
#   include <wx/wx.h>
#   include <vector>

    namespace Halak
    {
        namespace wxWidgets
        {
            class AppFramework : public wxApp
            {
                public:
                    virtual bool OnInit();
                    virtual int  OnExit();

                    GameStructure*  GetStructure() const;
                    GraphicsDevice* GetGraphicsDevice() const;
                    FreeType*       GetFreeType() const;
                    SpriteRenderer* GetSpriteRenderer() const;
                    Timeline*       GetMainTimeline() const;

                    virtual wxMainWindow* GetMainWindow() = 0;

                public:
                    static AppFramework* GetInstance();

                protected:
                    AppFramework();

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