#include "data.playerSystem.h"

namespace Data
{
    Entity* CPlayerSystem::GetPlayer()
    {
        return m_pPlayer;
    }

    void CPlayerSystem::SetPlayer(Entity* _pPlayer)
    {
        m_pPlayer = _pPlayer;
    }

}
