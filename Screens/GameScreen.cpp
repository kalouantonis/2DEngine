/*
 * GameScreen.cpp
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#include "GameScreen.h"

GameScreen::GameScreen()
{
	// TODO Auto-generated constructor stub

}

GameScreen::~GameScreen()
{
	// TODO Auto-generated destructor stub
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
	// Clearing to black... for now
	target.clear(sf::Color(0, 0, 0));
}

GAME_STATE GameScreen::GetGameState()
{
	return state;
}
