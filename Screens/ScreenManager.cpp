/*
 * ScreenManager.cpp
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#include "ScreenManager.h"

ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager instance;

	return instance;
}

ScreenManager::ScreenManager()
{

}

ScreenManager::~ScreenManager()
{
	delete curScreen;
}

void ScreenManager::Initialize()
{
	curScreen = new SplashScreen;
}

void ScreenManager::LoadContent()
{
	curScreen->LoadContent();
}

void ScreenManager::UnloadContent()
{
	curScreen->UnloadContent();
}

void ScreenManager::Update()
{
	curScreen->Update();
}

void ScreenManager::Draw(sf::RenderWindow& window)
{
	curScreen->Draw(window);
}

void ScreenManager::AddScreen(GameScreen* screen)
{
	curScreen->UnloadContent();
	delete curScreen;

	curScreen = screen;
	curScreen->LoadContent();
}

SCREEN_ID ScreenManager::GetScreenId()
{
	return curScreen->GetId();
}

