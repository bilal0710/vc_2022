#pragma once

#include "game.phase.h"

namespace Game
{
	class CMainMenuPhase : public CPhase
	{
	public:
		static CMainMenuPhase& GetInstance()
		{
			static CMainMenuPhase instance;
			return instance;
		};

		CMainMenuPhase(const CMainMenuPhase&) = delete;
		CMainMenuPhase& operator = (const CMainMenuPhase&) = delete;

	private:
		CMainMenuPhase()
		{};

	private:
		int InternOnEnter() override;
		int InternOnRun() override;
		int InternOnLeave() override;
	};
}
