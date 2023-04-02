#include <tinyxml2.cpp>
#include "data.MetaEntitySystem.h"
#include "../core/core_aabb3.h"
#include "../core/core_explode.h"
#include <iostream>


using namespace tinyxml2;

namespace Data
{
	void CMetaEntitySystem::Initialize(tinyxml2::XMLDocument& _rMetaEntityDoc)
	{

		XMLElement* pMetaEntities = _rMetaEntityDoc.FirstChildElement("meta-entities");
		XMLElement* pMetaEntity = pMetaEntities->FirstChildElement("meta-entity");

		for (;;)
		{
			if (pMetaEntity == nullptr)
			{
				break;
			}

			std::string name = pMetaEntity->FindAttribute("name")->Value();

			XMLElement* pDataElement = pMetaEntity->FirstChildElement("data");
			float Size = pDataElement->FirstChildElement("size")->FindAttribute("value")->FloatValue();

			auto MinCornerStrings = Core::Explode(pDataElement->FirstChildElement("aabb")->FindAttribute("minCorner")->Value(), ';');
			auto MaxCornerStrings = Core::Explode(pDataElement->FirstChildElement("aabb")->FindAttribute("maxCorner")->Value(), ';');


				Core::AABB3Float aabb = Core::AABB3Float(
				Core::Float3(
					std::stof(MinCornerStrings[0]),
					std::stof(MinCornerStrings[1]),
					std::stof(MinCornerStrings[2])
				),
				Core::Float3(
					std::stof(MaxCornerStrings[0]),
					std::stof(MaxCornerStrings[1]),
					std::stof(MaxCornerStrings[2])
				)
			);

			CMetaEntity& NewMetaEntity = CreateMetaEntity(name);
			NewMetaEntity.name = name;
			NewMetaEntity.size = Size;
			NewMetaEntity.aabb = aabb;


			std::cout << "Data::MetaEntitySystem::name -> " << NewMetaEntity.name << std::endl;
			std::cout << "Data::MetaEntitySystem::size -> " << NewMetaEntity.size << std::endl;
			std::cout << "\n" << std::endl;

			pMetaEntity = pMetaEntity->NextSiblingElement();
		}

	}
	CMetaEntity& CMetaEntitySystem::CreateMetaEntity(const string _pName)
	{
		CIDManager::BID id = m_IdManger.Register(_pName);
		CMetaEntity& MetaEntity = m_ItemManager.CreateItem(id);

		return MetaEntity;

	}

	CMetaEntity& CMetaEntitySystem::GetMetaEntity(CIDManager::BID _ID)
	{
		return m_ItemManager.GetItem(_ID);	
	
	}

	void CMetaEntitySystem::DestroyAllMetaEntities()
	{
		m_IdManger.Clear();
		m_ItemManager.Clear();
	}

	bool CMetaEntitySystem::ContainsMetaEntity(string& _rName)
	{
		return m_IdManger.ContainsName(_rName);;
	}

	CMetaEntity& CMetaEntitySystem::SearchMetaEntity(std::string _Name)
	{
		return m_ItemManager.GetItem(m_IdManger.GetIDByName(_Name));
	}

	bool CMetaEntitySystem::ContainsMetaEntity(std::string _Name)
	{
		return m_IdManger.ContainsName(_Name);
	}

	Core::CIDManager::BID CMetaEntitySystem::GetMetaEntityID(std::string _Name)
	{
		return m_IdManger.GetIDByName(_Name);
	}
}

