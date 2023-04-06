#include "gfx.mainMenuPhase.h"
#include "gfx.startupPhase.h"
#include <iostream>

#include <data/data.eventSystem.h>
#include <string>     // std::string, std::to_string
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


	static void EventCallBack(Data::CEvent& data) {
		std::cout << "ABC" << std::endl;

	}

	void CMainMenuPhase::OnRun()
	{
		cout << "Gfx::MainMenuPhase::OnRun" << endl;
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

					if (sf::Keyboard::isKeyPressed(Keyboard::Enter))
					{
						rEventSystem.Register(Data::CEvent::BTypeID(0), &EventCallBack);
						rEventSystem.FireEvent(0);
						if (m_MainMenuSelected == 0) {
							return;
						}
						if (m_MainMenuSelected == 1) {
							rStartupPhase.m_AppWindow.close();
						}
					}
					if (sf::Keyboard::isKeyPressed(Keyboard::Up) || sf::Keyboard::isKeyPressed(Keyboard::Down)) {
						Move();
						DrawMainMenu(rStartupPhase.m_AppWindow);
						rStartupPhase.m_AppWindow.display();
						break;

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
					FloatRect VisibleArea(0.f, 0.f, (float)Event.size.width, (float)Event.size.height);
					rStartupPhase.m_AppWindow.setView(sf::View(VisibleArea));
				}

			}

		}

	}


	void CMainMenuPhase::DrawMainMenu(RenderWindow& r_AppWindow)
	{

		r_AppWindow.draw(m_Background);

		for (int i = 0; i < Max_Main_Menu; i++) {

			r_AppWindow.draw(m_Menu[i]);
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