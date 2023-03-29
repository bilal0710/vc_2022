#include "game.mainMenuPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphics/gfx.mainMenuPhase.h"
#include "../gui/gui.mainMenuPhase.h"

namespace Game
{
	int CMainMenuPhase::InternOnEnter()
	{
		std::cout << "MainMenuPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::CMainMenuPhase::GetInstance().OnEnter();
		Gui::CMainMenuPhase::GetInstance().OnEnter();
		return 0;

	}

	int CMainMenuPhase::InternOnRun()
	{
		std::cout << "MainMenuPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::CMainMenuPhase::GetInstance().OnEnter();
		Gui::CMainMenuPhase::GetInstance().OnEnter();
		counter++;


		if (counter > 4)
		{
			counter = 0;
			return Type::LOAD_MAP;
		}

		return Type::MAIN_MENU;
	}

	int CMainMenuPhase::InternOnLeave()
	{
		std::cout << "MainMenuPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::CMainMenuPhase::GetInstance().OnEnter();
		Gui::CMainMenuPhase::GetInstance().OnEnter();
		return 0;
	}
}