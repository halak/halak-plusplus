#pragma once
#ifndef __HALAK_FREETYPE_H__
#define __HALAK_FREETYPE_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/String.h>
#   include <list>

    namespace Halak
    {
        class FreeType : public GameComponent
        {
            public:
                typedef std::list<std::pair<unsigned int, FreeTypeFontRendererPtr> > RendererCollection;

            public:
                FreeType(GraphicsDevice* graphicsDevice);

                GraphicsDevice* GetGraphicsDevice() const;

                const String& GetOSFontDirectory() const;

                const String& GetAlternativeFace() const;

                FreeTypeFontRendererPtr GetRenderer(const FreeTypeFontRendererParameters& parameters);

                // ResultType: FT_Library
                void* GetLibrary() const;

            protected:
                virtual ~FreeType();

            private:
                GraphicsDevice* graphicsDevice;
                String osFontDirectory;
                String alternativeFace;
                RendererCollection renderers;

                struct Fields;
                Fields* m;
        };
    }

#endif