#pragma once


#include "game.phase.h"

namespace Game
{
	class CCounter 
	{
	public:
		static CCounter& GetInstance()
		{
			static CCounter instance;
			return instance;
		};

		CCounter(const CCounter&) = delete;
		CCounter& operator = (const CCounter&) = delete;

	private:
		CCounter():m_Counter(3)
		{};

	private:
		int m_Counter;


	public:
		int GetGameCounter() {
			return m_Counter;
		}
		void SetGameCounter(int _GameCounter) {
			m_Counter = _GameCounter;
		}
	};
}
