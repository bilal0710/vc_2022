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
        Entity* GetPlayer();
        void SetPlayer(Entity* pPlayer);

    private:
        CPlayerSystem()
        {};

    private:
        Entity* m_pPlayer;
    };
}