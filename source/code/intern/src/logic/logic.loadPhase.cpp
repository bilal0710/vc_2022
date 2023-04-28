#include "logic.loadPhase.h"
#include <iostream>
#include "data/data.entitySystem.h"

namespace Logic
{
    void CLoadPhase::OnEnter()
    {}

    void CLoadPhase::OnRun(tinyxml2::XMLDocument& _rMapEntity)
    {
        std::cout << "DATA::LOAD::Run" << std::endl;

       // int EntityCount = Data::CEntitySystem::GetInstance().Initialize(_rMapEntity);


        //Data::CMetaEntitySystem& rMetaEntitySystem = Data::CMetaEntitySystem::GetInstance();
        //
        //XMLElement* pEntities = _rMapEntity.FirstChildElement("entities");
        //XMLElement* pXmlEntity = pEntities->FirstChildElement("entity");


    }

    void CLoadPhase::OnLeave()
    {}
}