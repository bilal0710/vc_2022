#include "data.entitySystem.h"

#include <tinyxml2.h>
#include <iostream>
#include <string>

#include "../core/core_aabb3.h"
#include "../core/core_explode.h"

#include "data.metaEntitySystem.h"
#include "data.playerSystem.h"
#include "data.entityCategory.h"

#include <iostream>

using namespace tinyxml2;

namespace Data
{
	void CEntitySystem::Initialize(tinyxml2::XMLDocument& _rMapEntity)
	{
		int EntityCount = 0;

		Data::CMetaEntitySystem& rMetaEntitySystem = Data::CMetaEntitySystem::GetInstance();

		XMLElement* pEntities = _rMapEntity.FirstChildElement("entities");
		XMLElement* pXmlEntity = pEntities->FirstChildElement("entity");

		for (;;)
		{
			if (pXmlEntity == nullptr)
			{
				break;
			}


			std::string Name = pXmlEntity->FindAttribute("name")->Value();

			std::string MetaEntityName = pXmlEntity->FindAttribute("meta-entity")->Value();
			auto ID = rMetaEntitySystem.GetMetaEntityID(MetaEntityName);
			Data::CMetaEntity& rMetaEntity = rMetaEntitySystem.GetMetaEntity(ID);

			XMLElement* pDataElement = pXmlEntity->FirstChildElement("data");

			auto SizeStrings = Core::Explode(pDataElement->FirstChildElement("size")->FirstChild()->Value(), ';');
			auto PositionStrings = Core::Explode(pDataElement->FirstChildElement("position")->FirstChild()->Value(), ';');
			auto type = atoi(pDataElement->FirstChildElement("type")->FirstChild()->Value());
			

			CEntity& rEntity = CreateEntity(Name);
			rEntity.size = Core::Float3(
				std::stof(SizeStrings[0]),
				std::stof(SizeStrings[1]),
				std::stof(SizeStrings[2])
			);
			rEntity.position = Core::Float3(
				std::stof(PositionStrings[0]),
				std::stof(PositionStrings[1]),
				std::stof(PositionStrings[2])
			);
			rEntity.aabb = Core::CAABB3<float>(
				Core::Float3(rEntity.position[0],
					rEntity.position[1],
					rEntity.position[2]),
				Core::Float3(rEntity.position[0] + rEntity.size[0],
					rEntity.position[1] + rEntity.size[1],
					rEntity.position[2] + rEntity.size[2]
				));


			rEntity.metaEntity = &rMetaEntity;
			if (type < SEntityCategory::NumberOfMembers)
			{
				rEntity.category = SEntityCategory::Enum(type);
			}

			EntityCount++;

			if (rMetaEntity.name == "mario")
			{
				Data::CPlayerSystem& rPlayerSystem = Data::CPlayerSystem::GetInstance();
				rPlayerSystem.SetPlayer(&rEntity);
			}

			pXmlEntity = pXmlEntity->NextSiblingElement();
		}
	}

	std::vector<Data::CEntity*> CEntitySystem::GetAllEntities()
	{
		return m_ItemManager.GetAllItems();
	}

	CEntity& CEntitySystem::CreateEntity(std::string name)
	{
		Core::CIDManager::BID id = m_IdManager.Register(name);

		return m_ItemManager.CreateItem(id);
	}

	void CEntitySystem::DestroyEntity()
	{
		throw std::logic_error("Not Implemented");
	}

	void CEntitySystem::DestoryAllEntities()
	{
		m_ItemManager.Clear();
		m_IdManager.Clear();
	}

	CEntity& CEntitySystem::SearchEntity(std::string name)
	{
		return m_ItemManager.GetItem(m_IdManager.GetIDByName(name));
	}

	CEntity& CEntitySystem::GetEntity(Core::CIDManager::BID id)
	{
		return m_ItemManager.GetItem(id);
	}

	bool CEntitySystem::ContainsEntity(std::string name)
	{
		return m_IdManager.ContainsName(name);
	}

	Core::CIDManager::BID CEntitySystem::GetEntityID(std::string name)
	{
		return m_IdManager.GetIDByName(name);
	}
}
