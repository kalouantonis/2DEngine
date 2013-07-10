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

	virtual void LoadContent(sf::Text* text);
	virtual void LoadContent(sf::Sprite* sprite);

	virtual void UnloadContent();
	virtual void Update(float elapsedTime);
	virtual void Draw(sf::RenderTarget& target);

	bool IsAnimationDone(void);
protected:
	int ScreenWidth, ScreenHeight;

	bool animationDone;

	sf::Text* text;
	sf::Sprite* sprite;

	sf::Transformable transItem;
};

#endif /* ANIMATION_H_ */
