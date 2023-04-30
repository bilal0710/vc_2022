#pragma once

#include "../core/core_vector.h"
#include "../data/data.playerSystem.h"
#include "../data/data.entitySystem.h"
#include "../data/data.entityCategory.h"
#include "../data/data.eventSystem.h"
#include "logic/logic.inputSystem.h"

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
        CPlayPhase() :m_PlayerTouchedGround(true), m_PlayerCanMoveDown(false), m_PlayerCanMoveUp(false)
        {};

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();
        void MovePlayer(Core::Float2 _Step);


    private:
        float m_Step = 8.0f;
        bool m_PlayerTouchedGround;
        bool m_PlayerCanMoveUp;
        bool m_PlayerCanMoveDown;
        SInputType::Enum m_Command;
    };
}