#pragma once
#ifndef __HALAK_UIMARKUPTEXT_H__
#define __HALAK_UIMARKUPTEXT_H__

#   include <Halak/FWD.h>
#   include <Halak/String.h>
#   include <vector>

    namespace Halak
    {
        class UIMarkupText
        {
            public:
                class Phrase
                {
                    public:
                        inline const String& GetText() const;

                    protected:
                        Phrase();
                        Phrase(const String& text);
                        Phrase(const Phrase& original);
                        virtual ~Phrase();

                        virtual Phrase* Clone() const = 0;

                    private:
                        String text;

                    private:
                        Phrase& operator = (const Phrase&);

                        friend class UIMarkupText;
                };

                class TextPhrase : public Phrase
                {
                    private:
                        TextPhrase(const String& text);
                        TextPhrase(const TextPhrase& original);
                        virtual ~TextPhrase();

                        virtual TextPhrase* Clone() const;

                        friend class UIMarkupText;
                };

                class NewLinePhrase : public Phrase
                {
                    private:
                        inline NewLinePhrase();
                        inline NewLinePhrase(const NewLinePhrase& original);
                        virtual ~NewLinePhrase();

                        virtual NewLinePhrase* Clone() const;

                        friend class UIMarkupText;
                };

                class ColorPhrase : public Phrase
                {
                    public:
                        inline Color* GetColor() const;

                    private:
                        ColorPhrase(const String& text);
                        ColorPhrase(const ColorPhrase& original);
                        virtual ~ColorPhrase();

                        virtual ColorPhrase* Clone() const;

                    private:
                        Color* color;

                        friend class UIMarkupText;
                };

                class ContentPhrase : public Phrase
                {
                    public:
                        typedef std::pair<String, String> KeyValuePair;
                        typedef std::vector<KeyValuePair> Dictionary;

                    public:
                        inline const String& GetType() const;
                        inline const String& GetName() const;
                        inline const Dictionary& GetAttributes() const;

                        const String& FindAttribute(const String& key) const;

                    private:
                        ContentPhrase(const String& text);
                        ContentPhrase(const ContentPhrase& original);
                        virtual ~ContentPhrase();

                        virtual ContentPhrase* Clone() const;

                        void ParseAttributes(const String& text);

                    private:
                        String type;
                        String name;
                        Dictionary attributes;
                        
                        friend class UIMarkupText;
                };

            public:
                typedef std::vector<Phrase*> PhraseCollection;

            public:
                UIMarkupText();
                UIMarkupText(const String original);
                UIMarkupText(const UIMarkupText& original);
                ~UIMarkupText();

                inline const String& GetOriginalText() const;
                inline const String& GetDisplayText() const;
                inline const PhraseCollection& GetPhrases() const;

                UIMarkupText& operator = (const UIMarkupText& original);
                bool operator == (const UIMarkupText& right) const;
                bool operator != (const UIMarkupText& right) const;

            public:
                static const UIMarkupText Empty;

            private:
                void AddSubText(const String& subText);
                template <typename T> int AddSpecialPhrase(int index, char open, char close, String& inoutSubText);

                void Parse();

                static void Copy(PhraseCollection& outTarget, const PhraseCollection& original);

            private:
                String originalText;
                String displayText;
                PhraseCollection phrases;
        };
    }

#endif