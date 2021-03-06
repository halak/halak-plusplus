#include <Halak.wxWidgets/PCH.h>
#include <Halak.wxWidgets/wxUILayoutRenderPanel.h>
#include <Halak.wxWidgets/AppFramework.h>
#include <Halak.wxWidgets/Window.h>
#include <Halak/Colors.h>
#include <Halak/DisplaySwapChain.h>
#include <Halak/GameStructure.h>
#include <Halak/GraphicsDevice.h>
#include <Halak/SpriteRenderer.h>
#include <Halak/UIDomain.h>
#include <Halak/UIDrawingContext.h>
#include <Halak/UIWindow.h>

namespace Halak
{
    namespace wxWidgets
    {
        BEGIN_EVENT_TABLE(wxUILayoutRenderPanel, wxRenderPanel)
            EVT_LEFT_DOWN   (OnMouseButtonDown)
            EVT_LEFT_UP     (OnMouseButtonUp)
            EVT_RIGHT_DOWN  (OnMouseButtonDown)
            EVT_RIGHT_UP    (OnMouseButtonUp)
            EVT_MIDDLE_DOWN (OnMouseButtonDown)
            EVT_MIDDLE_UP   (OnMouseButtonUp)
            EVT_MOTION      (OnMouseMotion)
        END_EVENT_TABLE()

        wxUILayoutRenderPanel::wxUILayoutRenderPanel(wxWindow* parent)
            : wxRenderPanel(parent),
              domain(nullptr),
              renderer(nullptr),
              clearColor(Colors::CornflowerBlue)
        {
            GameStructure* gameStructure = AppFramework::GetInstance()->GetStructure();

            //wxWidgetsWindow* adaptedWindow = new wxWidgetsWindow(this);
            //DisplaySwapChain* swapChain = new DisplaySwapChain(wxWidgetsApplication::GetInstance()->GetGraphicsDevice(), adaptedWindow, Point(800, 600));
            //document->GetLocalServices()->Add(adaptedWindow);
            //document->GetLocalServices()->Add(swapChain);
            //spriteRenderer = wxWidgetsApplication::GetInstance()->GetSpriteRenderer();
            //SetSwapChain(swapChain);
            //document->GetTimeline()->SetSpeed(1.0f);

                //MainWindow* mainWindow = wxWidgetsApplication::GetInstance()->GetMainWindow();
                //wxUILayoutRenderPanel* renderPanel = new wxUILayoutRenderPanel(mainWindow);
                //renderPanel->SetTarget(rootEntity);
                //mainWindow->AddNotebookPage(renderPanel, rootEntity->GetName());

                //EntityDocumentPtr document = GetDocumentFolder()->Find(rootEntity);
                //AdaptedWxWindow*  panelWindow    = new AdaptedWxWindow(renderPanel);
                //DisplaySwapChain* panelSwapChain = new DisplaySwapChain(wxWidgetsApplication::GetInstance()->GetGraphicsDevice(), panelWindow);
                //document->GetLocalServices()->Add(panelWindow);
                //document->GetLocalServices()->Add(panelSwapChain);

                //renderPanel->SetSwapChain(panelSwapChain);
                //renderPanel->SetSpriteRenderer(wxWidgetsApplication::GetInstance()->GetSpriteRenderer());

                //document->GetTimeline()->SetSpeed(1.0f);
           //{
           // wxUILayoutRenderPanel* renderPanel = new wxUILayoutRenderPanel(mainWindow);
           // renderPanel->SetTarget(entity);
           // mainWindow->AddNotebookPage(renderPanel, "TEST1");
           // AdaptedWxWindow* panelWindow = new AdaptedWxWindow(renderPanel);
           // DisplaySwapChain* panelSwapChain = new DisplaySwapChain(GetGraphicsDevice(), panelWindow);
           // Timeline* timeline = new Timeline();
           // CommandHistory* history = new CommandHistory();
           // GetServices()->Add(panelWindow);
           // GetServices()->Add(panelSwapChain);
           // GetServices()->Add(timeline);
           // GetServices()->Add(history);
           // renderPanel->SetSwapChain(panelSwapChain);
           // renderPanel->SetSpriteRenderer(GetSpriteRenderer());
           // renderPanel->SetName("AA");
           // timeline->Add(emitter);
           // propertiesWindow->SetHistory(history);
           // propertiesWindow->SetTarget(emitter);
           // historyWindow->SetHistory(history);
           // mainWindow->SetHistory(history);
           // }
        }

        UIDomain* wxUILayoutRenderPanel::GetDomain() const
        {
            return domain;
        }

        void wxUILayoutRenderPanel::SetDomain(UIDomain* value)
        {
            domain = value;
        }

        SpriteRenderer* wxUILayoutRenderPanel::GetRenderer() const
        {
            return renderer;
        }

        void wxUILayoutRenderPanel::SetRenderer(SpriteRenderer* value)
        {
            renderer = value;
        }

        Color wxUILayoutRenderPanel::GetClearColor() const
        {
            return clearColor;
        }

        void wxUILayoutRenderPanel::SetClearColor(Color value)
        {
            clearColor = value;
        }

        //RootEntityPtr wxUILayoutRenderPanel::GetTargetPointee() const
        //{
        //    return target;
        //}

        //void wxUILayoutRenderPanel::SetTarget(const RootEntityPtr value)
        //{
        //    if (target != value)
        //    {
        //        target = value;
        //    }
        //}

        //SpriteRenderer* wxUILayoutRenderPanel::GetSpriteRenderer() const
        //{
        //    return spriteRenderer;
        //}

        //void wxUILayoutRenderPanel::SetSpriteRenderer(SpriteRenderer* value)
        //{
        //    spriteRenderer = value;
        //}

        void wxUILayoutRenderPanel::Draw()
        {
            if (domain == nullptr ||
                domain->GetRoot() == nullptr ||
                renderer == nullptr)
                return;

            GetSwapChain()->GetGraphicsDevice()->Clear(clearColor);

            //renderer->Begin();
            //UIDrawingContext context(renderer);
            //context.Draw(domain->GetRoot());
            //renderer->End();

            //if (spriteRenderer == nullptr || target == nullptr)
            //    return;

            //const float sx = static_cast<float>(GetScrollPos(wxHORIZONTAL));
            //const float sy = static_cast<float>(GetScrollPos(wxVERTICAL));

            //DrawingContext context(spriteRenderer);
            //spriteRenderer->Begin();
            //spriteRenderer->Push(Matrix4::Translation(Vector3(-sx, -sy, 0.0f)));
            //const Entity::EntityCollection& children = target->GetChildren();
            //for (Entity::EntityCollection::const_iterator it = children.begin(); it != children.end(); it++)
            //{
            //    if (IDrawablePtr item = DynamicCast<IDrawable>(*it))
            //        item->Draw(context);
            //}
            //spriteRenderer->Pop();
            //spriteRenderer->End();
        }

        void wxUILayoutRenderPanel::OnMouseButtonDown(wxMouseEvent& event)
        {
            //const Ray ray(Vector3(event.GetX(), event.GetY(), 0), Vector3(0.0f, 0.0f, -1.0f));
            //PickingContext context(ray, true, false, true);
            //if (EntityExtension::Pick(GetTargetPointee(), context))
            //{
            //    HKAssertDebug(context.GetResults().size() == 1);

            //    const PickResult& result = context.GetResults().front();
            //    EntityPtr pickedEntity = DynamicCast<Entity>(result.SharedObject);
            //    HKAssertDebug(pickedEntity);
            //}
        }

        void wxUILayoutRenderPanel::OnMouseButtonUp(wxMouseEvent& /*event*/)
        {
        }

        void wxUILayoutRenderPanel::OnMouseMotion(wxMouseEvent& /*event*/)
        {
        }
    }
}