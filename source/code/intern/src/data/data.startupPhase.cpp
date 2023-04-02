 #include "data.startupPhase.h"
#include "data.metaEntitySystem.h"
#include <iostream>

namespace Data
{
	 void CStartupPhase::OnEnter()
	{
		 std::cout << "Data::StartupPhase::OnEnter" << std::endl;
		 std::cout << "\n" << std::endl;
		 
	}

	void CStartupPhase::OnRun(tinyxml2::XMLDocument& rMetaEntityDoc)
	{
		CMetaEntitySystem::GetInstance().Initialize(rMetaEntityDoc);
	}

	void CStartupPhase::OnLeave()
	{}
}