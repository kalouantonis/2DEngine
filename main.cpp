/*
 * main.cpp
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Screens/ScreenManager.h"
#include "StateManager.h"

int main(void)
{
	const int FPS = 60;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
			"Dice Roller Test Program");

	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FPS);

	sf::Event event;

	// Timer
	// Tick every 1/FPS of a second and store the time passed for every timer
	// event
	float timerTick = 1.0f / FPS, elapsedTime;
	sf::Clock timer;

	// Game state handler
	StateManager stateManager;

	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			}
		}

		// Handle timer events
		if(timer.getElapsedTime().asSeconds() >= timerTick)
		{
			elapsedTime = timer.restart().asSeconds();
			stateManager.Update(elapsedTime);

			//std::cout << elapsedTime << std::endl;
		}

		stateManager.DrawItems(window);

		window.display();
		window.clear(sf::Color::Black);
	}


	return 0;
}
