#include <Halak.wxWidgets/PCH.h>
#include <Halak.wxWidgets/AppFramework.h>
#include <Halak.wxWidgets/Window.h>
#include <Halak.wxWidgets/wxMainWindow.h>
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
    namespace wxWidgets
    {
        BEGIN_EVENT_TABLE(AppFramework, wxApp)
            EVT_IDLE(AppFramework::OnIdle)
            EVT_TIMER(wxID_ANY, AppFramework::OnTimer)
        END_EVENT_TABLE()

        AppFramework::AppFramework()
            : idleTimer(this)
        {
        }

        bool AppFramework::OnInit()
        {
            Halak::Startup();

            //locale.Init(wxLANGUAGE_KOREAN, wxLOCALE_CONV_ENCODING);
            //wxLocale::AddCatalogLookupPathPrefix("{Toolkit}\\Texts");
            //bool c = locale.AddCatalog(locale.GetCanonicalName());

            structure = new GameStructure();

            Halak::wxWidgets::Window* adaptedMainWindow = new Halak::wxWidgets::Window(GetMainWindow());
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


            //services->Push();

            lastUpdatedTime = Clock::GetCurrent();
            timestamp       = 0;
            idleTimer.Start();

            return true;
        }

        int AppFramework::OnExit()
        {
            delete structure;
            return wxApp::OnExit();
        }

        GameStructure* AppFramework::GetStructure() const
        {
            return structure;
        }

        GraphicsDevice* AppFramework::GetGraphicsDevice() const
        {
            return graphicsDevice;
        }

        FreeType* AppFramework::GetFreeType() const
        {
            return freeType;
        }

        SpriteRenderer* AppFramework::GetSpriteRenderer() const
        {
            return spriteRenderer;
        }

        Timeline* AppFramework::GetMainTimeline() const
        {
            return mainTimeline;
        }

        AppFramework* AppFramework::GetInstance()
        {
            return static_cast<AppFramework*>(wxApp::GetInstance());
        }

        void AppFramework::OnIdle(wxIdleEvent& /*event*/)
        {

        }

        void AppFramework::OnTimer(wxTimerEvent& /*event*/)
        {
            const float current = Clock::GetCurrent();

            mainTimeline->Update(current - lastUpdatedTime, timestamp);

            lastUpdatedTime = current;
            timestamp++;
        }
    }
}