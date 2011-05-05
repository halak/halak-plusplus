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
        // Markup�� ���ڿ��� �׷��� �� Layout�� �����ϴ� ��ü.
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
                
                // Layout�� ������ ���� ũ�⸦ �����´�.
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
                        // Block�� ��ġ�ϴٰ� ��踦 �Ѿ�� ��,
                        // Block�� �Ϻκи� ���� �ٿ� ��ġ�ϰ� ���� �� override�Ͽ� ����մϴ�.
                        // Return:
                        // ���� �ٿ� ��ġ�� Block�� ��ȯ�մϴ�.
                        // ���� nullptr�� ��ȯ�ϸ� Block ��ü�� ���� �ٿ� ��ġ�մϴ�.
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