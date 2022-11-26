#pragma once

#include "game.phase.h"

namespace Game
{
	class MainMenuPhase : public Phase
	{
	public:
		static MainMenuPhase& GetInstance()
		{
			static MainMenuPhase instance;
			return instance;
		};

		MainMenuPhase(const MainMenuPhase&) = delete;
		MainMenuPhase& operator = (const MainMenuPhase&) = delete;

	private:
		MainMenuPhase()
		{};

		int counter = 0;

	private:
		int InternOnEnter() override;
		int InternOnRun() override;
		int InternOnLeave() override;
	};
}
