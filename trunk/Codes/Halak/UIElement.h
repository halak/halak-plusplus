#pragma once
#ifndef __HALAK_UIELEMENT_H__
#define __HALAK_UIELEMENT_H__

#   include <Halak/FWD.h>
#   include <Halak/SharedObject.h>

    namespace Halak
    {
        class UIElement : public SharedObject
        {
            HKThisIsNoncopyableClass(UIElement);
            public:
                UIElement();
                virtual ~UIElement();
        };
    }

#   include <Halak/UIElement.inl>

#endif