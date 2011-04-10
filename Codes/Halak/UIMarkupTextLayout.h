//#pragma once
//#ifndef __HALAK_UIMARKUPTEXTLAYOUT_H__
//#define __HALAK_UIMARKUPTEXTLAYOUT_H__
//
//#   include <Halak/FWD.h>
//#   include <Halak/String.h>
//#   include <Halak/UIMarkupText.h>
//
//    namespace Halak
//    {
//        class UIMarkupTextLayout
//        {
//            class MarkupTextLayout
//            {
//                public:
//                    MarkupTextLayout();
//                    MarkupTextLayout(const Halak::String& text);
//                    MarkupTextLayout(const MarkupTextLayout& original);
//                    ~MarkupTextLayout();
//
//                    void Draw(Halak::DrawingContext& context);
//
//                    const Halak::String& GetText() const;
//                    void SetText(const Halak::String& value);
//
//                    const MarkupText& GetMarkupText() const;
//                    Vector2 GetSize();
//
//                    Alignment::E GetAlign() const;
//                    void SetAlign(Alignment::E value);
//
//                    float GetBoundary() const;
//                    void  SetBoundary(float value);
//
//                    Halak::FontPtr GetFont() const;
//                    void SetFont(Halak::FontPtr value);
//
//                    int GetNumberOfContents();
//
//                    float GetDisplayContentLength();
//                    void  SetDisplayContentLength(float value);
//
//                    MarkupTextLayout& operator = (const MarkupTextLayout& original);
//                    bool operator == (const MarkupTextLayout& right) const;
//                    bool operator != (const MarkupTextLayout& right) const;
//
//                private:
//                    class Block;
//                    class TextBlock;
//                    class Line;
//                    class LayoutContext;
//
//                    typedef std::vector<Block*> BlockCollection;
//                    typedef std::vector<Line*>  LineCollection;
//
//                private:
//                    void UpdateLayout();
//                    void DeleteAllLines();
//
//                    static void Copy(LineCollection& target, const LineCollection& original);
//
//                private:
//                    MarkupText* markupText;
//                    Alignment::E alignment;
//                    float boundary;
//                    Halak::FontPtr font; 
//                    int numberOfContents;
//                    float displayContentLength;
//                    bool layoutChanged;
//
//                    LineCollection lines;
//                    Vector2 size;
//
//                private:
//                    class Block
//                    {
//                        public:
//                            virtual ~Block();
//
//                            virtual Block* Clone() const = 0;
//                            virtual void Draw(Halak::SpriteRenderer* renderer, float& outLength) = 0;
//
//                            // Summary:
//                            // Block을 배치하다가 경계를 넘어갔을 때,
//                            // Block의 일부분만 다음 줄에 배치하고 싶을 때 override하여 사용합니다.
//                            // Return:
//                            // 다음 줄에 배치할 Block을 반환합니다.
//                            // 만약 nullptr을 반환하면 Block 전체를 다음 줄에 배치합니다.
//                            virtual Block* Divide(float cutWidth);
//
//                        public:
//                            Vector2 Position;
//                            Vector2 Offset;
//                            Vector2 Size;
//                            Color Tint;
//                    };
//
//                    class TextBlock : public Block
//                    {
//                        public:
//                            TextBlock(const Halak::String& text, Halak::FontPtr font);
//                            virtual ~TextBlock();
//
//                            virtual TextBlock* Clone() const;
//                            virtual void Draw(Halak::SpriteRenderer* renderer, float& outLength);
//
//                            virtual TextBlock* Divide(float cutWidth);
//
//                            int GetNumberOfGlyphs() const;
//
//                        private:
//                            Halak::String text;
//                            Halak::FontPtr font;
//                            Halak::FontString* fontString;
//                    };
//
//                    class Line
//                    {
//                        public:
//                            Line();
//                            Line(const Line& original);
//                            ~Line();
//
//                            void UpdateSize(float defaultHeight);
//                            void AdjustBlocks(float y, float boundary, Alignment::E alignment);
//
//                        public:
//                            BlockCollection Blocks;
//                            Vector2 Size;
//                    };
//
//                    class LayoutContext
//                    {
//                        public:
//                            explicit LayoutContext(MarkupTextLayout* layout);
//                            ~LayoutContext();
//
//                            void Push(Block* item);
//                            void Wrap();
//
//                            Halak::FontPtr GetFont() const;
//                            void SetFont(Halak::FontPtr value);
//
//                        private:
//                            MarkupTextLayout* layout;
//                            Line*   line;
//                            Vector2 position;
//                            Halak::FontPtr font;
//                    };
//            };
//        };
//    }
//
//#endif