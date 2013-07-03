/*
 * ScreenManager.h
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#ifndef SCREENMANAGER_H_
#define SCREENMANAGER_H_

#include "GameScreen.h"
#include "SplashScreen.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


class ScreenManager
{
public:
	virtual ~ScreenManager();
	static ScreenManager& GetInstance(void);

	void Initialize();
	void LoadContent();
	void UnloadContent();
	void Update();
	void Draw(sf::RenderWindow& window);

	void AddScreen(GameScreen *screen);

	SCREEN_ID GetScreenId();

private:
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	GameScreen *curScreen, *newScreen;
};

#endif /* SCREENMANAGER_H_ */
