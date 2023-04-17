#include "gui.playPhase.h"
#include <iostream>

#include <SFML/Graphics.hpp>

#include <graphics/gfx.startupPhase.h>
#include <graphics/gfx.playPhase.h>
#include <data/data.playerSystem.h>
#include <data/data.eventSystem.h>


namespace Gui
{
    void CPlayPhase::OnEnter()
    {

        
    }
    
    static void EventCallBack(Data::CEvent& data) {
        std::cout << "ABC" << std::endl;

    }

    void CPlayPhase::OnRun()
    {
        std::cout << "Gui::PlayPhase::OnRun" << std::endl;
        std::cout << "------------------------" << std::endl;

        Gfx::CStartupPhase& rStartupPhase = Gfx::CStartupPhase::GetInstance();
        Gfx::CPlayPhase& rPlayPhase = Gfx::CPlayPhase::GetInstance();
        Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();
       

        while (rStartupPhase.m_AppWindow.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event Event;
            while (rStartupPhase.m_AppWindow.pollEvent(Event))
            {

                if (Event.type == sf::Event::KeyPressed) {
                    rEventSystem.Register(Data::CEvent::BTypeID(0), &EventCallBack);
                    rEventSystem.FireEvent(0);
                } 

                // "close requested" event: we close the window
                if (Event.type == sf::Event::Closed)
                {
                    rStartupPhase.m_AppWindow.close();
                }
                if (Event.type == sf::Event::Resized)
                {
                    // update the view to the new size of the windowl
                    sf::FloatRect VisibleArea(0.f, 0.f, (float)Event.size.width, (float)Event.size.height);
                    rStartupPhase.m_AppWindow.setView(sf::View(VisibleArea));
                }

                if (Event.type == sf::Event::KeyPressed)
                {

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        std::cout << "Gfx::PlayPhase::KeyPressed left" << std::endl;
                        Data::CPlayerSystem& rPlayerSystem = Data::CPlayerSystem::GetInstance();
                        Data::Entity* pPlayer = rPlayerSystem.GetPlayer();
                        if (pPlayer != nullptr)
                        {
                            pPlayer->position = Core::Float3(pPlayer->position[0] - 2.0f, pPlayer->position[1], pPlayer->position[2]);
                            pPlayer->aabb = Core::CAABB3<float>(
                                Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
                                Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
                            );
                        }
                        rPlayPhase.OnRun();

                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        std::cout << "Gfx::PlayPhase::KeyPressed right" << std::endl;
                        Data::CPlayerSystem& rPlayerSystem = Data::CPlayerSystem::GetInstance();
                        Data::Entity* pPlayer = rPlayerSystem.GetPlayer();
                        if (pPlayer != nullptr)
                        {
                            pPlayer->position = Core::Float3(pPlayer->position[0] + 2.0f, pPlayer->position[1], pPlayer->position[2]);
                            pPlayer->aabb = Core::CAABB3<float>(
                                Core::Float3(pPlayer->position[0], pPlayer->position[1], pPlayer->position[2]),
                                Core::Float3(pPlayer->position[0] + 64, pPlayer->position[1] + 64, pPlayer->position[2])
                            );
                        }
                        rPlayPhase.OnRun();
                    }
                }

            }

        }
            
    }

    void CPlayPhase::OnLeave()
    {}
}