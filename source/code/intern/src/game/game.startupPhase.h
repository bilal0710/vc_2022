#pragma once


#include "game.phase.h"

namespace Game 
{
	class CStartupPhase: public CPhase
	{
		public:
			static CStartupPhase& GetInstance()
			{
				static CStartupPhase instance;
				return instance;
			};

			CStartupPhase(const CStartupPhase&) = delete;
			CStartupPhase& operator = (const CStartupPhase&) = delete;

		private:
			CStartupPhase()
			{};

		private:
			int InternOnEnter() override;
			int InternOnRun() override;
			int InternOnLeave() override;
	};
}
