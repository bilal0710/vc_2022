#include "gfx.playPhase.h"
#include "gfx.startupPhase.h"
#include <iostream>
#include <vector>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>

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
   
       /* Game::CApplication& app = Game::CApplication::GetInstance();*/

        // TODO: This needs to be replaced by the actual entity system instead of meta entities
        //Data::CMetaEntitySystem& metaEntitySystem = Data::CMetaEntitySystem::GetInstance();
        CStartupPhase& startupPhase = CStartupPhase :: GetInstance();

        Data::CEntitySystem& entitySystem = Data::CEntitySystem::GetInstance();
        auto entities = entitySystem.GetAllEntities();

        // clear the app.m_window with black color
        startupPhase.window.clear(sf::Color::Black);
        int counter = 0;

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

            startupPhase.window.draw(sprite);

		
      
        }
        startupPhase.window.display();

        while (startupPhase.window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (startupPhase.window.pollEvent(event))
            {
           
				if (event.type == sf::Event::KeyPressed) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					{
                        std::cout << "pressed" << std::endl;
                    }
                }

                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                {
                    
                    startupPhase.window.close();
				}
                if (event.type == sf::Event::Resized)
                {
                    // update the view to the new size of the windowl
                    sf::FloatRect visibleArea(0.f, 0.f, (float)event.size.width, (float)event.size.height);
                    startupPhase.window.setView(sf::View(visibleArea));
                }

                // end the current frame and display everything drawn
             

            }

        }
     
    }

    void CPlayPhase::OnLeave()
    {}

}