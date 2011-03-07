#include <Halak.wxToolkit/Tool.h>

namespace Halak
{
    namespace wxToolkit
    {
        Tool::Tool()
            : alive(true),
              active(false)
        {
        }

        Tool::~Tool()
        {
        }

        Tool::Status Tool::GetStatus() const
        {
            if (alive)
            {
                if (active)
                    return ActiveStatus;
                else
                    return AliveStatus;
            }
            else
                return DeadStatus;
        }
            
        bool Tool::GetAlive() const
        {
            return alive;
        }
        
        void Tool::SetAlive(bool value)
        {
            if (alive != value)
            {
                const Status oldStatus = GetStatus();
                alive = value;
                OnStatusChanged(oldStatus);
            }
        }
            
        bool Tool::GetActive() const
        {
            return active;
        }

        void Tool::SetActive(bool value)
        {
            if (active != value)
            {
                const Status oldStatus = GetStatus();
                active = value;
                OnStatusChanged(oldStatus);
            }
        }

        void Tool::OnStatusChanged(Status /*old*/)
        {
        }
    }
}