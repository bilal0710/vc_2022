#include "gui.mainMenuPhase.h"
#include "graphics/gfx.startupPhase.h"
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


		CStartupPhase& rStartupPhase = CStartupPhase::GetInstance();
		Gfx::CMainMenuPhase& rMainMenuPhase = Gfx::CMainMenuPhase::GetInstance();
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();


		while (rStartupPhase.m_AppWindow.isOpen())
		{
			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event Event;

			while (rStartupPhase.m_AppWindow.pollEvent(Event))
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
						rMainMenuPhase.DrawMainMenu(rStartupPhase.m_AppWindow);
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

	void CMainMenuPhase::OnLeave()
	{}
}