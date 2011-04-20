//#include <Halak.Toolkit/PCH.h>
//#include <Halak.Toolkit/EntityRenderPanel.h>
//#include <Halak.Toolkit/EntityDocument.h>
//#include <Halak.Toolkit/wxWidgetsApplication.h>
//#include <Halak.Toolkit/wxWidgetsWindow.h>
//#include <Halak/DisplaySwapChain.h>
//#include <Halak/DrawingContext.h>
//#include <Halak/EntityExtension.h>
//#include <Halak/GameStructure.h>
//#include <Halak/GraphicsDevice.h>
//#include <Halak/IDrawable.h>
//#include <Halak/IPickable.h>
//#include <Halak/Ray.h>
//#include <Halak/RootEntity.h>
//#include <Halak/SpriteRenderer.h>
//#include <Halak/Timeline.h>
//
//namespace Halak
//{
//    namespace Toolkit
//    {
//        BEGIN_EVENT_TABLE(EntityRenderPanel, RenderPanel)
//            EVT_LEFT_DOWN   (OnMouseButtonDown)
//            EVT_LEFT_UP     (OnMouseButtonUp)
//            EVT_RIGHT_DOWN  (OnMouseButtonDown)
//            EVT_RIGHT_UP    (OnMouseButtonUp)
//            EVT_MIDDLE_DOWN (OnMouseButtonDown)
//            EVT_MIDDLE_UP   (OnMouseButtonUp)
//            EVT_MOTION      (OnMouseMotion)
//        END_EVENT_TABLE()
//
//        EntityRenderPanel::EntityRenderPanel(wxWindow* parent, EntityDocument* document)
//            : RenderPanel(parent),
//              clearColor(Color::CornflowerBlue),
//              target(document->GetEntity()),
//              spriteRenderer(nullptr)
//        {
//            wxWidgetsWindow* adaptedWindow = new wxWidgetsWindow(this);
//            DisplaySwapChain* swapChain = new DisplaySwapChain(wxWidgetsApplication::GetInstance()->GetGraphicsDevice(), adaptedWindow, Point(800, 600));
//            //document->GetLocalServices()->Add(adaptedWindow);
//            //document->GetLocalServices()->Add(swapChain);
//            spriteRenderer = wxWidgetsApplication::GetInstance()->GetSpriteRenderer();
//            SetSwapChain(swapChain);
//            document->GetTimeline()->SetSpeed(1.0f);
//
//                //MainWindow* mainWindow = wxWidgetsApplication::GetInstance()->GetMainWindow();
//                //EntityRenderPanel* renderPanel = new EntityRenderPanel(mainWindow);
//                //renderPanel->SetTarget(rootEntity);
//                //mainWindow->AddNotebookPage(renderPanel, rootEntity->GetName());
//
//                //EntityDocumentPtr document = GetDocumentFolder()->Find(rootEntity);
//                //AdaptedWxWindow*  panelWindow    = new AdaptedWxWindow(renderPanel);
//                //DisplaySwapChain* panelSwapChain = new DisplaySwapChain(wxWidgetsApplication::GetInstance()->GetGraphicsDevice(), panelWindow);
//                //document->GetLocalServices()->Add(panelWindow);
//                //document->GetLocalServices()->Add(panelSwapChain);
//
//                //renderPanel->SetSwapChain(panelSwapChain);
//                //renderPanel->SetSpriteRenderer(wxWidgetsApplication::GetInstance()->GetSpriteRenderer());
//
//                //document->GetTimeline()->SetSpeed(1.0f);
//           //{
//           // EntityRenderPanel* renderPanel = new EntityRenderPanel(mainWindow);
//           // renderPanel->SetTarget(entity);
//           // mainWindow->AddNotebookPage(renderPanel, "TEST1");
//           // AdaptedWxWindow* panelWindow = new AdaptedWxWindow(renderPanel);
//           // DisplaySwapChain* panelSwapChain = new DisplaySwapChain(GetGraphicsDevice(), panelWindow);
//           // Timeline* timeline = new Timeline();
//           // CommandHistory* history = new CommandHistory();
//           // GetServices()->Add(panelWindow);
//           // GetServices()->Add(panelSwapChain);
//           // GetServices()->Add(timeline);
//           // GetServices()->Add(history);
//           // renderPanel->SetSwapChain(panelSwapChain);
//           // renderPanel->SetSpriteRenderer(GetSpriteRenderer());
//           // renderPanel->SetName("AA");
//           // timeline->Add(emitter);
//           // propertiesWindow->SetHistory(history);
//           // propertiesWindow->SetTarget(emitter);
//           // historyWindow->SetHistory(history);
//           // mainWindow->SetHistory(history);
//           // }
//        }
//
//        Color EntityRenderPanel::GetClearColor() const
//        {
//            return clearColor;
//        }
//
//        void EntityRenderPanel::SetClearColor(Color value)
//        {
//            clearColor = value;
//        }
//
//        RootEntityPtr EntityRenderPanel::GetTargetPointee() const
//        {
//            return target;
//        }
//
//        void EntityRenderPanel::SetTarget(const RootEntityPtr value)
//        {
//            if (target != value)
//            {
//                target = value;
//            }
//        }
//
//        SpriteRenderer* EntityRenderPanel::GetSpriteRenderer() const
//        {
//            return spriteRenderer;
//        }
//
//        void EntityRenderPanel::SetSpriteRenderer(SpriteRenderer* value)
//        {
//            spriteRenderer = value;
//        }
//
//        void EntityRenderPanel::Draw()
//        {
//            GetSwapChain()->GetGraphicsDevice()->Clear(clearColor);
//
//            if (spriteRenderer == nullptr || target == nullptr)
//                return;
//
//            const float sx = static_cast<float>(GetScrollPos(wxHORIZONTAL));
//            const float sy = static_cast<float>(GetScrollPos(wxVERTICAL));
//
//            DrawingContext context(spriteRenderer);
//            spriteRenderer->Begin();
//            spriteRenderer->Push(Matrix4::Translation(Vector3(-sx, -sy, 0.0f)));
//            const Entity::EntityCollection& children = target->GetChildren();
//            for (Entity::EntityCollection::const_iterator it = children.begin(); it != children.end(); it++)
//            {
//                if (IDrawablePtr item = DynamicCast<IDrawable>(*it))
//                    item->Draw(context);
//            }
//            spriteRenderer->Pop();
//            spriteRenderer->End();
//        }
//
//        void EntityRenderPanel::OnMouseButtonDown(wxMouseEvent& event)
//        {
//            const Ray ray(Vector3(event.GetX(), event.GetY(), 0), Vector3(0.0f, 0.0f, -1.0f));
//            PickingContext context(ray, true, false, true);
//            if (EntityExtension::Pick(GetTargetPointee(), context))
//            {
//                HKAssertDebug(context.GetResults().size() == 1);
//
//                const PickResult& result = context.GetResults().front();
//                EntityPtr pickedEntity = DynamicCast<Entity>(result.SharedObject);
//                HKAssertDebug(pickedEntity);
//            }
//        }
//
//        void EntityRenderPanel::OnMouseButtonUp(wxMouseEvent& /*event*/)
//        {
//        }
//
//        void EntityRenderPanel::OnMouseMotion(wxMouseEvent& /*event*/)
//        {
//        }
//    }
//}