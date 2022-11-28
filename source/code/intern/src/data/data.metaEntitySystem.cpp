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

		MetaEntity& newMetaEntity = MetaEntitySystem::createMetaEntity(name);

		newMetaEntity.name = name;

		std::cout << "Data::MetaEntitySystem::name -> " << newMetaEntity.name << std::endl;

	}
	MetaEntity& MetaEntitySystem::createMetaEntity(const string _pName)
	{
		Core::CIDManager::BID id = m_idManger.Register(_pName);
		MetaEntity& metaEntity = m_itemManager.CreateItem(id);
	
		return metaEntity;

	}
}

