#include "game.unloadPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphics/gfx.unloadPhase.h"
#include "../gui/gui.unloadPhase.h"
#include "../logic/logic.unloadPhase.h"
#include"game/game.counter.h"
#include <data/data.entitySystem.h>
namespace Game
{
	int CUnloadPhase::InternOnEnter()
	{
		Gfx::CUnloadPhase::GetInstance().OnEnter();
		Gui::CUnloadPhase::GetInstance().OnEnter();
		Logic::CUnloadPhase::GetInstance().OnEnter();
		return 0;
	}

	int CUnloadPhase::InternOnRun()
	{
	Game::CCounter& CGameCounter = Game::CCounter::GetInstance();

		Gfx::CUnloadPhase::GetInstance().OnRun();
		Gui::CUnloadPhase::GetInstance().OnRun();
		Logic::CUnloadPhase::GetInstance().OnRun();

		int GameCounter = CGameCounter.GetGameCounter();
		CGameCounter.SetGameCounter(GameCounter - 1);

		if (m_ReloadGame && GameCounter > 1) {
			return Type::LOAD_MAP;
		}

		return Type::MAIN_MENU;


	}

	void CUnloadPhase::ReloadGame(Data::CEvent& _Event)
	{
		CUnloadPhase UnloadPhaseClass;


		UnloadPhaseClass.GetInstance().SetReloadGame(true);
	}

	void CUnloadPhase::SetReloadGame(bool _Reload) {
		m_ReloadGame = _Reload;
	}

	int CUnloadPhase::InternOnLeave()
	{
		Data::CEntitySystem::GetInstance().DestoryAllEntities();

		Gfx::CUnloadPhase::GetInstance().OnLeave();
		Gui::CUnloadPhase::GetInstance().OnLeave();
		Logic::CUnloadPhase::GetInstance().OnLeave();
		return 0;
	}
}