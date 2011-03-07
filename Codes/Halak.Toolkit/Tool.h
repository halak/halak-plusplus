#pragma once
#ifndef __HALAK_WXTOOLKIT_TOOL_H__
#define __HALAK_WXTOOLKIT_TOOL_H__

#   include <Halak.wxToolkit/FWD.h>

    namespace Halak
    {
        namespace wxToolkit
        {
            class Tool
            {
                public:
                    enum Status
                    {
                        DeadStatus,
                        AliveStatus,
                        ActiveStatus,
                    };

                public:
                    virtual ~Tool();

                    Status GetStatus() const;

                    bool GetAlive() const;
                    void SetAlive(bool value);

                    bool GetActive() const;
                    void SetActive(bool value);

                protected:
                    Tool();

                    virtual void OnStatusChanged(Status old);

                private:
                    bool alive;
                    bool active;
            };
        }
    }

#endif