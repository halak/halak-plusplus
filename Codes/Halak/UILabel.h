#pragma once
#ifndef __HALAK_UILABEL_H__
#define __HALAK_UILABEL_H__

#   include <Halak/FWD.h>
#   include <Halak/UIVisual.h>
#   include <Halak/FontString.h>

    namespace Halak
    {
        class UILabel : public UIVisual
        {
            public:
                UILabel();
                virtual ~UILabel();

                inline const String& GetText() const;
                void SetText(const String& value);

                inline Font* GetFont() const;
                void SetFont(Font* value);

                inline bool GetAutoResize() const;
                void SetAutoResize(bool value);

            protected:
                virtual void OnDraw(UIDrawingContext& context);

            private:
                String text;
                FontPtr font;
                FontString fontString;
                bool fontStringChanged;
                bool autoResize;
        };
    }

#   include <Halak/UILabel.inl>

#endif