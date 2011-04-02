#pragma once
#ifndef __HALAK_TOOLKIT_ADAPTEDWXWINDOW_H__
#define __HALAK_TOOLKIT_ADAPTEDWXWINDOW_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/Window.h>
#   include <wx/wx.h>

    namespace Halak
    {
        namespace Toolkit
        {
            class AdaptedWxWindow : public Halak::Window
            {
                public:
                    AdaptedWxWindow(wxWindow* window);

                    virtual void Close();

                    virtual Point GetPosition() const;
                    virtual void  SetPosition(Point value);

                    virtual Point GetSize() const;
                    virtual void  SetSize(Point value);

                    virtual bool GetVisible() const;
                    virtual void SetVisible(bool value);

                    virtual void* GetHandle() const;

                private:
                    virtual ~AdaptedWxWindow();

                private:
                    wxWindow* window;
            };
        }
    }

#endif