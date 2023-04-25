#include "gfx.mainMenuPhase.h"

#include"game/game.appWindow.h"
#include <iostream>


using namespace std;


namespace Gfx
{
	void CMainMenuPhase::OnEnter()
	{
		std::cout << "Gfx::MainMenuPhase::OnEnter" << std::endl;

		if (!m_Font.loadFromFile("3Dumb.ttf")) {
			cout << "No font is loaded!" << endl;
		}

		for (int i = 0; i < Max_Main_Menu; i++) {
			m_Menu[i].setFont(m_Font);
			m_Menu[i].setCharacterSize(70);

			if (i == 0) {
				m_Menu[i].setString("Play");
				m_Menu[i].setPosition(900, 550);
				m_Menu[i].setFillColor(Color::Red);
				continue;
			}

			m_Menu[i].setString("Exit");
			m_Menu[i].setPosition(900, 650);
			m_Menu[i].setFillColor(Color::White);
		}
		m_MainMenuSelected = 0;
		
		m_Background.setSize(Vector2f(700, 396));
		m_Background.setPosition(650, 75);
		m_BackgroundTexture.loadFromFile("Mario_BG.png");
		m_Background.setTexture(&m_BackgroundTexture);

	}


	void CMainMenuPhase::EventListener(Data::CEvent& data) 
	{
		std::cout << "GFX::MainMenuPhase -> listen to event" << std::endl;
		Game::CApplicationWindow& rAppWindow = Game::CApplicationWindow::GetInstance();

		CMainMenuPhase MainMenuClass;
		int MainMenuSelected = MainMenuClass.GetInstance().m_MainMenuSelected;

		if (MainMenuSelected == 0) {
			std::cout << "return" << std::endl;
			return;
		}
		if (MainMenuSelected == 1) {
			rAppWindow.m_AppWindow.close();
		}
	}

	void CMainMenuPhase::OnRun()
	{
		cout << "Gfx::MainMenuPhase::OnRun" << endl;
		Game::CApplicationWindow& rAppWindow = Game::CApplicationWindow::GetInstance();
		DrawMainMenu(rAppWindow.m_AppWindow);
		rAppWindow.m_AppWindow.display();

	}


	void CMainMenuPhase::DrawMainMenu(RenderWindow& _rAppWindow)
	{

		_rAppWindow.draw(m_Background);

		for (int i = 0; i < Max_Main_Menu; i++) {

			_rAppWindow.draw(m_Menu[i]);
		}

	}
	void CMainMenuPhase::Move()
	{
		if (m_MainMenuSelected > 0) {

			m_Menu[m_MainMenuSelected].setFillColor(Color::White);
			m_MainMenuSelected--;
			m_Menu[m_MainMenuSelected].setFillColor(Color::Red);
			return;
		}
		m_Menu[m_MainMenuSelected].setFillColor(Color::White);
		m_MainMenuSelected++;
		m_Menu[m_MainMenuSelected].setFillColor(Color::Red);
	}

	void CMainMenuPhase::OnLeave()
	{}
}