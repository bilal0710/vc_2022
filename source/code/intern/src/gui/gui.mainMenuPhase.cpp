#include "gui.mainMenuPhase.h"
#include "game/game.appWindow.h"
#include "graphics/gfx.mainMenuPhase.h"
#include <data/data.eventSystem.h>

#include <iostream>


using namespace Gfx;
using namespace std;
using namespace sf;

namespace Gui
{
	void CMainMenuPhase::OnEnter()
	{}


	void CMainMenuPhase::OnRun()
	{
		cout << "Gui::MainMenuPhase::OnRun" << endl;


		Game::CApplicationWindow& rAppWindow = Game::CApplicationWindow::GetInstance();
		Gfx::CMainMenuPhase& rMainMenuPhase = Gfx::CMainMenuPhase::GetInstance();
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();


		while (rAppWindow.m_AppWindow.isOpen())
		{
			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event Event;

			while (rAppWindow.m_AppWindow.pollEvent(Event))
			{

				if (Event.type == sf::Event::KeyPressed) {

					if (sf::Keyboard::isKeyPressed(Keyboard::Enter))
					{
						cout << "Enter" << endl;
						rEventSystem.Register(Data::CEvent::BTypeID(0), &rMainMenuPhase.EventListener);
						rEventSystem.FireEvent(0);
						return;
					}
					if (sf::Keyboard::isKeyPressed(Keyboard::Up) || sf::Keyboard::isKeyPressed(Keyboard::Down)) {
						rMainMenuPhase.Move();
						rMainMenuPhase.DrawMainMenu(rAppWindow.m_AppWindow);
						rAppWindow.m_AppWindow.display();
						break;
					}

				}

				// "close requested" event: we close the window
				if (Event.type == sf::Event::Closed)
				{
					rAppWindow.m_AppWindow.close();
				}
				if (Event.type == sf::Event::Resized)
				{
					// update the view to the new size of the windowl
					FloatRect VisibleArea(0.f, 0.f, (float)Event.size.width, (float)Event.size.height);
					rAppWindow.m_AppWindow.setView(sf::View(VisibleArea));
				}

			}

		}
	}

	void CMainMenuPhase::OnLeave()
	{}
}