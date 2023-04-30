#include "gfx.startupPhase.h"
#include <iostream>

#include <tinyxml2.h>
#include <fstream>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <data/data.metaEntitySystem.h>

#include"game/game.appWindow.h"

using namespace tinyxml2;


void Gfx::CStartupPhase::OnEnter()
{
	// create the window

	Game::CApplicationWindow& rAppWindow = Game::CApplicationWindow::GetInstance();
	rAppWindow.OnCreate();

}

void Gfx::CStartupPhase::OnRun(XMLDocument& _rMetaEntityDoc)
{

	Data::CMetaEntitySystem& rMetaEntitySystem = Data::CMetaEntitySystem::GetInstance();

	XMLElement* pMetaEntities = _rMetaEntityDoc.FirstChildElement("meta-entities");
	XMLElement* pXMLMetaEntity = pMetaEntities->FirstChildElement("meta-entity");

	for (;;)
	{
		if (pXMLMetaEntity == nullptr)
		{
			break;
		}

		auto Id = rMetaEntitySystem.GetMetaEntityID(pXMLMetaEntity->FindAttribute("name")->Value());
		Data::CMetaEntity& rMetaEntity = rMetaEntitySystem.GetMetaEntity(Id);


		XMLElement* GraphicsElement = pXMLMetaEntity->FirstChildElement("graphics");

		std::string TexturePath = GraphicsElement->FirstChildElement("texture")->FindAttribute("value")->Value();

		
		sf::Texture* pTexture = new sf::Texture();
	

		if (pTexture->loadFromFile(TexturePath))
		{
			pTexture->setSmooth(true);
			rMetaEntity.facetes[0] = pTexture;
		}

		pXMLMetaEntity = pXMLMetaEntity->NextSiblingElement();
	}
}


void Gfx::CStartupPhase::OnLeave()
{
}
