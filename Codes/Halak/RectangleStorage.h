#pragma once
#ifndef __HALAK_RECTANGLESTORAGE_H__
#define __HALAK_RECTANGLESTORAGE_H__

#   include <Halak/FWD.h>
#   include <Halak/Rectangle.h>
#   include <list>

    namespace Halak
    {
        class RectangleStorage
        {
            public:
                typedef std::list<Rectangle> RectangleCollection;

            public:
                RectangleStorage();
                RectangleStorage(int width, int height);
                RectangleStorage(const RectangleStorage& original);
                ~RectangleStorage();

                void Clear();
                void Clear(int width, int height);

                Rectangle Allocate(int width, int height);
                void Deallocate(const Rectangle& rectangle);

                int GetWidth() const;
                int GetHeight() const;

                const RectangleCollection& GetFreeRectangles() const;
                const RectangleCollection& GetAllocatedRectangles() const;

                RectangleStorage& operator = (const RectangleStorage& right);

                bool operator == (const RectangleStorage& right) const;
                bool operator != (const RectangleStorage& right) const;

            private:
                static void Merge(RectangleCollection& rectangles, RectangleCollection::iterator targetIterator);

            private:
                int width;
                int height;
                RectangleCollection freeRectangles;
                RectangleCollection allocatedRectangles;
        };
    }

#endif