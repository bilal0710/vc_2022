#include "game.startupPhase.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../data/data.startupPhase.h"
#include "../graphics/gfx.startupPhase.h"


namespace Game
{
	int StartupPhase::InternOnEnter()
	{
		std::cout << "StartupPhase::InternOnEnter" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}

	int StartupPhase::InternOnRun()
	{
		std::cout << "StartupPhase::InternOnRun counter= " << counter << std::endl;
		std::cout << "------------------------" << std::endl;

		Data::StartupPhase::GetInstance().OnEnter();
		
		counter++;
		

		if (counter > 4)
		{
			counter = 0;
			drowShapes();
			return Type::MAIN_MENU;
		}

		return Type::STARTUP;
	}

	int StartupPhase::InternOnLeave()
	{
		std::cout << "StartupPhase::InternOnLeave" << std::endl;
		std::cout << "------------------------" << std::endl;
		return 0;
	}

	void StartupPhase::drowShapes() {
		int timer = 0;

		// create the window
		sf::RenderWindow window(sf::VideoMode(1200, 900), "Bilal Alnaani Application");
		sf::CircleShape shape(200.f);

		// define an octagon
		sf::CircleShape octagon(80.f, 8);

		shape.setFillColor(sf::Color(150, 50, 25));
		octagon.setFillColor(sf::Color::Cyan);

		// set a 10-pixel wide orange outline
		shape.setOutlineThickness(10.f);
		shape.setOutlineColor(sf::Color(250, 150, 100));

		// set the absolute position of the octagon
		octagon.setPosition(100.f, 100.f);

		// run the program as long as the window is open
		while (timer < 2000)
		{
			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event event;
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == sf::Event::Closed)
					window.close();
			}


			// clear the window with selected color -> Background
			window.clear(sf::Color::Black);

			// draw everything here...
			window.draw(shape);
			window.draw(octagon);

			// end the current frame
			window.display();

			timer++;
		}
	}
}
