/*
 * main.cpp
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Screens/ScreenManager.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
			"Dice Roller Test Program");

	sf::Event event;

	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().LoadContent();

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

		ScreenManager::GetInstance().Update();
		ScreenManager::GetInstance().Draw(window);

		window.display();
		window.clear(sf::Color::Black);
	}

	return 0;
}
