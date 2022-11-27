#include <tinyxml2.h>
#include "data.entitySystem.h"

namespace Data
{
	void EntitySystem::test()
	{
		tinyxml2::XMLDocument doc;
		doc.LoadFile("meta_entity.xml");

		const char* title = doc.FirstChildElement("meta_entities")->FirstChildElement("meta_entity")->FindAttribute("name")->Value();
		printf("Name of play (1): %s\n", title);
	}
}

