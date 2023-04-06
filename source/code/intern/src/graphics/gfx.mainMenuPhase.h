#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

#define Max_Main_Menu 2

namespace Gfx
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
        void DrawMainMenu(RenderWindow& r_AppWindow);
        void Move();
     
      

    private:
        CMainMenuPhase()
        {};


    private:
        int m_MainMenuSelected;
        Font m_Font;
        Text m_Menu[Max_Main_Menu];
        RectangleShape m_Background;
        Texture m_BackgroundTexture;
    };
}
