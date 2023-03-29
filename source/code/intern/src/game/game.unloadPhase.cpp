#include "game.unloadPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphics/gfx.unloadPhase.h"
#include "../gui/gui.unloadPhase.h"
#include "../logic/logic.unloadPhase.h"

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
		std::cout << "UnloadPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;

		counter++;


		if (counter > 4)
		{
			counter = 0;
			Gfx::CUnloadPhase::GetInstance().OnRun();
			Gui::CUnloadPhase::GetInstance().OnRun();
			Logic::CUnloadPhase::GetInstance().OnRun();

			return Type::SHUTDOWN;
		}

		return Type::UNLOAD_MAP;
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