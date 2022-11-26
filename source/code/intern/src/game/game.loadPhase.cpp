#include "game.loadPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Game
{
	int LoadPhase::InternOnEnter()
	{
		std::cout << "LoadPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}

	int LoadPhase::InternOnRun()
	{
		std::cout << "LoadPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;

		counter++;


		if (counter > 4)
		{
			counter = 0;

			return Type::PLAY;
		}

		return Type::LOAD_MAP;
	}

	int LoadPhase::InternOnLeave()
	{
		std::cout << "LoadPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}
}