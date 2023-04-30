#pragma once
#include <data/data.event.h>

namespace Gui
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

    private:
        CPlayPhase()
        {};

    public:
        static void RegisterEvent(Data::CEvent& data);

    private: 
        float m_Step = 4.0f;
        float m_Jump = 16.0f;
        float m_XLimitLeft = 20.0f;
        float m_XLimitRight = 3984.0f;
    };
}