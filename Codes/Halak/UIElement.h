#pragma once
#ifndef __HALAK_UIELEMENT_H__
#define __HALAK_UIELEMENT_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>
#   include <Halak/String.h>

    namespace Halak
    {
        class UIElement : public SharedObject
        {
            HKThisIsNoncopyableClass(UIElement);
            public:
                UIElement();
                virtual ~UIElement();

                inline const String& GetName() const;
                inline void SetName(const String& value);

            private:
                String name;
        };
    }

#   include <Halak/UIElement.inl>

#endif