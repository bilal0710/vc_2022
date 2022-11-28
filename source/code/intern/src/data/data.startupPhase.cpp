#include "data.startupPhase.h"
#include "data.metaEntitySystem.h"
#include <iostream>

namespace Data
{
	 void StartupPhase::OnEnter()
	{
		 std::cout << "Data::StartupPhase::OnEnter" << std::endl;
		 MetaEntitySystem::GetInstance().Initialize();
		 
	}

	void StartupPhase::OnRun()
	{}

	void StartupPhase::OnLeave()
	{}
}