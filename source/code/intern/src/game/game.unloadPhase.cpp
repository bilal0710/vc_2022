#include "game.unloadPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphics/gfx.unloadPhase.h"
#include "../gui/gui.unloadPhase.h"
#include "../logic/logic.unloadPhase.h"
//#include <data/data.eventSystem.h>


namespace Game
{
	int CUnloadPhase::InternOnEnter()
	{
		std::cout << "UnloadPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;	

		Gfx::CUnloadPhase::GetInstance().OnEnter();
		Gui::CUnloadPhase::GetInstance().OnEnter();
		Logic::CUnloadPhase::GetInstance().OnEnter();
		return 0;
	}

	int CUnloadPhase::InternOnRun()
	{
		std::cout << "UnloadPhase::InternOnRun " << std::endl;
		std::cout << "------------------------" << std::endl;

		Gfx::CUnloadPhase::GetInstance().OnRun();
		Gui::CUnloadPhase::GetInstance().OnRun();
		Logic::CUnloadPhase::GetInstance().OnRun();


		if (m_ReloadGame) {
			return Type::MAIN_MENU;
		}

		return Type::SHUTDOWN;


	}

	void CUnloadPhase::ReloadGame(Data::CEvent& _Event)
	{
		CUnloadPhase UnloadPhaseClass;
		UnloadPhaseClass.GetInstance().SetReloadGame(true);
	}

	void CUnloadPhase::SetReloadGame(bool _Reload) {
		m_ReloadGame = _Reload;
	}

	int CUnloadPhase::InternOnLeave()
	{
		std::cout << "UnloadPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::CUnloadPhase::GetInstance().OnLeave();
		Gui::CUnloadPhase::GetInstance().OnLeave();
		Logic::CUnloadPhase::GetInstance().OnLeave();
		return 0;
	}
}