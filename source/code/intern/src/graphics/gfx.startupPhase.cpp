#include "gfx.startupPhase.h"
#include <iostream>

#include <tinyxml2.h>
#include <fstream>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <data/data.metaEntitySystem.h>

using namespace tinyxml2;


void Gfx::CStartupPhase::OnEnter()
{
	std::cout << "Gfx::StartupPhase::OnEnter" << std::endl;
	// create the window
	window.create(sf::VideoMode(1200, 900), "Bilal Alnaani Application");
}

void Gfx::CStartupPhase::OnRun(XMLDocument& doc)
{
	std::cout << "Gfx::StartupPhase::OnRun" << std::endl;

	Data::CMetaEntitySystem& metaEntitySystem = Data::CMetaEntitySystem::GetInstance();

	XMLElement* metaEntities = doc.FirstChildElement("meta-entities");
	XMLElement* xmlMetaEntity = metaEntities->FirstChildElement("meta-entity");

	for (;;)
	{
		if (xmlMetaEntity == nullptr)
		{
			break;
		}

		auto id = metaEntitySystem.GetMetaEntityID(xmlMetaEntity->FindAttribute("name")->Value());
		Data::CMetaEntity& metaEntity = metaEntitySystem.GetMetaEntity(id);


		XMLElement* graphicsElement = xmlMetaEntity->FirstChildElement("graphics");

		std::string texturePath = graphicsElement->FirstChildElement("texture")->FindAttribute("value")->Value();

		
		sf::Texture* texture = new sf::Texture();
		
		std::cout << texturePath << std::endl;

		if (texture->loadFromFile(texturePath))
		{
			std::cout << "Gfx::texture" << std::endl;
			metaEntity.facetes[0] = texture;
		}

		xmlMetaEntity = xmlMetaEntity->NextSiblingElement();
	}
}


void Gfx::CStartupPhase::OnLeave()
{
	std::cout << "Gfx::StartupPhase::OnLeave" << std::endl;
}
