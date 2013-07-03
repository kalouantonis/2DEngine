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

enum GAME_STATE { SPLASH, TITLE, MENU, PLAY, PAUSE };

class GameScreen
{
public:
	GameScreen();
	virtual ~GameScreen();

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update(float elapsedTime);
	virtual void Draw(sf::RenderTarget& target);

	GAME_STATE GetGameState();

protected:
	InputManager input;
	std::vector<sf::Keyboard::Key> keys;

	GAME_STATE state;
};

#endif /* GAMESCREEN_H_ */
