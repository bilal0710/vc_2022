#include "game.mainMenuPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Game
{
	int MainMenuPhase::InternOnEnter()
	{
		std::cout << "MainMenuPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}

	int MainMenuPhase::InternOnRun()
	{
		std::cout << "MainMenuPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;

		counter++;


		if (counter > 4)
		{
			counter = 0;
			return Type::LOAD_MAP;
		}

		return Type::MAIN_MENU;
	}

	int MainMenuPhase::InternOnLeave()
	{
		std::cout << "MainMenuPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}
}