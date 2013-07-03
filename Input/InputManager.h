/*
 * InputManager.h
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include <vector>

#include <SFML/Window/Event.hpp>

typedef sf::Keyboard::Key sfKey;

class InputManager
{
public:
	InputManager();
	virtual ~InputManager();

	void Update();

	bool KeyPressed(sfKey key);
	bool KeyPressed(std::vector<sfKey> keys);

	bool KeyReleased(sfKey key);
	bool KeyReleased(std::vector<sfKey> keys);
};

#endif /* INPUTMANAGER_H_ */
