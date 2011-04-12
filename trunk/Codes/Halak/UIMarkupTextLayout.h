#pragma once
#ifndef __HALAK_UIMARKUPTEXTLAYOUT_H__
#define __HALAK_UIMARKUPTEXTLAYOUT_H__

#   include <Halak/FWD.h>
#   include <Halak/Color.h>
#   include <Halak/String.h>
#   include <Halak/Vector2.h>
#   include <vector>

    namespace Halak
    {
        // Markup된 문자열이 그려질 때 Layout을 보관하는 객체.
        class UIMarkupTextLayout
        {
           public:
               enum Alignment
               {
                   LeftTopPoint,
                   LeftBottomPoint,
                   LeftMiddlePoint,
                   RightTopPoint,
                   RightBottomPoint,
                   RightMiddlePoint,
                   CenterTopPoint,
                   CenterBottomPoint,
                   CenterPoint,
               };

            public:
                UIMarkupTextLayout();
                UIMarkupTextLayout(const String& text);
                UIMarkupTextLayout(const UIMarkupTextLayout& original);
                ~UIMarkupTextLayout();

                void Draw(DrawingContext& context);

                const String& GetText() const;
                void SetText(const String& value);

                const UIMarkupText& GetMarkupText() const;
                
                // Layout된 이후의 최종 크기를 가져온다.
                Vector2 GetSize();

                Alignment GetAlign() const;
                void SetAlign(Alignment value);

                float GetBoundary() const;
                void  SetBoundary(float value);

                FontPtr GetFont() const;
                void SetFont(FontPtr value);

                int GetNumberOfContents();

                float GetDisplayContentLength();
                void  SetDisplayContentLength(float value);

                UIMarkupTextLayout& operator = (const UIMarkupTextLayout& original);
                bool operator == (const UIMarkupTextLayout& right) const;
                bool operator != (const UIMarkupTextLayout& right) const;

            private:
                class Block;
                class TextBlock;
                class Line;
                class LayoutContext;

                typedef std::vector<Block*> BlockCollection;
                typedef std::vector<Line*>  LineCollection;

            private:
                void UpdateLayout();
                void DeleteAllLines();

                static void Copy(LineCollection& target, const LineCollection& original);

            private:
                UIMarkupText* markupText;
                Alignment align;
                float boundary;
                FontPtr font; 
                int numberOfContents;
                float displayContentLength;
                bool layoutChanged;

                LineCollection lines;
                Vector2 size;

            private:
                class Block
                {
                    public:
                        virtual ~Block();

                        virtual Block* Clone() const = 0;
                        virtual void Draw(SpriteRenderer* renderer, float& outLength) = 0;

                        // Summary:
                        // Block을 배치하다가 경계를 넘어갔을 때,
                        // Block의 일부분만 다음 줄에 배치하고 싶을 때 override하여 사용합니다.
                        // Return:
                        // 다음 줄에 배치할 Block을 반환합니다.
                        // 만약 nullptr을 반환하면 Block 전체를 다음 줄에 배치합니다.
                        virtual Block* Divide(float cutWidth);

                    public:
                        Vector2 Position;
                        Vector2 Offset;
                        Vector2 Size;
                        Color Tint;
                };

                class TextBlock : public Block
                {
                    public:
                        TextBlock(const String& text, FontPtr font);
                        virtual ~TextBlock();

                        virtual TextBlock* Clone() const;
                        virtual void Draw(SpriteRenderer* renderer, float& outLength);

                        virtual TextBlock* Divide(float cutWidth);

                        int GetNumberOfGlyphs() const;

                    private:
                        String text;
                        FontPtr font;
                        FontString* fontString;
                };

                class Line
                {
                    public:
                        Line();
                        Line(const Line& original);
                        ~Line();

                        void UpdateSize(float defaultHeight);
                        void AdjustBlocks(float y, float boundary, Alignment alignment);

                    public:
                        BlockCollection Blocks;
                        Vector2 Size;
                };

                class LayoutContext
                {
                    public:
                        explicit LayoutContext(UIMarkupTextLayout* layout);
                        ~LayoutContext();

                        void Push(Block* item);
                        void Wrap();

                        FontPtr GetFont() const;
                        void SetFont(FontPtr value);

                    private:
                        UIMarkupTextLayout* layout;
                        Line*   line;
                        Vector2 position;
                        FontPtr font;
                };
        };
    }

#   include <Halak/UIMarkupTextLayout.inl>

#endif