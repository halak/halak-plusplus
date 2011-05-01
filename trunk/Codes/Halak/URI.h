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
                    Anywhere,
                    FileSystem,
                    EmbeddedResource,
                    Internet,
                };

            public:
                static const URI Empty;

            public:
                URI();
                URI(const char* address);
                URI(const String& address);
                URI(const URI& original);
                ~URI();

                inline Source GetSource() const;
                inline uint32 GetID() const;
                inline const String& GetAddress() const;

                URI& operator = (const URI& right);
                inline bool operator == (const URI& right) const;
                inline bool operator != (const URI& right) const;
                inline bool operator < (const URI& right) const;

                static URI FromFileSystem(const String& path);
                static URI FromEmbeddedResource(uint32 id);
                static URI FromInternet(const String& address);

            private:
                inline URI(Source source, uint id);
                inline URI(Source source, const String& address);

                void Construct(const String& address);

            private:
                Source source;
                uint32 id;
                String address;
        };
    }

#   include <Halak/URI.inl>

#endif