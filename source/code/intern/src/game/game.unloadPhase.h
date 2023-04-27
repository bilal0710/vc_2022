#pragma once

#include "game.phase.h"
#include <data/data.eventSystem.h>


namespace Game
{
	class CUnloadPhase : public CPhase
	{
	public:
		static CUnloadPhase& GetInstance()
		{
			static CUnloadPhase instance;
			return instance;
		};

		CUnloadPhase(const CUnloadPhase&) = delete;
		CUnloadPhase& operator = (const CUnloadPhase&) = delete;

	private:
		CUnloadPhase() :m_ReloadGame(false)
		{};

	private:
		int InternOnEnter() override;
		int InternOnRun() override;
		int InternOnLeave() override;


	public:
		static void ReloadGame(Data::CEvent& data);
		void SetReloadGame(bool _Exit);

	public:
		bool m_ReloadGame;
	};
}
