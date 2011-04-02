#pragma once
#ifndef __HALAK_TOOLKIT_JSONDOCUMENT_H__
#define __HALAK_TOOLKIT_JSONDOCUMENT_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/Asset.h>
#   include <Halak/Exception.h>
#   include <Halak/IReloadable.h>
#   include <Halak/Signal.h>
#   include <Halak/String.h>
#   include <vector>

    namespace Halak
    {
        namespace Toolkit
        {
            class JSONDocument : public Asset, public IReloadable
            {
                public:
                    JSONDocument(const String& filename);
                    virtual ~JSONDocument();

                    virtual void Reload();

                    JSONObjectPtr GetRoot();

                    virtual const String& GetFilename() const;
                    void SetFilename(const String& value);

                    virtual Signal<JSONDocument*>& Reloaded();

                private:
                    JSONObjectPtr root;
                    String filename;
                    bool sourceChanged;

                    Signal<JSONDocument*> reloaded;
            };

            class JSONParsingError : public Exception
            {
                public:
                    const String Filename;
                    const int Line;
                    const int Column;

                public:
                    JSONParsingError(int errorCode, const String& filename, int line, int column);
                    JSONParsingError(const JSONParsingError& original);
                    virtual ~JSONParsingError();

                private:
                    JSONParsingError& operator = (const JSONParsingError&);
            };
        }
    }

#endif