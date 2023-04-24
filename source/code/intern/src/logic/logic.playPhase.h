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
        CPlayPhase()
        {};

    public:
        void OnEnter();
        void OnRun(Core::Float3 orientation);
        void OnLeave();


    };
}