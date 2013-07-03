/*
 * MenuScreen.h
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#ifndef MENUSCREEN_H_
#define MENUSCREEN_H_

#include "GameScreen.h"
#include "ScreenManager.h"
#include "MainScreen.h"

class MenuScreen: public GameScreen
{
public:
	MenuScreen();
	virtual ~MenuScreen();

	void LoadContent();
	void UnloadContent();
	void Update(float elapsedTime);
	void Draw(sf::RenderTarget& target);

private:
	sf::Text text;
	sf::Font font;
};

#endif /* MENUSCREEN_H_ */
