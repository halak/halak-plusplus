//#pragma once
//#ifndef __HALAK_TOOLKIT_ENTITYRENDERPANEL_H__
//#define __HALAK_TOOLKIT_ENTITYRENDERPANEL_H__
//
//#   include <Halak.Toolkit/FWD.h>
//#   include <Halak.Toolkit/RenderPanel.h>
//#   include <Halak/Color.h>
//
//    namespace Halak
//    {
//        namespace Toolkit
//        {
//            class EntityRenderPanel : public RenderPanel
//            {
//                public:
//                    EntityRenderPanel(wxWindow* parent, EntityDocument* document);
//
//                    Color GetClearColor() const;
//                    void SetClearColor(Color value);
//
//                    RootEntityPtr GetTargetPointee() const;
//                    void SetTarget(const RootEntityPtr value);
//
//                    SpriteRenderer* GetSpriteRenderer() const;
//                    void SetSpriteRenderer(SpriteRenderer* value);
//
//                protected:
//                    void OnMouseButtonDown(wxMouseEvent& event);
//                    void OnMouseButtonUp(wxMouseEvent& event);
//                    void OnMouseMotion(wxMouseEvent& event);
//
//                    virtual void Draw();
//
//                private:
//                    Color clearColor;
//                    RootEntity* target;
//                    SpriteRenderer* spriteRenderer;
//
//                private:
//                    DECLARE_EVENT_TABLE()
//            };
//        }
//    }
//
//#endif