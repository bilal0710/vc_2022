#include "data.entitySystem.h"

#include <tinyxml2.h>
#include <iostream>
#include <string>

#include "../core/core_aabb3.h"
#include "../core/core_explode.h"

#include "data.metaEntitySystem.h"
//#include "data.playerSystem.h"

using namespace tinyxml2;

namespace Data
{
    int CEntitySystem::Initialize(tinyxml2::XMLDocument& doc)
    {
        int entityCount = 0;

        Data::CMetaEntitySystem& metaEntitySystem = Data::CMetaEntitySystem::GetInstance();

        XMLElement* entities = doc.FirstChildElement("entities");
        XMLElement* xmlEntity = entities->FirstChildElement("entity");

        for (;;)
        {
            if (xmlEntity == nullptr)
            {
                break;
            }

            std::string name = xmlEntity->FindAttribute("name")->Value();

            std::string metaEntityName = xmlEntity->FindAttribute("meta-entity")->Value();
            auto id = metaEntitySystem.GetMetaEntityID(metaEntityName);
            Data::CMetaEntity& metaEntity = metaEntitySystem.GetMetaEntity(id);

            XMLElement* dataElement = xmlEntity->FirstChildElement("data");

            auto sizeStrings = Core::Explode(dataElement->FirstChildElement("size")->FirstChild()->Value(), ';');
            auto positionStrings = Core::Explode(dataElement->FirstChildElement("position")->FirstChild()->Value(), ';');

            // TODO: AABB and stuff

            Entity& entity = CreateEntity(name);
            entity.size = Core::Float3(
                std::stof(sizeStrings[0]),
                std::stof(sizeStrings[1]),
                std::stof(sizeStrings[2])
            );
            entity.position = Core::Float3(
                std::stof(positionStrings[0]),
                std::stof(positionStrings[1]),
                std::stof(positionStrings[2])
            );
            entity.metaEntity = &metaEntity;

            entityCount++;
            std::cout << "Entity-name: " << name << std::endl;

            if (metaEntity.name == "player")
            {
                //Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
                //playerSystem.SetPlayer(&entity);

                entity.aabb = Core::CAABB3<float>(
                    Core::Float3(entity.position[0], entity.position[1], entity.position[2]),
                    Core::Float3(entity.position[0] + 64, entity.position[1] + 64, entity.position[2])
                );
            }

            xmlEntity = xmlEntity->NextSiblingElement();
        }

        return entityCount;
    }

    std::vector<Data::Entity*> CEntitySystem::GetAllEntities()
    {
        return itemManager.GetAllItems();
    }

    Entity& CEntitySystem::CreateEntity(std::string name)
    {
        Core::CIDManager::BID id = idManager.Register(name);

        return itemManager.CreateItem(id);
    }

    void CEntitySystem::DestroyEntity()
    {
        throw std::logic_error("Not Implemented");
    }

    void CEntitySystem::DestoryAllEntities()
    {
        itemManager.Clear();
        idManager.Clear();
    }

    Entity& CEntitySystem::SearchEntity(std::string name)
    {
        return itemManager.GetItem(idManager.GetIDByName(name));
    }

    Entity& CEntitySystem::GetEntity(Core::CIDManager::BID id)
    {
        return itemManager.GetItem(id);
    }

    bool CEntitySystem::ContainsEntity(std::string name)
    {
        return idManager.ContainsName(name);
    }

    Core::CIDManager::BID CEntitySystem::GetEntityID(std::string name)
    {
        return idManager.GetIDByName(name);
    }
}
