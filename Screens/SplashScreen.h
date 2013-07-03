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
#include "Animation/SlideAnimation.h"

class SplashScreen: public GameScreen
{
public:
	SplashScreen();
	virtual ~SplashScreen();

	void LoadContent();
	void UnloadContent();
	void Update(float elapsedTime);
	void Draw(sf::RenderTarget& target);

	GAME_STATE GetGameState();

private:
	sf::Text text;
	sf::Font font;

	SlideAnimation slideAn;
};

#endif /* SPLASHSCREEN_H_ */
