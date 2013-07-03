/*
 * FadeAnimation.cpp
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#include "FadeAnimation.h"

FadeAnimation::FadeAnimation()
	: Animation()
{
	alpha = 0;

	fadeSpeed = 100;
}

FadeAnimation::~FadeAnimation()
{
	// TODO Auto-generated destructor stub
}

void FadeAnimation::Update(float elapsedTime)
{
	alpha += elapsedTime * fadeSpeed;

	if(alpha >= 255)
		fadeSpeed *= -1;
	else if(alpha <= 0)
		animationDone = true;
}

void FadeAnimation::Draw(sf::RenderTarget& target)
{
	if(text)
		text->setColor(sf::Color(text->getColor().r, text->getColor().g,
				text->getColor().b, alpha));
	else if(sprite)
		sprite->setColor(sf::Color(sprite->getColor().r, sprite->getColor().g,
				sprite->getColor().b, alpha));

	Animation::Draw(target);
}

