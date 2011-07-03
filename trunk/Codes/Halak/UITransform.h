#pragma once
#ifndef __HALAK_UITRANSFORM_H__
#define __HALAK_UITRANSFORM_H__

#   include <Halak/FWD.h>
#   include <Halak/UIElement.h>
#   include <Halak/Matrix4.h>

    namespace Halak
    {
        class UITransform : public UIElement
        {
            public:
                virtual ~UITransform();

                virtual const Matrix4& ComputeMatrix(UIVisualVisitor& visitor) = 0;

            protected:
                UITransform();
        };
    }

#   include <Halak/UITransform.inl>

#endif