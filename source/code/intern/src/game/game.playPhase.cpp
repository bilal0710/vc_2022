#include "game.playPhase.h"
#include <iostream>
#include "../graphics/gfx.playPhase.h"
#include "../gui/gui.playPhase.h"
#include "../logic/logic.playPhase.h"
#include "core/core_time.h"
#include "data/data.entitySystem.h"
#include <data/data.eventSystem.h>
#include "game.unloadPhase.h"


namespace Game
{
	int CPlayPhase::InternOnEnter()
	{

		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();

		m_EndGame = false;
		rEventSystem.Register(Data::CEvent::BTypeID(2), &CPlayPhase::FinishGame);
		rEventSystem.Register(Data::CEvent::BTypeID(3), &CUnloadPhase::GetInstance().ReloadGame);

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
			return Type::UNLOAD_MAP;
		}

		return Type::PLAY;
	}

	void CPlayPhase::FinishGame(Data::CEvent& _Event)
	{
		CPlayPhase::GetInstance().SetEndGame(true);
	}

	void CPlayPhase::SetEndGame(bool _Exit) {
		m_EndGame = _Exit;
	}

	int CPlayPhase::InternOnLeave()
	{

		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();
		rEventSystem.Unregister(Data::CEvent::BTypeID(2), &CPlayPhase::FinishGame);
		rEventSystem.Unregister(Data::CEvent::BTypeID(3), &CUnloadPhase::GetInstance().ReloadGame);

		Gfx::CPlayPhase::GetInstance().OnLeave();
		Gui::CPlayPhase::GetInstance().OnLeave();
		Logic::CPlayPhase::GetInstance().OnLeave();
		return 0;
	}
}