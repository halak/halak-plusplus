#pragma once
#ifndef __HALAK_UIHANDLEDDRAWINGCONTEXT_H__
#define __HALAK_UIHANDLEDDRAWINGCONTEXT_H__

#   include <Halak/FWD.h>
#   include <Halak/UIDrawingContext.h>

    namespace Halak
    {
        class UIHandledDrawingContext : public UIDrawingContext
        {
            public:
                class IHandler
                {
                    protected:
                        virtual ~IHandler() { }

                        virtual void OnBegan(UIHandledDrawingContext& context) = 0;
                        virtual void OnEnded(UIHandledDrawingContext& context) = 0;
                        virtual void OnDrawBegan(UIHandledDrawingContext& context, UIVisual* target) = 0;
                        virtual void OnDrawEnded(UIHandledDrawingContext& context, UIVisual* target) = 0;

                        friend class UIHandledDrawingContext;
                }; 

            public:
                UIHandledDrawingContext(SpriteRenderer* renderer);
                UIHandledDrawingContext(SpriteRenderer* renderer, IHandler* handler);
                virtual ~UIHandledDrawingContext();

                inline IHandler* GetHandler() const;
                inline void SetHandler(IHandler* value);

            private:
                IHandler* handler;
        };
    }

#   include <Halak/UIHandledDrawingContext.inl>

#endif