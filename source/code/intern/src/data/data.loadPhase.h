#pragma once
#include <tinyxml2.h>

namespace Data
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

    public:
        void OnEnter();
        void OnRun(tinyxml2::XMLDocument& _rMapEntity);
        void OnLeave();

    private:
        CLoadPhase()
        {};
    };
}