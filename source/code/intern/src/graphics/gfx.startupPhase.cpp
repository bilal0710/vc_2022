#include "gfx.startupPhase.h"
#include <iostream>

#include <tinyxml2.h>
#include <fstream>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <game/game.application.h>
#include <data/data.metaEntitySystem.h>

using namespace tinyxml2;


void Gfx::StartupPhase::OnEnter()
{
	std::cout << "Gfx::StartupPhase::OnEnter" << std::endl;
}

void Gfx::StartupPhase::OnRun(XMLDocument& doc)
{
	std::cout << "Gfx::StartupPhase::OnRun" << std::endl;

    Game::CApplication& app = Game::CApplication::GetInstance();
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
        if (texture->loadFromFile(texturePath))
        {
            metaEntity.facetes[0] = texture;
        }

        xmlMetaEntity = xmlMetaEntity->NextSiblingElement();
    }
}


void Gfx::StartupPhase::OnLeave()
{
	std::cout << "Gfx::StartupPhase::OnLeave" << std::endl;
}
