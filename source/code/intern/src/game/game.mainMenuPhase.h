#pragma once

#include "game.phase.h"
#include <data/data.eventSystem.h>

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
		CMainMenuPhase():m_Choice(-1)
		{};

	private:
		int InternOnEnter() override;
		int InternOnRun() override;
		int InternOnLeave() override;

	public:
		//static void EventListener(Data::CEvent& data);
		static void EnterGame(Data::CEvent& data);
		void SetChoice(int _Choice);

	private: 
		int m_Choice;
	};
}
