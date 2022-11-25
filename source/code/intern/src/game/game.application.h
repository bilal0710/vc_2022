#pragma once

#include "game.phase.h"

namespace Game
{
	class Application
	{
	public:
		static Application& GetInstance() {
			static Application instance;
			return instance;
		}
		Application(const Application&) = delete;
		Application& operator =(const Application&) = delete;

	private:
		Application();

	private:
		int m_IndexOfCurrentPhase;
		Phase* m_pPhases[Phase::NumberOfTypes];

	public:
		void Initialize();
		void Run();
		void Finalize();

	private:
		bool RunPhase();
	};

}

