/*
 * FadeAnimation.cpp
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#include "FadeAnimation.h"

FadeAnimation::FadeAnimation()
{
}

FadeAnimation::~FadeAnimation()
{
	// TODO Auto-generated destructor stub
}

void FadeAnimation::LoadContent(sf::Drawable* drawItem)
{
	Animation::LoadContent(drawItem);

	alpha = 0;
}

void FadeAnimation::UnloadContent()
{
	Animation::UnloadContent();
}

void FadeAnimation::Update(float elapsedTime)
{
	// Just increments the alpha every cicle,
	// should be dictated by the caller
	if(alpha < 255)
		alpha += 1.0f * elapsedTime;
}

void FadeAnimation::Draw(sf::RenderTarget& target)
{
	Animation::Draw(target);
}

int FadeAnimation::GetAlpha()
{
	return alpha;
}
