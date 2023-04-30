#include "game.mainMenuPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphics/gfx.mainMenuPhase.h"
#include "../gui/gui.mainMenuPhase.h"
#include"game/game.appWindow.h"
#include <data/data.eventSystem.h>
#include"game/game.counter.h"


namespace Game
{
	int CMainMenuPhase::InternOnEnter()
	{

		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();

		rEventSystem.Register(Data::CEvent::BTypeID(0), &CMainMenuPhase::EnterGame);
		m_Choice = -1;

		Gfx::CMainMenuPhase::GetInstance().OnEnter();
		Gui::CMainMenuPhase::GetInstance().OnEnter();
		return 0;

	}

	int CMainMenuPhase::InternOnRun()
	{
		Game::CCounter& CGameCounter = Game::CCounter::GetInstance();

		if (CGameCounter.GetGameCounter() == 0) {
			CGameCounter.SetGameCounter(3);
		}

		Gfx::CMainMenuPhase::GetInstance().OnRun();
		Gui::CMainMenuPhase::GetInstance().OnRun();

		if (m_Choice == 1)
		{
			return Type::SHUTDOWN;
		}
		if (m_Choice == 0)
		{
			return Type::LOAD_MAP;
		}

		return Type::MAIN_MENU;

	}

	void CMainMenuPhase::EnterGame(Data::CEvent& _Event)
	{

		CMainMenuPhase::GetInstance().SetChoice(_Event.GetData());
	}

	void CMainMenuPhase::SetChoice(int _Choice) {
		m_Choice = _Choice;
	}

	int CMainMenuPhase::InternOnLeave()
	{

		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();
		rEventSystem.Unregister(Data::CEvent::BTypeID(0), &CMainMenuPhase::EnterGame);

		Gfx::CMainMenuPhase::GetInstance().OnLeave();
		Gui::CMainMenuPhase::GetInstance().OnLeave();
		return 0;
	}
}