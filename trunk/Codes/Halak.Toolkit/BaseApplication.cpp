#include <Halak.wxToolkit/BaseApplication.h>
#include <Halak.wxToolkit/AdaptedWxWindow.h>
#include <Halak.wxToolkit/DocumentFolder.h>
#include <Halak.wxToolkit/MainWindow.h>
#include <Halak/Clock.h>
#include <Halak/FreeType.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/ServiceTree.h>
#include <Halak/SpriteRenderer.h>
#include <Halak/Startup.h>

namespace Halak
{
    namespace wxToolkit
    {
        BEGIN_EVENT_TABLE(BaseApplication, wxApp)
            EVT_IDLE(BaseApplication::OnIdle)
            EVT_TIMER(wxID_ANY, BaseApplication::OnTimer)
        END_EVENT_TABLE()

        BaseApplication::BaseApplication()
            : idleTimer(this)
        {
        }

        bool BaseApplication::OnInit()
        {
            Halak::Startup();

            //locale.Init(wxLANGUAGE_KOREAN, wxLOCALE_CONV_ENCODING);
            //wxLocale::AddCatalogLookupPathPrefix("{Toolkit}\\Texts");
            //bool c = locale.AddCatalog(locale.GetCanonicalName());

            services = new ServiceTree();

            // --------------------------------------------------
            // Basic Service Layer

            AdaptedWxWindow* adaptedMainWindow = new AdaptedWxWindow(GetMainWindow());
            services->GetRoot()->AttachChild(adaptedMainWindow);

            graphicsDevice = new GraphicsDevice();
            graphicsDevice->SetWindow(adaptedMainWindow);
            services->GetRoot()->AttachChild(graphicsDevice);

            freeType = new FreeType(graphicsDevice);
            services->GetRoot()->AttachChild(freeType);

            spriteRenderer = new SpriteRenderer(graphicsDevice);
            services->GetRoot()->AttachChild(spriteRenderer);

            documentFolder = new DocumentFolder();
            services->GetRoot()->AttachChild(documentFolder);

            // --------------------------------------------------
            // Service Layer

            //services->Push();

            lastUpdatedTime = Clock::GetCurrent();
            timestamp       = 0;
            idleTimer.Start();

            return true;
        }

        int BaseApplication::OnExit()
        {
            delete services;
            return wxApp::OnExit();
        }

        ServiceTree* BaseApplication::GetServices() const
        {
            return services;
        }

        GraphicsDevice* BaseApplication::GetGraphicsDevice() const
        {
            return graphicsDevice;
        }

        FreeType* BaseApplication::GetFreeType() const
        {
            return freeType;
        }

        SpriteRenderer* BaseApplication::GetSpriteRenderer() const
        {
            return spriteRenderer;
        }

        DocumentFolder* BaseApplication::GetDocumentFolder() const
        {
            return documentFolder;
        }

        BaseApplication* BaseApplication::GetInstance()
        {
            return static_cast<BaseApplication*>(wxApp::GetInstance());
        }

        void BaseApplication::OnIdle(wxIdleEvent& /*event*/)
        {

        }

        void BaseApplication::OnTimer(wxTimerEvent& /*event*/)
        {
            const float current = Clock::GetCurrent();

            services->Update(current - lastUpdatedTime, timestamp);

            lastUpdatedTime = current;
            timestamp++;
        }
    }
}