/*
 * Component.h
 *
 *  Created on: Jul 10, 2013
 *      Author: slacker
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

class Component
{
public:
	Component();

	virtual void Exec(float elapsedTime);

	virtual ~Component();
};

#endif /* COMPONENT_H_ */
