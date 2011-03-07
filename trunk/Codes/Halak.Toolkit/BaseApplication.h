#pragma once
#ifndef __HALAK_BASEAPPLICATION_H__
#define __HALAK_BASEAPPLICATION_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <wx/wx.h>
#   include <vector>

    namespace Halak
    {
        namespace wxToolkit
        {
            class BaseApplication : public wxApp
            {
                public:
                    virtual bool OnInit();
                    virtual int  OnExit();

                    ServiceTree*    GetServices() const;
                    GraphicsDevice* GetGraphicsDevice() const;
                    FreeType*       GetFreeType() const;
                    SpriteRenderer* GetSpriteRenderer() const;
                    DocumentFolder* GetDocumentFolder() const;

                    virtual MainWindow* GetMainWindow() = 0;

                public:
                    static BaseApplication* GetInstance();

                protected:
                    BaseApplication();

                protected:
                    virtual void OnIdle(wxIdleEvent& event);
                    void OnTimer(wxTimerEvent& event);
                    
                private:
                    wxLocale locale;

                    ServiceTree*    services;
                    GraphicsDevice* graphicsDevice;
                    FreeType*       freeType;
                    SpriteRenderer* spriteRenderer;
                    DocumentFolder* documentFolder;

                    float lastUpdatedTime;
                    uint  timestamp;
                    wxTimer idleTimer;

                private:
                    DECLARE_EVENT_TABLE()
            };
        }
    }

#endif