#pragma once
#ifndef __HALAK_WXTOOLKIT_TOOLASSISTANT_H__
#define __HALAK_WXTOOLKIT_TOOLASSISTANT_H__

#   include <Halak.wxToolkit/FWD.h>
#   include <Halak/Service.h>
#   include <Halak/AnyPtr.h>
#   include <list>
#   include <map>

    namespace Halak
    {
        namespace wxToolkit
        {
            class ToolAssistant : public Service
            {
                public:
                    typedef std::list<ToolPtr> ToolCollection;
                    typedef std::map<AnyPtr, ToolCollection> ToolDictionary;

                public:
                    ToolAssistant(IGlobalSignals* signals);

                protected:
                    virtual ~ToolAssistant();

                private:
                    ToolDictionary tools;
            };
        }
    }

#endif