#pragma once

namespace Gfx
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

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();
        //void drawShapes();

    private:
        CPlayPhase()
        {};
    };
}