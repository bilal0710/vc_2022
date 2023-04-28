#include "logic.loadPhase.h"
#include "data/data.entitySystem.h"
#include "data/data.entity.h"


#include <tinyxml2.h>
#include <sstream>
#include <iostream>

using namespace tinyxml2;
namespace Logic
{
    void CLoadPhase::OnEnter()
    {}

    void CLoadPhase::OnRun(tinyxml2::XMLDocument& _rMapEntity)
    {
        std::cout << "DATA::LOAD::Run" << std::endl;

        Data::CEntitySystem& rEntitySystem = Data::CEntitySystem::GetInstance();
        XMLElement* pEntities = _rMapEntity.FirstChildElement("entities");
        XMLElement* pXmlEntity = pEntities->FirstChildElement("entity");

        for (;;)
        {
            if (pXmlEntity == nullptr)
            {
                break;
            }
            XMLElement* pLogicElement = pXmlEntity->FirstChildElement("logic");
            bool canCollide;
            istringstream(pLogicElement->FirstChildElement("canCollide")->FirstChild()->Value()) >> std::boolalpha >> canCollide;

            auto Id= rEntitySystem.GetEntityID(pXmlEntity->FindAttribute("name")->Value());
            Data::CEntity& rEntity = rEntitySystem.GetEntity(Id);

            rEntity.canCollide = canCollide;

            if (rEntity.metaEntity->name == "ladder") {
                std::cout << rEntity.metaEntity->name << std::endl;
            }

            pXmlEntity = pXmlEntity->NextSiblingElement();
        }

    }

    void CLoadPhase::OnLeave()
    {}
}