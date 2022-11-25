
#include <iostream>
#include <cassert>
#include "game.phase.h"
#include "game.application.h"
#include "game.startupPhase.h"

namespace Game
{
	Application::Application()
		: m_IndexOfCurrentPhase(Phase::Undefined),
		m_pPhases{
		&StartupPhase::GetInstance(),
		/* &MainMenuPhase::GetInstance(),
		 &LoadPhase::GetInstance(),
		 &PlayPhase::GetInstance(),
		 &UnloadPhase::GetInstance(),
		 &ShutdownPhase::GetInstance()*/
		}
	{

	}

	void Application::Initialize() {
		std::cout << "Application -> Initialize" << std::endl;

		m_IndexOfCurrentPhase = Phase::STARTUP;
		m_pPhases[m_IndexOfCurrentPhase]->OnEnter();

	}

	void Application::Run()
	{
		std::cout << "Application -> Run" << std::endl;

		if (RunPhase() == false)
		{
			return;
		}
	}

	void Application::Finalize()
	{
		std::cout << "Application -> Finalize" << std::endl;
	}

	bool Application::RunPhase()
	{
		Phase* pCurrentPhase = m_pPhases[m_IndexOfCurrentPhase];
		assert(pCurrentPhase != nullptr);

		int indexOfNextPhase = pCurrentPhase->OnRun();

		if (indexOfNextPhase != m_IndexOfCurrentPhase)
		{
			pCurrentPhase->OnLeave();

			if (m_IndexOfCurrentPhase == Phase::SHUTDOWN)
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
	Game::Application& application = Game::Application::GetInstance();
	application.Initialize();

	application.Run();

	application.Finalize();

	return 0;
}