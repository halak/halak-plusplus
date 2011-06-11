#pragma once

#include <Halak/FWD.h>
#include <Halak/SharedObject.h>

namespace Halak
{
    class UIEventArgs : public SharedObject
    {
        public:
            UIEventArgs();
            UIEventArgs(UIVisual* target);
            UIEventArgs(const UIEventArgs& original);
            virtual ~UIEventArgs();

            virtual UIEventArgs* Clone() const;

            inline UIVisual* GetTarget() const;

        private:
            UIVisualPtr target;
    };
}

#include <Halak/UIEventArgs.inl>