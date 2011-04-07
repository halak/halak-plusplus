#pragma once
#ifndef __HALAK_WINDOW_H__
#define __HALAK_WINDOW_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/Point.h>
#   include <Halak/Signal.h>

    namespace Halak
    {
        class Window : public GameComponent
        {
            HKDeclareGameComponentClassFOURCC('W', 'I', 'N', 'D');
            public:
                virtual ~Window();

                virtual void Close() = 0;

                virtual Point GetPosition() const = 0;
                virtual void  SetPosition(Point value) = 0;

                virtual Point GetSize() const = 0;
                virtual void  SetSize(Point value) = 0;

                virtual bool GetVisible() const = 0;
                virtual void SetVisible(bool value) = 0;

                virtual void* GetHandle() const = 0;

                inline Signal<int>& MouseWheel();

            private:
                Signal<int> mouseWheel;
        };
    }

#   include <Halak/Window.inl>

#endif