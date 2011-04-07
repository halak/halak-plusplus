#pragma once
#ifndef __HALAK_STRINGREADER_H__
#define __HALAK_STRINGREADER_H__

#   include <Halak/FWD.h>
#   include <Halak/String.h>

    namespace Halak
    {
        class StringReader
        {
            public:
                explicit StringReader(const String& text);

                String ReadLine();

                bool IsTerminated() const;

            private:
                String text;
                int index;
        };
    }

#endif