/*
 * GameScreen.h
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_

#include <SFML/Graphics.hpp>
#include "../Input/InputManager.h"

#include <iostream>

enum SCREEN_ID { SPLASH, TITLE, MENU, MAIN };

class GameScreen
{
public:
	GameScreen();
	virtual ~GameScreen();

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update();
	virtual void Draw(sf::RenderWindow& window);

	SCREEN_ID GetId();

protected:
	InputManager input;
	std::vector<sf::Keyboard::Key> keys;

	SCREEN_ID id;
};

#endif /* GAMESCREEN_H_ */
