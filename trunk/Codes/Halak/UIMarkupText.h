#pragma once
#ifndef __HALAK_UIMARKUPTEXT_H__
#define __HALAK_UIMARKUPTEXT_H__

#   include <Halak/FWD.h>
#   include <Halak/Color.h>
#   include <Halak/SequenceDictionary.h>
#   include <Halak/String.h>
#   include <vector>

    namespace Halak
    {
        class UIMarkupText
        {
            public:
                enum PhraseType
                {
                    TextPhraseType,
                    NewLinePhraseType,
                    ColorPhraseType,
                    FontPhraseType,
                    ContentPhraseType,
                };

                class Phrase
                {
                    public:
                        inline PhraseType GetType() const;
                        inline int GetIndex() const;
                        inline int GetLegnth() const;

                    protected:
                        Phrase(PhraseType type);
                        Phrase(PhraseType type, int index, int length);
                        Phrase(const Phrase& original);
                        virtual ~Phrase();

                        virtual Phrase* Clone() const = 0;

                    private:
                        PhraseType type;
                        int index;
                        int length;

                    private:
                        Phrase& operator = (const Phrase&);

                        friend class UIMarkupText;
                };

                class TextPhrase : public Phrase
                {
                    private:
                        TextPhrase(const String& originalText, int index, int length);
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
                        inline Color GetColor() const;
                        inline bool  HasColor() const;

                    private:
                        ColorPhrase(const String& originalText, int index, int length);
                        ColorPhrase(const ColorPhrase& original);
                        virtual ~ColorPhrase();

                        virtual ColorPhrase* Clone() const;

                    private:
                        Color color;
                        bool hasColor;

                        friend class UIMarkupText;
                };

                class ContentPhrase : public Phrase
                {
                    public:
                        inline const String& GetContentType() const;
                        inline const String& GetContentName() const;
                        inline const SequenceDictionary& GetAttributes() const;

                    private:
                        ContentPhrase(const String& originalText, int index, int length);
                        ContentPhrase(const ContentPhrase& original);
                        virtual ~ContentPhrase();

                        virtual ContentPhrase* Clone() const;

                        void ParseAttributes(const String& originalText, int index, int length);

                    private:
                        String contentType;
                        String contentName;
                        SequenceDictionary attributes;
                        
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
                void AddSubText(int index, int length);
                template <typename T> int AddSpecialPhrase(int index, char open, char close, int subTextIndex, int subTextLength);

                void Parse();

                static void Copy(PhraseCollection& outTarget, const PhraseCollection& original);

            private:
                String originalText;
                String displayText;
                PhraseCollection phrases;
        };
    }

#endif