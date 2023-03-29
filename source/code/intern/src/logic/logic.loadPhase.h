#pragma once
namespace Logic
{
    class CLoadPhase
    {
    public:
        static CLoadPhase& GetInstance()
        {
            static CLoadPhase instance;
            return instance;
        };

        CLoadPhase(const CLoadPhase&) = delete;
        CLoadPhase& operator = (const CLoadPhase&) = delete;

    private:
        CLoadPhase()
        {};

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();

 
    };
}