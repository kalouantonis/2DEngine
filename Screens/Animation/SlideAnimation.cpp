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
	slideSpeed = 700;

	// In seconds
	waitTime = 3;
	curTime = 0;
	waitDone = false;
}

SlideAnimation::~SlideAnimation()
{
}

void SlideAnimation::Update(float elapsedTime)
{
	// TODO: Use polymorphism
	if(text)
	{

		if(!waitDone)
		{
			curTime += elapsedTime;
			if(curTime >= waitTime)
				waitDone = true;
		}
		else
		{
			text->move(elapsedTime * slideSpeed, 0);

			if(text->getPosition().x > SCREEN_WIDTH)
				animationDone = true;
		}

	}
	else if(sprite)
	{
		if(!waitDone)
		{
			curTime += elapsedTime;
			if(curTime >= waitTime)
				waitDone = true;
		}
		else
		{
			sprite->move(elapsedTime * slideSpeed, 0);

			if(sprite->getPosition().x > SCREEN_WIDTH)
				animationDone = true;
		}
	}
}

