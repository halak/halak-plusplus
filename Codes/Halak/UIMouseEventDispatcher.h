#pragma once
#ifndef __HALAK_UIMOUSEEVENTDISPATCHER_H__
#define __HALAK_UIMOUSEEVENTDISPATCHER_H__

#   include <Halak/FWD.h>
#   include <Halak/UpdateableGameComponent.h>
#   include <Halak/MouseState.h>
#   include <vector>

    namespace Halak
    {
        class UIMouseEventDispatcher : public UpdateableGameComponent
        {
            HKClassFOURCC('U', 'I', 'M', 'S');
            public:
                UIMouseEventDispatcher();
                virtual ~UIMouseEventDispatcher();

                virtual void Update(float dt, uint timestamp);

                inline UIDomain* GetDomain() const;
                void SetDomain(UIDomain* value);

                inline Mouse* GetDevice() const;
                void SetDevice(Mouse* value);

                inline UIRenderer* GetRenderer() const;
                inline void SetRenderer(UIRenderer* value);

            private:
                UIDomain* domain;
                Mouse* device;
                UIRenderer* renderer;
                UIVisualPtr capturedVisual;
                UIVisualPtr lastTargetVisual;
                MouseState  lastMouseState;

                typedef std::vector<UIVisual*> VisualVector;
                VisualVector cachedEnterVisuals;
                VisualVector cachedLeaveVisuals;
        };
    }

#   include <Halak/UIMouseEventDispatcher.inl>

#endif