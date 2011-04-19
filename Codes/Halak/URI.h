#pragma once
#ifndef __HALAK_URI_H__
#define __HALAK_URI_H__

#   include <Halak/Foundation.h>
#   include <Halak/String.h>

    namespace Halak
    {
        class URI
        {
            public:
                enum Source
                {
                    FileSystem,
                    Http,
                    Resource,
                };

            public:
                static const URI Empty;

            public:
                inline URI();
                inline URI(const URI& original);
                inline ~URI();

                inline URI& operator = (const URI& right);
                inline bool operator == (const URI& right) const;
                inline bool operator != (const URI& right) const;

            private:
                Source source;
        };
    }

#   include <Halak/URI.inl>

#endif