#include "gfx.playPhase.h"
#include "gfx.startupPhase.h"
#include <iostream>
#include <vector>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>

#include <game/game.application.h>
#include <data/data.metaEntitySystem.h>
#include <data/data.entitySystem.h>

namespace Gfx
{
    void CPlayPhase::OnEnter()
    {
		std::cout << "Gfx::PlayPhase::OnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;

	}

    void CPlayPhase::OnRun()
    {
		std::cout << "Gfx::PlayPhase::OnRun" << std::endl;
		std::cout << "------------------------" << std::endl;

		int timer = 0;
   

       /* Game::CApplication& app = Game::CApplication::GetInstance();*/

        // TODO: This needs to be replaced by the actual entity system instead of meta entities
        //Data::CMetaEntitySystem& metaEntitySystem = Data::CMetaEntitySystem::GetInstance();
        CStartupPhase& startupPhase = CStartupPhase :: GetInstance();

        Data::CEntitySystem& entitySystem = Data::CEntitySystem::GetInstance();
        auto entities = entitySystem.GetAllEntities();

        // clear the app.m_window with black color
        startupPhase.window.clear(sf::Color::Black);

        for (auto& entity : entities)
        {
            sf::Texture* texturePtr = static_cast<sf::Texture*>(entity->metaEntity->facetes[0]);

            sf::Sprite sprite;
            sprite.setTexture(*texturePtr);

            sprite.setPosition(entity->position[0], entity->position[1]);
			

            assert(texturePtr != nullptr);

            // factor in the texture size
            float xScale = entity->metaEntity->aabb.GetMax()[0] - entity->metaEntity->aabb.GetMin()[0];
            float yScale = entity->metaEntity->aabb.GetMax()[1] - entity->metaEntity->aabb.GetMin()[1];

            float xSpriteScale = xScale / texturePtr->getSize().x;
            float ySpriteScale = yScale / texturePtr->getSize().y;

            sprite.setScale(xSpriteScale, ySpriteScale);

            

			while (startupPhase.window.isOpen())
			{
				// check all the window's events that were triggered since the last iteration of the loop
				sf::Event event;
				while (startupPhase.window.pollEvent(event))
				{
					// "close requested" event: we close the window
					if (event.type == sf::Event::Closed)
                        startupPhase.window.close();
				}


				// clear the window with selected color -> Background
				//window.clear(sf::Color::Black);

				// draw everything here...
                startupPhase.window.draw(sprite);

				// end the current frame
                startupPhase.window.display();

				timer++;
			}
      
        }

        // end the current frame and display everything drawn
        startupPhase.window.display();

    }

    void CPlayPhase::OnLeave()
    {}

}