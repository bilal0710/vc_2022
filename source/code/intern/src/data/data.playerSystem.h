#pragma once

#include "data.entity.h"

namespace Data
{
    class CPlayerSystem
    {
    public:
        static CPlayerSystem& GetInstance()
        {
            static CPlayerSystem instance;
            return instance;
        };

        CPlayerSystem(const CPlayerSystem&) = delete;
        CPlayerSystem& operator = (const CPlayerSystem&) = delete;

    public:
        CEntity* GetPlayer();
        void SetPlayer(CEntity* pPlayer);

    private:
        CPlayerSystem()
        {};

    private:
        CEntity* m_pPlayer;
    };
}