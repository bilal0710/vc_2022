#pragma once

#include "game.phase.h"

namespace Game
{
	class ShutdownPhase : public Phase
	{
	public:
		static ShutdownPhase& GetInstance()
		{
			static ShutdownPhase instance;
			return instance;
		};

		ShutdownPhase(const ShutdownPhase&) = delete;
		ShutdownPhase& operator = (const ShutdownPhase&) = delete;

	private:
		ShutdownPhase()
		{};

		int counter = 0;

	private:
		int InternOnEnter() override;
		int InternOnRun() override;
		int InternOnLeave() override;
	};
}
