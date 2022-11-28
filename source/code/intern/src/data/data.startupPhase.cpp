#include "data.startupPhase.h"
#include "data.metaEntitySystem.h"
#include <iostream>

namespace Data
{
	 void StartupPhase::OnEnter()
	{
		 std::cout << "Data::StartupPhase::OnEnter" << std::endl;
		 MetaEntitySystem& entitySystem = MetaEntitySystem::GetInstance();
		 entitySystem.test();

	}

	void StartupPhase::OnRun()
	{}

	void StartupPhase::OnLeave()
	{}
}