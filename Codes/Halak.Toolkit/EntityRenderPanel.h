#pragma once
#ifndef __HALAK_WXTOOLKIT_ENTITYRENDERPANEL_H__
#define __HALAK_WXTOOLKIT_ENTITYRENDERPANEL_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <Halak.wxToolkit/RenderPanel.h>
#   include <Halak/Color.h>

    namespace Halak
    {
        namespace wxToolkit
        {
            class EntityRenderPanel : public RenderPanel
            {
                public:
                    EntityRenderPanel(wxWindow* parent, EntityDocumentPtr document);

                    Color GetClearColor() const;
                    void SetClearColor(Color value);

                    RootEntityPtr GetTargetPointee() const;
                    void SetTarget(const RootEntityPtr value);

                    SpriteRenderer* GetSpriteRenderer() const;
                    void SetSpriteRenderer(SpriteRenderer* value);

                protected:
                    void OnMouseButtonDown(wxMouseEvent& event);
                    void OnMouseButtonUp(wxMouseEvent& event);
                    void OnMouseMotion(wxMouseEvent& event);

                    virtual void Draw();

                private:
                    Color clearColor;
                    RootEntityPtr target;
                    SpriteRenderer* spriteRenderer;

                private:
                    DECLARE_EVENT_TABLE()
            };
        }
    }

#endif