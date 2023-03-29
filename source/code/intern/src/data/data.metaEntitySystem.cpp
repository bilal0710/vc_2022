#include <tinyxml2.cpp>
#include "data.MetaEntitySystem.h"
#include "../core/core_aabb3.h"
#include "../core/core_explode.h"
#include <iostream>


using namespace tinyxml2;

namespace Data
{
	void CMetaEntitySystem::Initialize(tinyxml2::XMLDocument& doc)
	{

		XMLElement* metaEntities = doc.FirstChildElement("meta-entities");
		XMLElement* metaEntity = metaEntities->FirstChildElement("meta-entity");

		//std::string name = metaEntity->FindAttribute("name")->Value();

		//MetaEntity& newMetaEntity = MetaEntitySystem::CreateMetaEntity(name);

		//newMetaEntity.name = name;

		for (;;)
		{
			if (metaEntity == nullptr)
			{
				break;
			}

			std::string name = metaEntity->FindAttribute("name")->Value();

			XMLElement* dataElement = metaEntity->FirstChildElement("data");
			float size = dataElement->FirstChildElement("size")->FindAttribute("value")->FloatValue();

			auto minCornerStrings = Core::Explode(dataElement->FirstChildElement("aabb")->FindAttribute("minCorner")->Value(), ';');
			auto maxCornerStrings = Core::Explode(dataElement->FirstChildElement("aabb")->FindAttribute("maxCorner")->Value(), ';');


				Core::AABB3Float aabb = Core::AABB3Float(
				Core::Float3(
					std::stof(minCornerStrings[0]),
					std::stof(minCornerStrings[1]),
					std::stof(minCornerStrings[2])
				),
				Core::Float3(
					std::stof(maxCornerStrings[0]),
					std::stof(maxCornerStrings[1]),
					std::stof(maxCornerStrings[2])
				)
			);

			CMetaEntity& newMetaEntity = CreateMetaEntity(name);
			newMetaEntity.name = name;
			newMetaEntity.size = size;
			newMetaEntity.aabb = aabb;


			std::cout << "Data::MetaEntitySystem::name -> " << newMetaEntity.name << std::endl;
			std::cout << "Data::MetaEntitySystem::size -> " << newMetaEntity.size << std::endl;
			std::cout << "\n" << std::endl;

			metaEntity = metaEntity->NextSiblingElement();
		}

	}
	CMetaEntity& CMetaEntitySystem::CreateMetaEntity(const string _pName)
	{
		CIDManager::BID id = m_idManger.Register(_pName);
		CMetaEntity& metaEntity = m_itemManager.CreateItem(id);

		return metaEntity;

	}

	CMetaEntity& CMetaEntitySystem::GetMetaEntity(CIDManager::BID _ID)
	{
		return m_itemManager.GetItem(_ID);	
	
	}

	void CMetaEntitySystem::DestroyAllMetaEntities()
	{
		m_idManger.Clear();
		m_itemManager.Clear();
	}

	bool CMetaEntitySystem::ContainsMetaEntity(string& _pName)
	{
		return m_idManger.ContainsName(_pName);;
	}

	CMetaEntity& CMetaEntitySystem::SearchMetaEntity(std::string name)
	{
		return m_itemManager.GetItem(m_idManger.GetIDByName(name));
	}

	bool CMetaEntitySystem::ContainsMetaEntity(std::string name)
	{
		return m_idManger.ContainsName(name);
	}

	Core::CIDManager::BID CMetaEntitySystem::GetMetaEntityID(std::string name)
	{
		return m_idManger.GetIDByName(name);
	}
}

