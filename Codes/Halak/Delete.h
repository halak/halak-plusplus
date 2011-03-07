#pragma once
#ifndef __HALAK_DELETE_H__
#define __HALAK_DELETE_H__

    namespace Halak
    {
        template <typename T> void DeleteAll(T& container)
        {
            T deletingContainer;
            deletingContainer.swap(container);

            DeleteAll(deletingContainer.begin(), deletingContainer.end());
        }

        template <typename T> void DeleteAll(T begin, T end)
        {
            for (; begin != end; begin++)
                delete (*begin);
        }
    }

#endif