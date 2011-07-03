#pragma once
#ifndef __HALAK_FONTLIBRARY_H__
#define __HALAK_FONTLIBRARY_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/String.h>
#   include <vector>

    namespace Halak
    {
        class FontLibrary : public GameComponent
        {
            HKClassFOURCC('F', 'T', 'L', 'B');
            public:
                typedef std::pair<unsigned int, FontCachePtr> CachePair;
                typedef std::vector<CachePair> CacheCollection;

            public:
                FontLibrary();
                FontLibrary(GraphicsDevice* graphicsDevice);
                virtual ~FontLibrary();

                inline GraphicsDevice* GetGraphicsDevice() const;
                void SetGraphicsDevice(GraphicsDevice* value);

                inline const String& GetOSFontDirectory() const;

                inline const String& GetAlternativeFace() const;

                FontCache* GetCache(const FontCacheParameters& parameters);

                // ResultType: FT_Library
                void* GetFTLibrary() const;

            private:
                void Construct();

            private:
                GraphicsDevice* graphicsDevice;
                String osFontDirectory;
                String alternativeFace;
                CacheCollection caches;

                struct Fields;
                Fields* m;
        };
    }

#   include <Halak/FontLibrary.inl>

#endif