/*
 * SlideAnimation.cpp
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#include "SlideAnimation.h"

SlideAnimation::SlideAnimation()
	: Animation()
{
	// TODO: Tweak this to perfection
	slideSpeed = 140;
}

SlideAnimation::~SlideAnimation()
{
}

void SlideAnimation::Update(float elapsedTime)
{
	// TODO: Use polymorphism
	if(text)
	{
		text->move(elapsedTime * slideSpeed, 0);

		if(text->getPosition().x > SCREEN_WIDTH)
			animationDone = true;
	}
	else if(sprite)
	{
		sprite->move(elapsedTime * slideSpeed, 0);

		if(sprite->getPosition().x > SCREEN_WIDTH)
			animationDone = true;
	}
}

