#include "gfx.loadPhase.h"
#include <iostream>
#include"game/game.appWindow.h"
#include"game/game.counter.h"
#include <string>


using namespace std;

namespace Gfx
{
	void CLoadPhase::OnEnter()
	{
		Game::CCounter& CGameCounter = Game::CCounter::GetInstance();
		int GameCounter = CGameCounter.GetGameCounter();
		

		if (!m_Font.loadFromFile("3Dumb.ttf")) {
			cout << "No font is loaded!" << endl;
		}

		m_Background.setSize(Vector2f(120, 100));
		m_Background.setPosition(700, 380);
		m_BackgroundTexture.loadFromFile("mario.png");
		m_Background.setTexture(&m_BackgroundTexture);

		m_Menu.setFont(m_Font);
		m_Menu.setCharacterSize(70);
		m_Menu.setString("X      " + to_string(GameCounter));
		m_Menu.setPosition(950, 380);
		m_Menu.setFillColor(Color::White);


	}

	void CLoadPhase::OnRun()
	{

		Game::CApplicationWindow& rAppWindow = Game::CApplicationWindow::GetInstance();
		while (m_Timer < 1200) {
			auto& AppWindowSize = rAppWindow.m_AppWindow.getView().getSize();

			sf::View view(sf::FloatRect(0.0f, 0.0f, AppWindowSize.x, AppWindowSize.y));
			rAppWindow.m_AppWindow.setView(view);
			rAppWindow.m_AppWindow.clear(sf::Color::Black);
			rAppWindow.m_AppWindow.draw(m_Background);
			rAppWindow.m_AppWindow.draw(m_Menu);
			rAppWindow.m_AppWindow.display();
			m_Timer++;
		}
		m_Timer = 0;
	}

	void CLoadPhase::OnLeave()
	{}
}