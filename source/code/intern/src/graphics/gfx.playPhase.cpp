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

        CStartupPhase& rStartupPhase = CStartupPhase :: GetInstance();

        Data::CEntitySystem& rEntitySystem = Data::CEntitySystem::GetInstance();
        auto Entities = rEntitySystem.GetAllEntities();

        // clear the app.m_window with black color
        rStartupPhase.m_AppWindow.clear(sf::Color(44,144,193,255));
    

        for (auto& Entity : Entities)
        {
            sf::Texture* pTexture = static_cast<sf::Texture*>(Entity->metaEntity->facetes[0]);

            sf::Sprite Sprite;
            Sprite.setTexture(*pTexture);
            Sprite.setPosition(Entity->position[0], Entity->position[1]);

            if (Entity->metaEntity->name == "dirt") {
                std::cout << "x" << Entity->metaEntity->name << std::endl;
                Sprite.setPosition(Entity->position[0] + 64, Entity->position[1] );
            }
            assert(pTexture != nullptr);

            // factor in the texture size
            float xScale = Entity->metaEntity->aabb.GetMax()[0] - Entity->metaEntity->aabb.GetMin()[0];
            float yScale = Entity->metaEntity->aabb.GetMax()[1] - Entity->metaEntity->aabb.GetMin()[1];

            float xSpriteScale = xScale / pTexture->getSize().x;
            float ySpriteScale = yScale / pTexture->getSize().y;

            Sprite.setScale(xSpriteScale, ySpriteScale);

            // We move the camera/view with the player entity
            if (Entity->metaEntity->name == "player")
            {
                auto& prevSize = rStartupPhase.m_AppWindow.getView().getSize();

                sf::View view(sf::FloatRect(
                    Entity->position[0] - prevSize.x / 2 + 128,
                    Entity->position[1] - prevSize.y / 2 - 64 - 32,
                    prevSize.x,
                    prevSize.y
                ));

                rStartupPhase.m_AppWindow.setView(view);
            }


            rStartupPhase.m_AppWindow.draw(Sprite);

		
      
        }
        rStartupPhase.m_AppWindow.display();

        while (rStartupPhase.m_AppWindow.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event Event;
            while (rStartupPhase.m_AppWindow.pollEvent(Event))
            {
           
				if (Event.type == sf::Event::KeyPressed) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					{
                        std::cout << "pressed" << std::endl;
                    }
                }

                // "close requested" event: we close the window
                if (Event.type == sf::Event::Closed)
                {
                    
                    rStartupPhase.m_AppWindow.close();
				}
                if (Event.type == sf::Event::Resized)
                {
                    // update the view to the new size of the windowl
                    sf::FloatRect visibleArea(0.f, 0.f, (float)Event.size.width, (float)Event.size.height);
                    rStartupPhase.m_AppWindow.setView(sf::View(visibleArea));
                }

                // end the current frame and display everything drawn
             

            }

        }
     
    }

    void CPlayPhase::OnLeave()
    {}

}