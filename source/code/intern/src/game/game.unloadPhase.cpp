#include "game.unloadPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphics/gfx.unloadPhase.h"
#include "../gui/gui.unloadPhase.h"
#include "../logic/logic.unloadPhase.h"

namespace Game
{
	int UnloadPhase::InternOnEnter()
	{
		std::cout << "UnloadPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::UnloadPhase::GetInstance().OnEnter();
		Gui::UnloadPhase::GetInstance().OnEnter();
		Logic::UnloadPhase::GetInstance().OnEnter();
		return 0;
	}

	int UnloadPhase::InternOnRun()
	{
		std::cout << "UnloadPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;

		counter++;


		if (counter > 4)
		{
			counter = 0;
			Gfx::UnloadPhase::GetInstance().OnRun();
			Gui::UnloadPhase::GetInstance().OnRun();
			Logic::UnloadPhase::GetInstance().OnRun();

			return Type::SHUTDOWN;
		}

		return Type::UNLOAD_MAP;
	}

	int UnloadPhase::InternOnLeave()
	{
		std::cout << "UnloadPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::UnloadPhase::GetInstance().OnLeave();
		Gui::UnloadPhase::GetInstance().OnLeave();
		Logic::UnloadPhase::GetInstance().OnLeave();
		return 0;
	}
}