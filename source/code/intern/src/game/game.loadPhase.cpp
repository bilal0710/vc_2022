#include "game.loadPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphics/gfx.loadPhase.h"
#include "../gui/gui.loadPhase.h"
#include "../logic/logic.loadPhase.h"

namespace Game
{
	int LoadPhase::InternOnEnter()
	{
		std::cout << "LoadPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::LoadPhase::GetInstance().OnEnter();
		Gui::LoadPhase::GetInstance().OnEnter();
		Logic::LoadPhase::GetInstance().OnEnter();
		return 0;
	}

	int LoadPhase::InternOnRun()
	{
		std::cout << "LoadPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;

		counter++;


		if (counter > 4)
		{
			Gfx::LoadPhase::GetInstance().  OnRun();
			Gui::LoadPhase::GetInstance().  OnRun();
			Logic::LoadPhase::GetInstance().OnRun();
			counter = 0;

			return Type::PLAY;
		}

		return Type::LOAD_MAP;
	}

	int LoadPhase::InternOnLeave()
	{
		std::cout << "LoadPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::LoadPhase::GetInstance().  OnLeave();
		Gui::LoadPhase::GetInstance().  OnLeave();
		Logic::LoadPhase::GetInstance().OnLeave();
		return 0;
	}
}