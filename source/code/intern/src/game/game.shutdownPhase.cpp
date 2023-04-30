#include "game.shutdownPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../data/data.shutdownPhase.h"
#include "../graphics/gfx.shutdownPhase.h"
#include "../gui/gui.shutdownPhase.h"
#include "../logic/logic.shutdownPhase.h"
#include "game/game.appWindow.h"
#include <data/data.entitySystem.h>
#include <data/data.metaEntitySystem.h>


namespace Game
{
	int CShutdownPhase::InternOnEnter()
	{
		std::cout << "ShutdownPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		Data::CShutdownPhase::GetInstance().OnEnter();
		Gfx::CShutdownPhase::GetInstance().OnEnter();
		Gui::ShutdownPhase::GetInstance().OnEnter();
		Logic::CShutdownPhase::GetInstance().OnEnter();
		return 0;
	}

	int CShutdownPhase::InternOnRun()
	{
		std::cout << "ShutdownPhase::InternOnRun" << std::endl;
		std::cout << "------------------------" << std::endl;

		Data::CShutdownPhase::GetInstance().OnRun();
		Gfx::CShutdownPhase::GetInstance().OnRun();
		Gui::ShutdownPhase::GetInstance().OnRun();
		Logic::CShutdownPhase::GetInstance().OnRun();

		return Type::NumberOfTypes;
	}

	int CShutdownPhase::InternOnLeave()
	{
		Game::CApplicationWindow& rAppWindow = Game::CApplicationWindow::GetInstance();
		std::cout << "ShutdownPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		Data::CShutdownPhase::GetInstance().OnLeave();
		Gfx::CShutdownPhase::GetInstance().OnLeave();
		Gui::ShutdownPhase::GetInstance().OnLeave();
		Logic::CShutdownPhase::GetInstance().OnLeave();

		Data::CEntitySystem::GetInstance().DestoryAllEntities();
		Data::CMetaEntitySystem::GetInstance().DestroyAllMetaEntities();

		rAppWindow.m_AppWindow.close();
		return 0;
	}
}