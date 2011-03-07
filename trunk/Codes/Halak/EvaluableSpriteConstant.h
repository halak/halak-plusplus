#pragma once
#ifndef __HALAK_EVALUABLESPRITECONSTANT_H__
#define __HALAK_EVALUABLESPRITECONSTANT_H__

#   include <Halak/FWD.h>
#   include <Halak/ISpriteEvaluable.h>

    namespace Halak
    {
        class EvaluableSpriteConstant : public ISpriteEvaluable
        {
            typedef Sprite ValueType;
            public:
                EvaluableSpriteConstant();
                EvaluableSpriteConstant(ValueType value);
                virtual ~EvaluableSpriteConstant();

                virtual ValueType Evaluate();

                ValueType GetValue() const;
                void SetValue(ValueType value);

            private:
                ValueType value;
        };
    }

#endif