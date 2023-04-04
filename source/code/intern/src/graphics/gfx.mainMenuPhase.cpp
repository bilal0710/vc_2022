#include "gfx.mainMenuPhase.h"
#include "gfx.startupPhase.h"
#include <iostream>

#include <data/data.eventSystem.h>

namespace Gfx
{
    void CMainMenuPhase::OnEnter()
    {
        std::cout << "Gfx::MainMenuPhase::OnEnter" << std::endl;
        

    }
    static void EventCallBack(Data::CEvent& data) {
        std::cout << "ABC" << std::endl;

    }

    void CMainMenuPhase::OnRun()
    {
        std::cout << "Gfx::MainMenuPhase::OnRun" << std::endl;
        CStartupPhase& rStartupPhase = CStartupPhase::GetInstance();
        Data::CEventSystem& rEventSystem = Data::CEventSystem::GetInstance();

        rStartupPhase.m_AppWindow.clear(sf::Color::Red);
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
                        rEventSystem.Register(Data::CEvent::BTypeID(0), &EventCallBack);
                        rEventSystem.FireEvent(0);
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
                    sf::FloatRect VisibleArea(0.f, 0.f, (float)Event.size.width, (float)Event.size.height);
                    rStartupPhase.m_AppWindow.setView(sf::View(VisibleArea));
                }

            }

        }

    }

    void CMainMenuPhase::OnLeave()
    {}
}