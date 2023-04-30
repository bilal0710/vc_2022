 #include "data.startupPhase.h"
#include "data.metaEntitySystem.h"
#include <iostream>

namespace Data
{
	 void CStartupPhase::OnEnter()
	{ 
	}

	void CStartupPhase::OnRun(tinyxml2::XMLDocument& _rMetaEntityDoc)
	{
		CMetaEntitySystem::GetInstance().Initialize(_rMetaEntityDoc);
	}

	void CStartupPhase::OnLeave()
	{}
}