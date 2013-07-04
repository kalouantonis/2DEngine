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
#include "../FileManager.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


class ScreenManager
{
public:
	virtual ~ScreenManager();
	static ScreenManager& GetInstance(void);

	void Initialize(GameScreen* screen);
	void LoadContent();
	void UnloadContent();
	void Update(float elapsedTime);
	void Draw(sf::RenderTarget& target);

	void AddScreen(GameScreen *screen);

	GAME_STATE GetGameState();

private:
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	GameScreen *curScreen, *newScreen;

	FileManager file;
	std::vector<std::vector<std::string> > attributes;
	std::vector<std::vector<std::string> > contents;
 };

#endif /* SCREENMANAGER_H_ */
