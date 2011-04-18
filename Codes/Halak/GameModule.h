#pragma once
#ifndef __HALAK_GAMEMODULE_H__
#define __HALAK_GAMEMODULE_H__

#   include <Halak/FWD.h>
#   include <Halak/GameComponent.h>
#   include <Halak/ICloneable.h>
#   include <Halak/String.h>

    namespace Halak
    {
        class GameModule : public GameComponent, public ICloneable
        {
            HKClassFOURCC('G', 'M', 'D', 'L');
            public:
                GameModule();
                explicit GameModule(uint32 id);
                GameModule(const GameModule& original, CloningContext& context);
                virtual ~GameModule();

                virtual GameModule* CloneWith(CloningContext& context) const;

                inline const String& GetName() const;
                inline void SetName(const String& value);
                inline const String& GetFilename() const;
                inline void SetFilename(const String& value);
                inline const String& GetDescription() const;
                inline void SetDescription(const String& value);

                virtual ICloneable* QueryCloneableInterface();

            private:
                String name;
                String filename;
                String description;
        };
    }

#   include <Halak/GameModule.inl>

#endif