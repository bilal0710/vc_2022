#include "gfx.mainMenuPhase.h"
#include <data/data.eventSystem.h>
#include"game/game.appWindow.h"
#include <iostream>


using namespace std;


namespace Gfx
{
	void CMainMenuPhase::OnEnter()
	{
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();

		rEventSystem.Register(Data::CEvent::BTypeID(1), &CMainMenuPhase::EventListener);

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

	int CMainMenuPhase::GetMainMenuSelected() {
		return m_MainMenuSelected;
	}

	void CMainMenuPhase::EventListener(Data::CEvent& data)
	{
		 CMainMenuPhase::GetInstance().Move();
	}

	void CMainMenuPhase::OnRun()
	{
		Game::CApplicationWindow& rAppWindow = Game::CApplicationWindow::GetInstance();

		DrawMainMenu(rAppWindow.m_AppWindow);
		rAppWindow.m_AppWindow.display();

	}


	void CMainMenuPhase::DrawMainMenu(RenderWindow& _rAppWindow)
	{
		auto& AppWindowSize = _rAppWindow.getView().getSize();

		sf::View view(sf::FloatRect(0.0f, 0.0f, AppWindowSize.x, AppWindowSize.y));
		_rAppWindow.setView(view);
		_rAppWindow.clear(sf::Color::Black);
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
	{
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();

		rEventSystem.Unregister(Data::CEvent::BTypeID(1), &CMainMenuPhase::EventListener);
	}
}