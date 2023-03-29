#include "game.shutdownPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../data/data.shutdownPhase.h"
#include "../graphics/gfx.shutdownPhase.h"
#include "../gui/gui.shutdownPhase.h"
#include "../logic/logic.shutdownPhase.h"

namespace Game
{
	int CShutdownPhase::InternOnEnter()
	{
		std::cout << "ShutdownPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		Data:: CShutdownPhase::GetInstance().OnEnter();
		Gfx::  ShutdownPhase::GetInstance().OnEnter();
		Gui::  ShutdownPhase::GetInstance().OnEnter();
		Logic::ShutdownPhase::GetInstance().OnEnter();
		return 0;
	}

	int CShutdownPhase::InternOnRun()
	{
		std::cout << "ShutdownPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;

		counter++;


		if (counter > 4)
		{
			Data:: CShutdownPhase::GetInstance().OnRun();
			Gfx::  ShutdownPhase::GetInstance().OnRun();
			Gui::  ShutdownPhase::GetInstance().OnRun();
			Logic::ShutdownPhase::GetInstance().OnRun();

			counter = 0;

			return Type::NumberOfTypes;
		}

		return Type::SHUTDOWN;
	}

	int CShutdownPhase::InternOnLeave()
	{
		std::cout << "ShutdownPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		Data:: CShutdownPhase::GetInstance().OnLeave();
		Gfx::  ShutdownPhase::GetInstance().OnLeave();
		Gui::  ShutdownPhase::GetInstance().OnLeave();
		Logic::ShutdownPhase::GetInstance().OnLeave();
		return 0;
	}
}