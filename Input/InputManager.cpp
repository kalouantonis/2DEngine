/*
 * InputManager.cpp
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#include "InputManager.h"

InputManager::InputManager()
{
	// TODO Auto-generated constructor stub

}

InputManager::~InputManager()
{
	// TODO Auto-generated destructor stub
}

void InputManager::Update()
{

}

bool InputManager::KeyPressed(sfKey key)
{
	if(sf::Keyboard::isKeyPressed(key))
		return true;

	return false;
}

bool InputManager::KeyPressed(std::vector<sfKey> keys)
{
	bool foundFlag = false;

	for(std::vector<sfKey>::const_iterator i = keys.begin(); i != keys.end(); i++)
	{
		if(!KeyPressed(*i))
			continue;
		else
			foundFlag = true;
	}

	return foundFlag;
}

bool InputManager::KeyReleased(sfKey key)
{
	return !KeyPressed(key);
}

bool InputManager::KeyReleased(std::vector<sfKey> keys)
{
	return !KeyPressed(keys);
}

bool InputManager::KeyDown(sfKey key)
{
	return KeyPressed(key);
}

bool InputManager::KeyDown(std::vector<sfKey> keys)
{
	return KeyPressed(keys);
}

