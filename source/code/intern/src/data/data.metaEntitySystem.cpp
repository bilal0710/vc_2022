#include <tinyxml2.cpp>
#include "data.MetaEntitySystem.h"
#include <iostream>



namespace Data
{
	void MetaEntitySystem::Initialize()
	{
		tinyxml2::XMLDocument doc;
		doc.LoadFile("../code/intern/src/data/meta_entity.xml");

		tinyxml2::XMLElement* metaEntities = doc.FirstChildElement("meta-entities");
		tinyxml2::XMLElement* metaEntity = metaEntities->FirstChildElement("meta-entity");

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
	bool MetaEntitySystem::ContainsMetaEntity(string& _pName)
	{
		return m_idManger.ContainsName(_pName);;
	}

	MetaEntity& MetaEntitySystem::SearchMetaEntity(std::string name)
	{
		return m_itemManager.GetItem(m_idManger.GetIDByName(name));
	}


	bool MetaEntitySystem::ContainsMetaEntity(std::string name)
	{
		return m_idManger.ContainsName(name);
	}

	Core::CIDManager::BID MetaEntitySystem::GetMetaEntityID(std::string name)
	{
		return m_idManger.GetIDByName(name);
	}
}

