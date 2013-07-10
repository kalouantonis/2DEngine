/*
 * Animation.cpp
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#include "Animation.h"
#include "../ScreenManager.h"

Animation::Animation()
{
	ScreenHeight = ScreenManager::GetInstance().GetScreenHeight();
	ScreenWidth = ScreenManager::GetInstance().GetScreenWidth();

	animationDone = false;

	text = NULL;
	sprite = NULL;
}

Animation::~Animation()
{
}


void Animation::LoadContent(sf::Sprite *sprite)
{
	this->sprite = sprite;
}

void Animation::LoadContent(sf::Text* text)
{
	this->text = text;
}

void Animation::UnloadContent()
{
	animationDone = true;
	sprite = NULL;
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
	if(text)
		target.draw(*text);
	else if(sprite)
		target.draw(*sprite);
}

