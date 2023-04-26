#pragma once

#include "game.phase.h"
#include <data/data.eventSystem.h>

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
		CPlayPhase():m_EndGame(false)
		{};

	

	private:
		int InternOnEnter() override;
		int InternOnRun() override;
		int InternOnLeave() override;

	public:
		static void FinishGame(Data::CEvent& data);
		void SetEndGame(bool _Exit);

	public:
		bool m_EndGame;
	};

}
