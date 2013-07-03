/*
 * StateManager.cpp
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#include "StateManager.h"

StateManager::StateManager()
{
	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().LoadContent();
}

StateManager::~StateManager()
{
	// TODO Auto-generated destructor stub
}

void StateManager::Update(float elapsedTime)
{
	switch(ScreenManager::GetInstance().GetGameState())
	{
	case SPLASH:
		// Purposely falling through, for now
	case TITLE:
		ScreenManager::GetInstance().Update(elapsedTime);
		break;
	case MENU:
		break;
	case PLAY:
		break;
	case PAUSE:
		break;
	}
}

void StateManager::DrawItems(sf::RenderTarget& target)
{
	ScreenManager::GetInstance().Draw(target);
}
