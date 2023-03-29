#pragma once

#include "game.phase.h"

namespace Game
{
	class CPlayPhase : public CPhase
	{
	public:
		static CPlayPhase& GetInstance()
		{
			static CPlayPhase instance;
			return instance;
		};

		CPlayPhase(const CPlayPhase&) = delete;
		CPlayPhase& operator = (const CPlayPhase&) = delete;

	private:
		CPlayPhase()
		{};

		int counter = 0;

	private:
		int InternOnEnter() override;
		int InternOnRun() override;
		int InternOnLeave() override;
	};
}
