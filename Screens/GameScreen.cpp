/*
 * GameScreen.cpp
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#include "GameScreen.h"
#include "ScreenManager.h"

GameScreen::GameScreen()
{
	ScreenHeight = ScreenManager::GetInstance().GetScreenHeight();
	ScreenWidth = ScreenManager::GetInstance().GetScreenWidth();
}

GameScreen::~GameScreen()
{
}

void GameScreen::ChangeScreen(GameScreen* screen)
{
	ScreenManager::GetInstance().AddScreen(screen);
}

void GameScreen::LoadContent()
{
}

void GameScreen::UnloadContent()
{
	keys.clear();
}

void GameScreen::Update(float elapsedTime)
{

}

void GameScreen::Draw(sf::RenderTarget& target)
{
}

GAME_STATE GameScreen::GetGameState()
{
	return state;
}
