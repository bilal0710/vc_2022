#include "game.startupPhase.h"
#include <SFML/Graphics.hpp>
#include <tinyxml2.h>

#include <iostream>

#include "../data/data.startupPhase.h"
#include "../graphics/gfx.startupPhase.h"
#include "../gui/gui.startupPhase.h"
#include "../logic/logic.startupPhase.h"


namespace Game
{
	int StartupPhase::InternOnEnter()
	{
		std::cout << "Game::StartupPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		Data::StartupPhase::GetInstance().OnEnter();
		Gfx::StartupPhase::GetInstance().OnEnter();
		Gui::StartupPhase::GetInstance().OnEnter();
		Logic::StartupPhase::GetInstance().OnEnter();
		return 0;
	}

	int StartupPhase::InternOnRun()
	{
		std::cout << "Game::StartupPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;
		counter++;
		
		if (counter > 4)
		{
			tinyxml2::XMLDocument* doc =  new tinyxml2::XMLDocument;
			doc->LoadFile("../code/intern/src/data/meta_entity.xml");

			Data::StartupPhase::GetInstance().OnRun(*doc);
			Gfx::StartupPhase::GetInstance().OnRun(*doc);
			Gui::StartupPhase::GetInstance().OnRun();
			Logic::StartupPhase::GetInstance().OnRun();

			counter = 0;
			

			return Type::MAIN_MENU;
		}

		return Type::STARTUP;
	}

	int StartupPhase::InternOnLeave()
	{
		Data::StartupPhase:: GetInstance().OnLeave();
		Gfx::StartupPhase::  GetInstance().OnLeave();
		Gui::StartupPhase::  GetInstance().OnLeave();
		Logic::StartupPhase::GetInstance().OnLeave();

		std::cout << "StartupPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}

}
