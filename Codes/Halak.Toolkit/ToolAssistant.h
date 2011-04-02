#pragma once
#ifndef __HALAK_TOOLKIT_TOOLASSISTANT_H__
#define __HALAK_TOOLKIT_TOOLASSISTANT_H__

#   include <Halak.Toolkit/FWD.h>
#   include <Halak/Service.h>
#   include <Halak/AnyPtr.h>
#   include <list>
#   include <map>

    namespace Halak
    {
        namespace Toolkit
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