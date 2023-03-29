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
	int CStartupPhase::InternOnEnter()
	{
		std::cout << "Game::StartupPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		Data::CStartupPhase::GetInstance().OnEnter();
		Gfx::CStartupPhase::GetInstance().OnEnter();
		Gui::CStartupPhase::GetInstance().OnEnter();
		Logic::CStartupPhase::GetInstance().OnEnter();
		return 0;
	}

	int CStartupPhase::InternOnRun()
	{
		std::cout << "Game::StartupPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;
		counter++;
		
		if (counter > 4)
		{
			tinyxml2::XMLDocument* doc =  new tinyxml2::XMLDocument;
			doc->LoadFile("../bin/meta_entity.xml");

			Data::CStartupPhase::GetInstance().OnRun(*doc);
			Gfx::CStartupPhase::GetInstance().OnRun(*doc);
			Gui::CStartupPhase::GetInstance().OnRun();
			Logic::CStartupPhase::GetInstance().OnRun();

			counter = 0;
			

			return Type::MAIN_MENU;
		}

		return Type::STARTUP;
	}

	int CStartupPhase::InternOnLeave()
	{
		Data::CStartupPhase:: GetInstance().OnLeave();
		Gfx::CStartupPhase::  GetInstance().OnLeave();
		Gui::CStartupPhase::  GetInstance().OnLeave();
		Logic::CStartupPhase::GetInstance().OnLeave();

		std::cout << "StartupPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}

}
