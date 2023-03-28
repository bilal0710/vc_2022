#include "game.playPhase.h"
#include <iostream>
#include "../graphics/gfx.playPhase.h"
#include "../gui/gui.playPhase.h"

namespace Game
{
	int PlayPhase::InternOnEnter()
	{
		std::cout << "PlayPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::PlayPhase::GetInstance().OnEnter();
		Gui::PlayPhase::GetInstance().OnEnter();
		return 0;
	}

	int PlayPhase::InternOnRun()
	{
		std::cout << "PlayPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;

		counter++;


		if (counter > 4)
		{
			counter = 0;
			Gfx::PlayPhase::GetInstance().OnRun();
			Gui::PlayPhase::GetInstance().OnRun();

			return Type::UNLOAD_MAP;
		}

		return Type::PLAY;
	}

	int PlayPhase::InternOnLeave()
	{
		std::cout << "PlayPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::PlayPhase::GetInstance().OnLeave();
		Gui::PlayPhase::GetInstance().OnLeave();
		return 0;
	}
}