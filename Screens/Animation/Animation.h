/*
 * Animation.h
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	virtual ~Animation();

	virtual void LoadContent(sf::Drawable* drawItem);
	virtual void UnloadContent();
	virtual void Update(float elapsedTime);
	virtual void Draw(sf::RenderTarget& target);

	bool IsAnimationDone(void);
protected:
	bool animationDone;

	sf::Drawable* drawItem;
};

#endif /* ANIMATION_H_ */
