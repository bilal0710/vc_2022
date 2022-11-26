#include "game.unloadPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Game
{
	int UnloadPhase::InternOnEnter()
	{
		std::cout << "UnloadPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
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

			return Type::SHUTDOWN;
		}

		return Type::UNLOAD_MAP;
	}

	int UnloadPhase::InternOnLeave()
	{
		std::cout << "UnloadPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}
}