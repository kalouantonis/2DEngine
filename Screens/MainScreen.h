/*
 * MainScreen.h
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#ifndef MAINSCREEN_H_
#define MAINSCREEN_H_

#include "GameScreen.h"

class MainScreen: public GameScreen
{
public:
	MainScreen();
	virtual ~MainScreen();

	void LoadContent();
	void UnloadContent();
	void Update();
	void Draw(sf::RenderWindow& window);

private:
	sf::Text text;
	sf::Font font;
};

#endif /* MAINSCREEN_H_ */
