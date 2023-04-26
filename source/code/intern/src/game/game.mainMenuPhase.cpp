#include "game.mainMenuPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../graphics/gfx.mainMenuPhase.h"
#include "../gui/gui.mainMenuPhase.h"
#include"game/game.appWindow.h"
#include <data/data.eventSystem.h>


namespace Game
{
	int CMainMenuPhase::InternOnEnter()
	{
		std::cout << "Game::MainMenuPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;

		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();

		CMainMenuPhase MainMenuClass;
		rEventSystem.Register(Data::CEvent::BTypeID(0), &MainMenuClass.EnterGame);
		m_Choice = -1;

		Gfx::CMainMenuPhase::GetInstance().OnEnter();
		Gui::CMainMenuPhase::GetInstance().OnEnter();
		return 0;

	}

	int CMainMenuPhase::InternOnRun()
	{
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
		std::cout << "GFX::MainMenuPhase -> listen to event" << std::endl;
		
		CMainMenuPhase MainMenuClass;
		MainMenuClass.GetInstance().SetChoice(_Event.GetData());
	}

	void CMainMenuPhase::SetChoice(int _Choice) {
		m_Choice = _Choice;
	}

	int CMainMenuPhase::InternOnLeave()
	{
		std::cout << "Game::MainMenuPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;


		Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();

		CMainMenuPhase MainMenuClass;
		rEventSystem.Unregister(Data::CEvent::BTypeID(0), &MainMenuClass.EnterGame);

		Gfx::CMainMenuPhase::GetInstance().OnLeave();
		Gui::CMainMenuPhase::GetInstance().OnLeave();
		return 0;
	}
}