#include "data.startupPhase.h"
#include "data.entitySystem.h"

namespace Data
{
	 void StartupPhase::OnEnter()
	{
		 EntitySystem& entitySystem = EntitySystem::GetInstance();
		 entitySystem.test();

	}

	void StartupPhase::OnRun()
	{}

	void StartupPhase::OnLeave()
	{}
}