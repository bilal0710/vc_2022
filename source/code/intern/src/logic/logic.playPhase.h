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
        CPlayPhase() :m_PlayerCollidedWithObject(true), m_CanMoveDown(false), m_CanMoveUp(false)
        {};

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();
       // void forLoop(std::vector<Data::CEntity*> Entities, std::vector<Data::CEntity*>* collisionEntities, Core::Float2 _Step);
        void MovePlayer(Core::Float2 _Step);


    private:
        float m_Step = 4.0f;
        bool m_PlayerCollidedWithObject;
        bool m_CanMoveUp;
        bool m_CanMoveDown;
    };
}