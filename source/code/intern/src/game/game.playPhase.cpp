#include "game.playPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphics/gfx.playPhase.h"

namespace Game
{
	int PlayPhase::InternOnEnter()
	{
		std::cout << "PlayPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::PlayPhase::GetInstance().OnEnter();
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

			return Type::UNLOAD_MAP;
		}

		return Type::PLAY;
	}

	int PlayPhase::InternOnLeave()
	{
		std::cout << "PlayPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}
}