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

		m_Title.setFont(m_Font);
		m_Title.setFillColor(Color::Red);
		m_Title.setCharacterSize(70);
		m_Title.setString("Super Mario");
		m_Title.setPosition(780, 150);

		for (int i = 0; i < Max_Main_Menu; i++) {
			m_Menu[i].setFont(m_Font);
			m_Menu[i].setCharacterSize(70);

			if (i == 0) {
				m_Menu[i].setString("Play");
				m_Menu[i].setPosition(900, 400);
				m_Menu[i].setFillColor(Color::Blue);
				continue;
			}

			m_Menu[i].setString("Exit");
			m_Menu[i].setPosition(900, 480);
			m_Menu[i].setFillColor(Color::White);
		}
		m_MainMenuSelected = 0;

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
					if (sf::Keyboard::isKeyPressed(Keyboard::Up)) {
						Move();
						DrawMainMenu(rStartupPhase.m_AppWindow);
						rStartupPhase.m_AppWindow.display();
						break;

					}
					if (sf::Keyboard::isKeyPressed(Keyboard::Down)) {
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

		r_AppWindow.draw(m_Title);

		for (int i = 0; i < Max_Main_Menu; i++) {

			r_AppWindow.draw(m_Menu[i]);
		}

	}
	void CMainMenuPhase::Move()
	{
		if (m_MainMenuSelected > 0) {

			m_Menu[m_MainMenuSelected].setFillColor(Color::White);
			m_MainMenuSelected--;
			m_Menu[m_MainMenuSelected].setFillColor(Color::Blue);
			return;
		}
		m_Menu[m_MainMenuSelected].setFillColor(Color::White);
		m_MainMenuSelected++;
		m_Menu[m_MainMenuSelected].setFillColor(Color::Blue);
	}

	void CMainMenuPhase::OnLeave()
	{}
}