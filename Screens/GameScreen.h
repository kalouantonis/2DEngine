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
#include "../FileManager.h"
#include "../GameGlobals.h"

#include <iostream>

class GameScreen
{
public:
	GameScreen();
	virtual ~GameScreen();

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update(float elapsedTime);
	virtual void Draw(sf::RenderTarget& target);
	void ChangeScreen(GameScreen* screen);

	GAME_STATE GetGameState();

protected:
	InputManager input;
	std::vector<sf::Keyboard::Key> keys;

	FileManager file;

	GAME_STATE state;
	int ScreenWidth, ScreenHeight;
};

#endif /* GAMESCREEN_H_ */
