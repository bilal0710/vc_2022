#include "data.playerSystem.h"

namespace Data
{
    CEntity* CPlayerSystem::GetPlayer()
    {
        return m_pPlayer;
    }

    void CPlayerSystem::SetPlayer(CEntity* _pPlayer)
    {
        m_pPlayer = _pPlayer;
    }

}
