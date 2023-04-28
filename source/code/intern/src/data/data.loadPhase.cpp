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
        std::cout << "DATA::LOAD::Run" << std::endl;

        int EntityCount = CEntitySystem::GetInstance().Initialize(_rMapEntity);

        std::cout << "DATA::LOAD::Run " << EntityCount << " Entities initialized" << std::endl;
    }

    void CLoadPhase::OnLeave()
    {}
}