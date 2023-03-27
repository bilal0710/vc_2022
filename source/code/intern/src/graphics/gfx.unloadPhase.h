#pragma once
#pragma once

namespace Gfx
{
    class UnloadPhase
    {
    public:
        static UnloadPhase& GetInstance()
        {
            static UnloadPhase instance;
            return instance;
        };

        UnloadPhase(const UnloadPhase&) = delete;
        UnloadPhase& operator = (const UnloadPhase&) = delete;

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();

    private:
        UnloadPhase()
        {};
    };
}