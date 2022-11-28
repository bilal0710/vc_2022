#include <tinyxml2.h>
#include <tinyxml2.cpp>
#include "data.MetaEntitySystem.h"
#include <iostream>


namespace Data
{
	void MetaEntitySystem::test()
	{
		
		tinyxml2::XMLDocument doc;
		doc.LoadFile("../code/intern/src/data/meta_entity.xml");
		tinyxml2::XMLElement* metaEntities = doc.FirstChildElement("meta_entities");
		tinyxml2::XMLElement* metaEntity = metaEntities->FirstChildElement("meta_entity");
		std::string title = doc.FirstChildElement("meta_entities")->FirstChildElement("meta_entity")->FindAttribute("name")->Value();

		std::cout << "Data::EntitySystem::title -> " << title << std::endl;

	}
}

