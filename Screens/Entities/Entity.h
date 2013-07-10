/*
 * Entity.h
 *
 *  Created on: Jul 10, 2013
 *      Author: slacker
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics/RenderTarget.hpp>
#include "../../Input/InputManager.h"
#include "Component.h"

#include <vector>

class Entity
{
public:
	Entity();

	// Using pointer for dynamic binding capabilities
	virtual void AddComponent(Component*);

	virtual void Update(float elapsedTime);
	virtual void Draw(sf::RenderTarget& target);

	virtual ~Entity();

private:
	std::vector<Component*> compVec;
};

#endif /* ENTITY_H_ */
