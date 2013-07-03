/*
 * Animation.cpp
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#include "Animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
	// TODO Auto-generated destructor stub
}

void Animation::LoadContent(sf::Drawable* drawItem)
{
	animationDone = false;

	this->drawItem = drawItem;
}

void Animation::UnloadContent()
{
	animationDone = true;
}

bool Animation::IsAnimationDone()
{
	return animationDone;
}

void Animation::Update(float elaspedTime)
{

}
void Animation::Draw(sf::RenderTarget& target)
{
	target.draw(*drawItem);
}

