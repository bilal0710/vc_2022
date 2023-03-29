#pragma once

#include "game.phase.h"

namespace Game
{
	class CShutdownPhase : public CPhase
	{
	public:
		static CShutdownPhase& GetInstance()
		{
			static CShutdownPhase instance;
			return instance;
		};

		CShutdownPhase(const CShutdownPhase&) = delete;
		CShutdownPhase& operator = (const CShutdownPhase&) = delete;

	private:
		CShutdownPhase()
		{};

		int counter = 0;

	private:
		int InternOnEnter() override;
		int InternOnRun() override;
		int InternOnLeave() override;
	};
}
