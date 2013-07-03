/*
 * TitleScreen.h
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#ifndef TITLESCREEN_H_
#define TITLESCREEN_H_

#include "GameScreen.h"
#include "MenuScreen.h"
#include "Animation/SlideAnimation.h"

#include "ScreenManager.h"

class TitleScreen: public GameScreen
{
public:
	TitleScreen();
	virtual ~TitleScreen();

	void LoadContent();
	void UnloadContent();
	void Update(float elapsedTime);
	void Draw(sf::RenderTarget& target);

private:
	sf::Text text;
	sf::Font font;

	SlideAnimation slideAn;
};

#endif /* TITLESCREEN_H_ */
