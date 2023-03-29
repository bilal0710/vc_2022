#pragma once

namespace Logic
{
    class CStartupPhase
    {
    public:
        static CStartupPhase& GetInstance()
        {
            static CStartupPhase instance;
            return instance;
        };

        CStartupPhase(const CStartupPhase&) = delete;
        CStartupPhase& operator = (const CStartupPhase&) = delete;


    private:
        CStartupPhase()
        {};

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();

    };
}