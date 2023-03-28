#include "data.startupPhase.h"
#include "data.metaEntitySystem.h"
#include <iostream>

namespace Data
{
	 void StartupPhase::OnEnter()
	{
		 std::cout << "Data::StartupPhase::OnEnter" << std::endl;
		 std::cout << "\n" << std::endl;
		 
	}

	void StartupPhase::OnRun(tinyxml2::XMLDocument& doc)
	{
		MetaEntitySystem::GetInstance().Initialize(doc);
	}

	void StartupPhase::OnLeave()
	{}
}