#include "game.mainMenuPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphics/gfx.mainMenuPhase.h"
#include "../gui/gui.mainMenuPhase.h"

namespace Game
{
	int CMainMenuPhase::InternOnEnter()
	{
		std::cout << "Game::MainMenuPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::CMainMenuPhase::GetInstance().OnEnter();
		Gui::CMainMenuPhase::GetInstance().OnEnter();
		return 0;

	}

	int CMainMenuPhase::InternOnRun()
	{
		std::cout << "Game::MainMenuPhase::InternOnRun " << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::CMainMenuPhase::GetInstance().OnRun();
		Gui::CMainMenuPhase::GetInstance().OnRun();


		return Type::LOAD_MAP;

	}

	int CMainMenuPhase::InternOnLeave()
	{
		std::cout << "Game::MainMenuPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::CMainMenuPhase::GetInstance().OnLeave();
		Gui::CMainMenuPhase::GetInstance().OnLeave();
		return 0;
	}
}