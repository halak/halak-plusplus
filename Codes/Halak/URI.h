#pragma once
#ifndef __HALAK_URI_H__
#define __HALAK_URI_H__

#   include <Halak/Foundation.h>

    namespace Halak
    {
        class URI
        {
            public:
                enum Source
                {
                    Resource,
                    FileSystem,
                    Http,
                };

            public:
                URI();
                URI(const URI& original);
                ~URI();

                URI& operator = (const URI& right);
                bool operator == (const URI& right) const;
                bool operator != (const URI& right) const;

            private:
        };
    }

#   include <Halak/URI.inl>

#endif