#include "game.shutdownPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Game
{
	int ShutdownPhase::InternOnEnter()
	{
		std::cout << "ShutdownPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}

	int ShutdownPhase::InternOnRun()
	{
		std::cout << "ShutdownPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;

		counter++;


		if (counter > 4)
		{
			counter = 0;

			return Type::NumberOfTypes;
		}

		return Type::SHUTDOWN;
	}

	int ShutdownPhase::InternOnLeave()
	{
		std::cout << "ShutdownPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}
}