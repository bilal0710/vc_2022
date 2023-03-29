#include <iostream>

#include <fstream>

#include "data.loadPhase.h"
#include "data.metaEntitySystem.h"
#include "data.entitySystem.h"

namespace Data
{
    void CLoadPhase::OnEnter()
    {}

    void CLoadPhase::OnRun(tinyxml2::XMLDocument& doc)
    {
        std::cout << "DATA::LOAD::Run" << std::endl;

        int entityCount = CEntitySystem::GetInstance().Initialize(doc);

        std::cout << "DATA::LOAD::Run " << entityCount << " Entities initialized" << std::endl;
    }

    void CLoadPhase::OnLeave()
    {}
}