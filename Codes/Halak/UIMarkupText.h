//#pragma once
//#ifndef __HALAK_UIMARKUPTEXT_H__
//#define __HALAK_UIMARKUPTEXT_H__
//
//#   include <Halak/FWD.h>
//#   include <Halak/String.h>
//
//    namespace Halak
//    {
//        class UIMarkupText
//        {
//            public:
//                class Phrase
//                {
//                    public:
//                        const Halak::String& GetText() const;
//
//                    protected:
//                        Phrase();
//                        Phrase(const Halak::String& text);
//                        Phrase(const Phrase& original);
//                        virtual ~Phrase();
//
//                        virtual Phrase* Clone() const = 0;
//
//                    private:
//                        String text;
//
//                    private:
//                        Phrase& operator = (const Phrase&);
//
//                        friend class MarkupText;
//                };
//
//                class TextPhrase : public Phrase
//                {
//                    private:
//                        TextPhrase(const Halak::String& text);
//                        TextPhrase(const TextPhrase& original);
//                        virtual ~TextPhrase();
//
//                        virtual TextPhrase* Clone() const;
//
//                        friend class MarkupText;
//                };
//
//                class NewLinePhrase : public Phrase
//                {
//                    friend class MarkupText;
//                private:
//                    NewLinePhrase();
//                    NewLinePhrase(const NewLinePhrase& original);
//                    virtual ~NewLinePhrase();
//
//                    virtual NewLinePhrase* Clone() const;
//                };
//
//                class ColorPhrase : public Phrase
//                {
//                    friend class MarkupText;
//                public:
//                    Color* GetColor() const;
//
//                private:
//                    ColorPhrase(const Halak::String& text);
//                    ColorPhrase(const ColorPhrase& original);
//                    virtual ~ColorPhrase();
//
//                    virtual ColorPhrase* Clone() const;
//
//                private:
//                    Color* color;
//                };
//
//                class ContentPhrase : public Phrase
//                {
//                    friend class MarkupText;
//                public:
//                    const Halak::String& GetType() const;
//                    const Halak::String& GetName() const;
//                    const std::map<Halak::String, Halak::String> GetAttributes() const;
//
//                private:
//                    ContentPhrase(const Halak::String& text);
//                    ContentPhrase(const ContentPhrase& original);
//                    virtual ~ContentPhrase();
//
//                    virtual ContentPhrase* Clone() const;
//
//                    void ParseAttributes(const Halak::String& text);
//
//                private:
//                    Halak::String type;
//                    Halak::String name;
//                    std::map<Halak::String, Halak::String> attributes;
//                };
//
//                public:
//                    typedef std::vector<Phrase*> PhraseCollection;
//
//                public:
//                    MarkupText(const Halak::String original);
//                    MarkupText(const MarkupText& original);
//                    ~MarkupText();
//
//                    const Halak::String& GetOriginalText() const;
//                    const Halak::String& GetDisplayText() const;
//                    const PhraseCollection& GetPhrases() const;
//
//                    MarkupText& operator = (const MarkupText& original);
//                    bool operator == (const MarkupText& right) const;
//                    bool operator != (const MarkupText& right) const;
//
//                public:
//                    static const MarkupText Empty;
//
//                private:
//                    MarkupText();
//
//                    void AddSubText(const Halak::String subText);
//                    template <typename T> int AddSpecialPhrase(int index, char open, char close, Halak::String& outSubText);
//
//                    void Parse();
//
//                    static void Copy(PhraseCollection& outTarget, const PhraseCollection& original);
//
//                private:
//                    Halak::String originalText;
//                    Halak::String displayText;
//                    PhraseCollection phrases;
//        };
//    }
//
//#endif