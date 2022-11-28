#include <tinyxml2.h>
#include <tinyxml2.cpp>
#include "data.MetaEntitySystem.h"
#include <iostream>



namespace Data
{
	void MetaEntitySystem::Initialize()
	{
		tinyxml2::XMLDocument doc;
		doc.LoadFile("../code/intern/src/data/meta_entity.xml");
		tinyxml2::XMLElement* metaEntities = doc.FirstChildElement("meta_entities");
		tinyxml2::XMLElement* metaEntity = metaEntities->FirstChildElement("meta_entity");
		std::string name = metaEntity->FindAttribute("name")->Value();

		MetaEntity& newMetaEntity = MetaEntitySystem::CreateMetaEntity(name);

		newMetaEntity.name = name;

		std::cout << "Data::MetaEntitySystem::name -> " << newMetaEntity.name << std::endl;

	}
	MetaEntity& MetaEntitySystem::CreateMetaEntity(const string _pName)
	{
		CIDManager::BID id = m_idManger.Register(_pName);
		MetaEntity& metaEntity = m_itemManager.CreateItem(id);

		return metaEntity;

	}
	MetaEntity& MetaEntitySystem::GetMetaEntity(CIDManager::BID _ID)
	{
		return m_itemManager.GetItem(_ID);	
	
	}
	void MetaEntitySystem::DestroyAllMetaEntities()
	{
		m_idManger.Clear();
		m_itemManager.Clear();
	}
	bool MetaEntitySystem::ContainsMEtaEntity(string& _pName)
	{
		return m_idManger.ContainsName(_pName);;
	}
}

