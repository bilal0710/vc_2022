#include "game.startupPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../data/data.startupPhase.h"
#include "../graphics/gfx.startupPhase.h"


namespace Game
{
	int StartupPhase::InternOnEnter()
	{
		std::cout << "Game::StartupPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}

	int StartupPhase::InternOnRun()
	{
		std::cout << "Game::StartupPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;
		counter++;
		

		if (counter > 4)
		{
			counter = 0;
			Data::StartupPhase::GetInstance().OnEnter();
			Gfx::StartupPhase::GetInstance().OnEnter();

			return Type::MAIN_MENU;
		}

		return Type::STARTUP;
	}

	int StartupPhase::InternOnLeave()
	{
		std::cout << "StartupPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}

}
