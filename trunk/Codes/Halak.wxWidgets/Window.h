#pragma once
#ifndef __HALAK_WXWIDGETS_WINDOW_H__
#define __HALAK_WXWIDGETS_WINDOW_H__

#   include <Halak.wxWidgets/FWD.h>
#   include <Halak/Window.h>
#   include <wx/wx.h>

    namespace Halak
    {
        namespace wxWidgets
        {
            class Window : public Halak::Window
            {
                public:
                    Window(wxWindow* window);
                    virtual ~Window();

                    virtual void Close();

                    virtual Point GetPosition() const;
                    virtual void  SetPosition(Point value);

                    virtual Point GetSize() const;
                    virtual void  SetSize(Point value);

                    virtual bool GetVisible() const;
                    virtual void SetVisible(bool value);

                    virtual void* GetHandle() const;

                private:
                    wxWindow* window;
            };
        }
    }

#endif