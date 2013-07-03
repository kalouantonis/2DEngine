/*
 * SplashScreen.h
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#ifndef SPLASHSCREEN_H_
#define SPLASHSCREEN_H_

#include "GameScreen.h"

// TODO: Clean this up when done
#include "TitleScreen.h"
#include "ScreenManager.h"

class SplashScreen: public GameScreen
{
public:
	SplashScreen();
	virtual ~SplashScreen();

	void LoadContent();
	void UnloadContent();
	void Update();
	void Draw(sf::RenderWindow& window);

private:
	sf::Text text;
	sf::Font font;
};

#endif /* SPLASHSCREEN_H_ */
