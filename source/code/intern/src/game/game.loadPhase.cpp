#include "game.loadPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphics/gfx.loadPhase.h"
#include "../gui/gui.loadPhase.h"
#include "../logic/logic.loadPhase.h"
#include "../data/data.loadPhase.h"
#include <tinyxml2.h>

using namespace tinyxml2;


namespace Game
{
	int CLoadPhase::InternOnEnter()
	{
		std::cout << "LoadPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;

		Data::CLoadPhase::GetInstance().OnEnter();
		Gfx::CLoadPhase::GetInstance().OnEnter();
		Gui::CLoadPhase::GetInstance().OnEnter();
		Logic::CLoadPhase::GetInstance().OnEnter();
		return 0;
	}

	int CLoadPhase::InternOnRun()
	{
		std::cout << "LoadPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;

		counter++;


		if (counter > 4)
		{

			XMLDocument* doc = new XMLDocument;;
			doc -> LoadFile("../bin/map.xml");

			Data::CLoadPhase::GetInstance().OnRun(*doc);
			Gfx::CLoadPhase::GetInstance().  OnRun();
			Gui::CLoadPhase::GetInstance().  OnRun();
			Logic::CLoadPhase::GetInstance().OnRun();
			counter = 0;

			return Type::PLAY;
		}

		return Type::LOAD_MAP;
	}

	int CLoadPhase::InternOnLeave()
	{
		std::cout << "LoadPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		Data::CLoadPhase::GetInstance().OnLeave();
		Gfx::CLoadPhase::GetInstance().  OnLeave();
		Gui::CLoadPhase::GetInstance().  OnLeave();
		Logic::CLoadPhase::GetInstance().OnLeave();
		return 0;
	}
}