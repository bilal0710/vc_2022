#include "data.loadPhase.h"
#include <iostream>

#include <fstream>

//#include "data.metaEntitySystem.h"
#include "data.entitySystem.h"

namespace Data
{
	void CLoadPhase::OnEnter()
	{}

	void CLoadPhase::OnRun(tinyxml2::XMLDocument& _rMapEntity)
	{
		CEntitySystem::GetInstance().Initialize(_rMapEntity);
	}

	void CLoadPhase::OnLeave()
	{}
}