#pragma once
#ifndef __HALAK_SERIALIZABLE_INTERFACE__
#define __HALAK_SERIALIZABLE_INTERFACE__

#   include <Halak/FWD.h>

    namespace Halak
    {
        class ISerializable
        {
            HKInterfaceFOURCC('I', 'S', 'R', 'Z');
            public:
                virtual ~ISerializable() { }

                virtual void Serialize(StreamWriter& writer) = 0;
                virtual void Deserialize(StreamReader& reader) = 0;
        };
    }

#endif