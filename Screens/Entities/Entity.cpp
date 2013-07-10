/*
 * Entity.cpp
 *
 *  Created on: Jul 10, 2013
 *      Author: slacker
 */

#include "Entity.h"

Entity::Entity()
{
	// TODO Auto-generated constructor stub

}

Entity::~Entity()
{
	// TODO Auto-generated destructor stub
}

void Entity::AddComponent(Component* comp)
{
	compVec.push_back(comp);
}

void Entity::Update(float elapsedTime)
{
	for(std::vector<Component*>::const_iterator i = compVec.begin();
			i != compVec.end(); i++)
		(*i)->Exec(elapsedTime);
}

void Entity::Draw(sf::RenderTarget& target)
{
}
