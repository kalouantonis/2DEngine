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
	curScreen = NULL;
	newScreen = NULL;
}

ScreenManager::~ScreenManager()
{
	delete curScreen;
}

void ScreenManager::Initialize(GameScreen* screen)
{
	curScreen = screen;
	file.LoadContent("test.cme", attributes, contents);
}

void ScreenManager::LoadContent()
{
	curScreen->LoadContent();
}

void ScreenManager::UnloadContent()
{
	curScreen->UnloadContent();
}

void ScreenManager::Update(float elapsedTime)
{
	curScreen->Update(elapsedTime);
}

void ScreenManager::Draw(sf::RenderTarget& target)
{
	curScreen->Draw(target);
}

void ScreenManager::AddScreen(GameScreen* screen)
{
	curScreen->UnloadContent();
	delete curScreen;

	curScreen = screen;
	curScreen->LoadContent();
}

GAME_STATE ScreenManager::GetGameState()
{
	return curScreen->GetGameState();
}

