#include "game.playPhase.h"
#include <iostream>
#include "../graphics/gfx.playPhase.h"
#include "../gui/gui.playPhase.h"
#include "../logic/logic.playPhase.h"
#include "core/core_time.h"
#include "data/data.entitySystem.h"

namespace Game
{
	int CPlayPhase::InternOnEnter()
	{
		std::cout << "PlayPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;

		Core::Time::Reset();
		m_EndGame = false;

		Gfx::CPlayPhase::GetInstance().OnEnter();
		Gui::CPlayPhase::GetInstance().OnEnter();
		Logic::CPlayPhase::GetInstance().OnEnter();

		return 0;
	}

	int CPlayPhase::InternOnRun()
	{
		Core::Time::OnFrame();

		//std::cout << "PlayPhase::InternOnRun " << std::endl;
		//std::cout << "------------------------" << std::endl;

		Gfx::CPlayPhase::GetInstance().OnRun();
		Gui::CPlayPhase::GetInstance().OnRun();
		//Logic::CPlayPhase::GetInstance().OnRun();

		if (m_EndGame)
		{
			return Type::UNLOAD_MAP;
		}

		return Type::PLAY;
	}

	int CPlayPhase::InternOnLeave()
	{
		std::cout << "PlayPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::CPlayPhase::GetInstance().OnLeave();
		Gui::CPlayPhase::GetInstance().OnLeave();
		return 0;
	}
}