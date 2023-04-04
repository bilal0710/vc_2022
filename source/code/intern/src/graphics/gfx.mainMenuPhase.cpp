#include "gfx.mainMenuPhase.h"
#include "gfx.startupPhase.h"
#include <iostream>

#include <data/data.eventSystem.h>

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
			m_Menu[i].setFillColor(Color::White);
			m_Menu[i].setCharacterSize(70);

			if (i == 0) {
				m_Menu[0].setString("Super Mario");
				m_Menu[0].setPosition(780, 150);
				continue;
			}
			if (i == 1) {
				m_Menu[1].setString("Play");
				m_Menu[1].setPosition(900, 400);
				continue;
			}
			m_Menu[2].setString("Exit");
			m_Menu[2].setPosition(900, 520);
		}
		m_MainMenuSelected = 0;

	}


	static void EventCallBack(Data::CEvent& data) {
		std::cout << "ABC" << std::endl;

	}

	void CMainMenuPhase::OnRun()
	{
		std::cout << "Gfx::MainMenuPhase::OnRun" << std::endl;
		CStartupPhase& rStartupPhase = CStartupPhase::GetInstance();
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();

		DrawMainMenu(rStartupPhase.m_AppWindow);
		rStartupPhase.m_AppWindow.display();

		while (rStartupPhase.m_AppWindow.isOpen())
		{
			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event Event;
			while (rStartupPhase.m_AppWindow.pollEvent(Event))
			{

				if (Event.type == sf::Event::KeyPressed) {


					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{
						rEventSystem.Register(Data::CEvent::BTypeID(0), &EventCallBack);
						rEventSystem.FireEvent(0);
						return;
					}
				}

				// "close requested" event: we close the window
				if (Event.type == sf::Event::Closed)
				{

					rStartupPhase.m_AppWindow.close();
				}
				if (Event.type == sf::Event::Resized)
				{
					// update the view to the new size of the windowl
					sf::FloatRect VisibleArea(0.f, 0.f, (float)Event.size.width, (float)Event.size.height);
					rStartupPhase.m_AppWindow.setView(sf::View(VisibleArea));
				}

			}

		}

	}

	void CMainMenuPhase::OnLeave()
	{}
	void CMainMenuPhase::DrawMainMenu(RenderWindow& r_AppWindow)
	{
		for (int i = 0; i < Max_Main_Menu; i++) {
			r_AppWindow.draw(m_Menu[i]);
		}

	}
	void CMainMenuPhase::MoveUp()
	{
		if (m_MainMenuSelected - 1 > 0) {

			m_Menu[m_MainMenuSelected].setFillColor(Color::White);
			m_MainMenuSelected--;
			if (m_MainMenuSelected == 0) {
				m_MainMenuSelected = 2;
			}
			m_Menu[m_MainMenuSelected].setFillColor(Color::Blue);
		}
	}
	void CMainMenuPhase::MoveDown()
	{
		if (m_MainMenuSelected +1 < Max_Main_Menu) {

			m_Menu[m_MainMenuSelected].setFillColor(Color::White);
			m_MainMenuSelected++;
			if (m_MainMenuSelected == 2) {
				m_MainMenuSelected = 0;
			}
			m_Menu[m_MainMenuSelected].setFillColor(Color::Blue);
		}
	}

}