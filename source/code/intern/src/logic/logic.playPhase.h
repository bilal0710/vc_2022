#pragma once

#include "../core/core_vector.h"


namespace Logic
{
    class CPlayPhase
    {
    public:
        static CPlayPhase& GetInstance()
        {
            static CPlayPhase instance;
            return instance;
        };

        CPlayPhase(const CPlayPhase&) = delete;
        CPlayPhase& operator = (const CPlayPhase&) = delete;

    private:
        CPlayPhase():m_PlayerCollidedWithGround(true)
        {};

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();
        void MovePlayer(Core::Float2 _Step);


    private:
        float m_Step = 4.0f;
        bool m_PlayerCollidedWithGround;
    };
}