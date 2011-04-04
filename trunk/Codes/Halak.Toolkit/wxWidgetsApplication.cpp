#include <Halak.Toolkit/wxWidgetsApplication.h>
#include <Halak.Toolkit/MainWindow.h>
#include <Halak.Toolkit/wxWidgetsWindow.h>
#include <Halak/Clock.h>
#include <Halak/FreeType.h>
#include <Halak/GameStructure.h>
#include <Halak/GameNode.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/SpriteRenderer.h>
#include <Halak/Timeline.h>
#include <Halak/Startup.h>

namespace Halak
{
    namespace Toolkit
    {
        BEGIN_EVENT_TABLE(wxWidgetsApplication, wxApp)
            EVT_IDLE(wxWidgetsApplication::OnIdle)
            EVT_TIMER(wxID_ANY, wxWidgetsApplication::OnTimer)
        END_EVENT_TABLE()

        wxWidgetsApplication::wxWidgetsApplication()
            : idleTimer(this)
        {
        }

        bool wxWidgetsApplication::OnInit()
        {
            Halak::Startup();

            //locale.Init(wxLANGUAGE_KOREAN, wxLOCALE_CONV_ENCODING);
            //wxLocale::AddCatalogLookupPathPrefix("{Toolkit}\\Texts");
            //bool c = locale.AddCatalog(locale.GetCanonicalName());

            structure = new GameStructure();

            // --------------------------------------------------
            // Basic Service Layer

            wxWidgetsWindow* adaptedMainWindow = new wxWidgetsWindow(GetMainWindow());
            structure->GetRoot()->AttachChild(adaptedMainWindow);

            graphicsDevice = new GraphicsDevice();
            graphicsDevice->SetWindow(adaptedMainWindow);
            structure->GetRoot()->AttachChild(graphicsDevice);

            freeType = new FreeType(graphicsDevice);
            structure->GetRoot()->AttachChild(freeType);

            spriteRenderer = new SpriteRenderer(graphicsDevice);
            structure->GetRoot()->AttachChild(spriteRenderer);

            mainTimeline = new Timeline();
            structure->GetRoot()->AttachChild(mainTimeline);

            // --------------------------------------------------
            // Service Layer

            //services->Push();

            lastUpdatedTime = Clock::GetCurrent();
            timestamp       = 0;
            idleTimer.Start();

            return true;
        }

        int wxWidgetsApplication::OnExit()
        {
            delete structure;
            return wxApp::OnExit();
        }

        GameStructure* wxWidgetsApplication::GetStructure() const
        {
            return structure;
        }

        GraphicsDevice* wxWidgetsApplication::GetGraphicsDevice() const
        {
            return graphicsDevice;
        }

        FreeType* wxWidgetsApplication::GetFreeType() const
        {
            return freeType;
        }

        SpriteRenderer* wxWidgetsApplication::GetSpriteRenderer() const
        {
            return spriteRenderer;
        }

        Timeline* wxWidgetsApplication::GetMainTimeline() const
        {
            return mainTimeline;
        }

        wxWidgetsApplication* wxWidgetsApplication::GetInstance()
        {
            return static_cast<wxWidgetsApplication*>(wxApp::GetInstance());
        }

        void wxWidgetsApplication::OnIdle(wxIdleEvent& /*event*/)
        {

        }

        void wxWidgetsApplication::OnTimer(wxTimerEvent& /*event*/)
        {
            const float current = Clock::GetCurrent();

            mainTimeline->Update(current - lastUpdatedTime, timestamp);

            lastUpdatedTime = current;
            timestamp++;
        }
    }
}