#include "game.playPhase.h"
#include <iostream>
#include "../graphics/gfx.playPhase.h"
#include "../gui/gui.playPhase.h"
#include "../logic/logic.playPhase.h"
#include "core/core_time.h"
#include "data/data.entitySystem.h"
#include <data/data.eventSystem.h>
namespace Game
{
	int CPlayPhase::InternOnEnter()
	{
		std::cout << "PlayPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;

		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();

		m_EndGame = false;

		CPlayPhase PlayPhaseClass;
		rEventSystem.Register(Data::CEvent::BTypeID(2), &PlayPhaseClass.FinishGame);

		Gfx::CPlayPhase::GetInstance().OnEnter();
		Gui::CPlayPhase::GetInstance().OnEnter();
		Logic::CPlayPhase::GetInstance().OnEnter();
		Core::Time::Reset();

		return 0;
	}

	int CPlayPhase::InternOnRun()
	{
		Core::Time::OnFrame();

		Gfx::CPlayPhase::GetInstance().OnRun();
		Gui::CPlayPhase::GetInstance().OnRun();
		Logic::CPlayPhase::GetInstance().OnRun();

		if (m_EndGame)
		{
			return Type::MAIN_MENU;
		}

		return Type::PLAY;
	}

	void CPlayPhase::FinishGame(Data::CEvent& _Event)
	{
		CPlayPhase PlayPhaseClass;
		PlayPhaseClass.GetInstance().SetEndGame(true);
	}

	void CPlayPhase::SetEndGame(bool _Exit) {
		m_EndGame = _Exit;
	}

	int CPlayPhase::InternOnLeave()
	{
		std::cout << "PlayPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		Gfx::CPlayPhase::GetInstance().OnLeave();
		Gui::CPlayPhase::GetInstance().OnLeave();
		Logic::CPlayPhase::GetInstance().OnLeave();
		return 0;
	}
}