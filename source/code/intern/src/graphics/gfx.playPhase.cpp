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
#include <data/data.playerSystem.h>

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
                std::cout << "player" << std::endl;
              /*  auto& AppWindowSize = rStartupPhase.m_AppWindow.getView().getSize();

                sf::View view(sf::FloatRect(
                    Entity->position[0] - (AppWindowSize.x / 2) + 128,
                    Entity->position[1] - (AppWindowSize.y / 2) - 128 - 64,
                    AppWindowSize.x,
                    AppWindowSize.y
                ));

                rStartupPhase.m_AppWindow.setView(view);*/
            }

            rStartupPhase.m_AppWindow.draw(Sprite);
        }
        rStartupPhase.m_AppWindow.display();

     
     
    }

    void CPlayPhase::OnLeave()
    {}

}