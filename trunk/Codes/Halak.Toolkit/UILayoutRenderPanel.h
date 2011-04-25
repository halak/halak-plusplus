#pragma once
#ifndef __HALAK_TOOLKIT_UILAYOUTRENDERPANEL_H__
#define __HALAK_TOOLKIT_UILAYOUTRENDERPANEL_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak.Toolkit/RenderPanel.h>
#   include <Halak/Color.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class UILayoutRenderPanel : public RenderPanel
            {
                public:
                    UILayoutRenderPanel(wxWindow* parent);

                    UIDomain* GetDomain() const;
                    void SetDomain(UIDomain* value);

                    SpriteRenderer* GetRenderer() const;
                    void SetRenderer(SpriteRenderer* value);

                    Color GetClearColor() const;
                    void SetClearColor(Color value);

                protected:
                    void OnMouseButtonDown(wxMouseEvent& event);
                    void OnMouseButtonUp(wxMouseEvent& event);
                    void OnMouseMotion(wxMouseEvent& event);

                    virtual void Draw();

                private:
                    UIDomain* domain;
                    SpriteRenderer* renderer;
                    Color clearColor;

                private:
                    DECLARE_EVENT_TABLE()
            };
        }
    }

#endif