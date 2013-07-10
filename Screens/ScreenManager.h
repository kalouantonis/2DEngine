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

#include "../GameGlobals.h"

class ScreenManager
{
public:
	virtual ~ScreenManager();
	static ScreenManager& GetInstance(void);

	void LoadConfig(const char* filename);
	void Initialize(GameScreen* screen);
	void LoadContent();
	void UnloadContent();
	void Update(float elapsedTime);
	void Draw(sf::RenderTarget& target);
	void Reload(void);

	void AddScreen(GameScreen *screen);

	int GetScreenWidth(void);
	int GetScreenHeight(void);
	void SetScreenWidth(int width);
	void SetScreenHeight(int height);

	GAME_STATE GetGameState();

private:
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	GameScreen *curScreen, *newScreen;

	int ScreenWidth, ScreenHeight;

	FileManager file;
 };

#endif /* SCREENMANAGER_H_ */
