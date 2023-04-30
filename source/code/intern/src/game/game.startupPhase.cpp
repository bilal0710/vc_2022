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
		Data::CStartupPhase::GetInstance().OnEnter();
		Gfx::CStartupPhase::GetInstance().OnEnter();
		Gui::CStartupPhase::GetInstance().OnEnter();
		Logic::CStartupPhase::GetInstance().OnEnter();
		return 0;
	}

	int CStartupPhase::InternOnRun()
	{
		
			tinyxml2::XMLDocument* pMetaEntityDoc =  new tinyxml2::XMLDocument;
			pMetaEntityDoc->LoadFile("../bin/meta_entity.xml");

			Data::CStartupPhase::GetInstance().OnRun(*pMetaEntityDoc);
			Gfx::CStartupPhase::GetInstance().OnRun(*pMetaEntityDoc);
			Gui::CStartupPhase::GetInstance().OnRun();
			Logic::CStartupPhase::GetInstance().OnRun();
			return Type::MAIN_MENU;
	}

	int CStartupPhase::InternOnLeave()
	{
		Data::CStartupPhase:: GetInstance().OnLeave();
		Gfx::CStartupPhase::  GetInstance().OnLeave();
		Gui::CStartupPhase::  GetInstance().OnLeave();
		Logic::CStartupPhase::GetInstance().OnLeave();

		return 0;
	}

}
