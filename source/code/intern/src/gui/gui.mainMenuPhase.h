#pragma once

namespace Gui
{
    class CMainMenuPhase
    {
    public:
        static CMainMenuPhase& GetInstance()
        {
            static CMainMenuPhase instance;
            return instance;
        };

        CMainMenuPhase(const CMainMenuPhase&) = delete;
        CMainMenuPhase& operator = (const CMainMenuPhase&) = delete;

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();

    private:
        CMainMenuPhase()
        {};
    };
}