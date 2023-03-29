
#include <iostream>
#include <cassert>
#include "game.phase.h"
#include "game.application.h"
#include "game.startupPhase.h"
#include "game.mainMenuPhase.h"
#include "game.loadPhase.h"
#include "game.playPhase.h"
#include "game.unloadPhase.h"
#include "game.shutdownPhase.h"

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


		for (;;)
		{
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
		std::cout << "------------------------" << std::endl;

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