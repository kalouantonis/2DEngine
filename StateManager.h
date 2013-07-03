/*
 * StateManager.h
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_

#include "Screens/ScreenManager.h"


/**
 * Will handle all game states
 */

class StateManager
{
public:
	StateManager();
	virtual ~StateManager();

	void Update(float elapsedTime);
	void DrawItems(sf::RenderTarget& target);
};

#endif /* STATEMANAGER_H_ */
