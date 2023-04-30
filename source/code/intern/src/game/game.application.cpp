
#include <cassert>
#include "game.phase.h"
#include "game.application.h"
#include "game.startupPhase.h"
#include "game.mainMenuPhase.h"
#include "game.loadPhase.h"
#include "game.playPhase.h"
#include "game.unloadPhase.h"
#include "game.shutdownPhase.h"

#include"game/game.appWindow.h"

#include"game/game.appWindow.h"
#include <graphics/gfx.playPhase.h>
#include <data/data.playerSystem.h>
#include <data/data.eventSystem.h>
#include <data/data.event.h>
#include <logic/logic.playPhase.h>
#include <logic/logic.inputType.h>
#include <logic/logic.inputSystem.h>

#include <iostream>


using namespace sf;
using namespace std;

namespace Game
{
	CApplication::CApplication()
		: m_IndexOfCurrentPhase(CPhase::Undefined),
		m_pPhases{
		 &CStartupPhase::GetInstance(),
		 &CMainMenuPhase::GetInstance(),
		 &CLoadPhase::GetInstance(),
		 &CPlayPhase::GetInstance(),
		 &CUnloadPhase::GetInstance(),
		 &CShutdownPhase::GetInstance()
		}
	{

	}

	void CApplication::Initialize() {
		std::cout << "Application -> Initialize" << std::endl;
		std::cout << "------------------------" << std::endl;

		m_IndexOfCurrentPhase = CPhase::STARTUP;
		m_pPhases[m_IndexOfCurrentPhase]->OnEnter();

	}

	void CApplication::Run()
	{
		std::cout << "Application -> Run" << std::endl;
		std::cout << "------------------------" << std::endl;

		Game::CApplicationWindow& rAppWindow = Game::CApplicationWindow::GetInstance();
		//Logic::CInputSystem& rLogicInputSystem = Logic::CInputSystem::GetInstance();
		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();



		for (;;)
		{
			if (rAppWindow.m_AppWindow.isOpen() == false)
			{
				break;
			}


			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event Event;


			while (rAppWindow.m_AppWindow.pollEvent(Event))
			{

				// "close requested" event: we close the window
				if (Event.type == sf::Event::Closed)
				{
					rAppWindow.m_AppWindow.close();
				}
				if (Event.type == sf::Event::Resized)
				{
					// update the view to the new size of the windowl
					sf::FloatRect VisibleArea(0.f, 0.f, (float)Event.size.width, (float)Event.size.height);
					rAppWindow.m_AppWindow.setView(sf::View(VisibleArea));
				}

				if (Event.type == sf::Event::KeyPressed)
				{
					rEventSystem.FireEvent(4, Event.key.code);
				}
			}

			if (RunPhase() == false)
			{
				std::cout << "Application -> Run -> if" << std::endl;
				return;
			}
		}
	}

	void CApplication::Finalize()
	{
		std::cout << "Application -> Finalize" << std::endl;
	}

	bool CApplication::RunPhase()
	{
		//std::cout << "------------------------" << std::endl;

		CPhase* pCurrentPhase = m_pPhases[m_IndexOfCurrentPhase];
		assert(pCurrentPhase != nullptr);

		int indexOfNextPhase = pCurrentPhase->OnRun();

		if (indexOfNextPhase != m_IndexOfCurrentPhase)
		{
			pCurrentPhase->OnLeave();

			if (m_IndexOfCurrentPhase == CPhase::SHUTDOWN)
			{
				return false;
			}

			m_IndexOfCurrentPhase = indexOfNextPhase;

			pCurrentPhase = m_pPhases[m_IndexOfCurrentPhase];

			assert(pCurrentPhase != nullptr);

			pCurrentPhase->OnEnter();
		}

		return true;
	}
}



int main()
{
	Game::CApplication& application = Game::CApplication::GetInstance();
	application.Initialize();

	application.Run();

	application.Finalize();

	return 0;
}