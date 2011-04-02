#pragma once
#ifndef __HALAK_TOOLKIT_TOOL_H__
#define __HALAK_TOOLKIT_TOOL_H__

#   include <Halak.Toolkit/FWD.h>

    namespace Halak
    {
        namespace Toolkit
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