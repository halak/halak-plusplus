#pragma once
#ifndef __HALAK_WXWIDGETS_UILAYOUTRENDERPANEL_H__
#define __HALAK_WXWIDGETS_UILAYOUTRENDERPANEL_H__

#   include <Halak.wxWidgets/FWD.h>
#   include <Halak.wxWidgets/wxRenderPanel.h>
#   include <Halak/Color.h>

    namespace Halak
    {
        namespace wxWidgets
        {
            class wxUILayoutRenderPanel : public wxRenderPanel
            {
                public:
                    wxUILayoutRenderPanel(wxWindow* parent);

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