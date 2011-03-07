#pragma once
#ifndef __HALAK_WXTOOLKIT_GLOBALSIGNALS_INTERFACE__
#define __HALAK_WXTOOLKIT_GLOBALSIGNALS_INTERFACE__

#   include <Halak.wxToolkit/FWD.h>
#   include <Halak/Signal.h>
#   include <vector>

    namespace Halak
    {
        namespace wxToolkit
        {
            class IGlobalSignals
            {
                public:
                    typedef std::vector<AnyPtr> AnyPtrCollection;

                public:
                    virtual ~IGlobalSignals() { }

                    virtual Signal<AnyPtrCollection>& ObjectCreated() = 0;
                    virtual Signal<AnyPtrCollection>& ObjectDeleted() = 0;
                    virtual Signal<AnyPtrCollection>& ObjectSelected() = 0;

                    virtual Signal<Command*>& CommandExecuted() = 0;
                    virtual Signal<Command*>& CommandUndone() = 0;
                    virtual Signal<Command*>& CommandRedone() = 0;

                    virtual Signal<float, uint>& Updating() = 0;
                    virtual Signal<>& OnTerminating() = 0;
            };
        }
    }

#endif