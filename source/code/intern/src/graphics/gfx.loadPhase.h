#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


namespace Gfx
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
        void OnRun();
        void OnLeave();

    private:
        CLoadPhase()
        {};

    private:
        int  m_Timer = 0;
        Font m_Font;
        Text m_Menu;
        RectangleShape m_Background;
        Texture m_BackgroundTexture;
    };
}