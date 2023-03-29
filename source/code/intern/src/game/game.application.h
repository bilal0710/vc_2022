#pragma once

#include "game.phase.h"

namespace Game
{
	class CApplication
	{
	public:
		static CApplication& GetInstance() {
			static CApplication instance;
			return instance;
		}
		CApplication(const CApplication&) = delete;
		CApplication& operator =(const CApplication&) = delete;

	private:
		CApplication();

	private:
		int m_IndexOfCurrentPhase;
		CPhase* m_pPhases[CPhase::NumberOfTypes];

	public:
		void Initialize();
		void Run();
		void Finalize();

	private:
		bool RunPhase();
	};

}

