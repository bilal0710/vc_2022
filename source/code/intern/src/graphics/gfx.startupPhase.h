#pragma once

#include <SFML/Graphics.hpp>
#include <tinyxml2.h>

namespace Gfx
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
        sf::RenderWindow m_AppWindow;

    public:
        void OnEnter();
        void OnRun(tinyxml2::XMLDocument& _rMetaEntityDoc);
        void OnLeave();

    private:
        CStartupPhase()
        {};
    };
}