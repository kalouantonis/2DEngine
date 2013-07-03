/*
 * FadeAnimation.h
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#ifndef FADEANIMATION_H_
#define FADEANIMATION_H_

#include "Animation.h"

class FadeAnimation: public Animation
{
public:
	FadeAnimation();
	virtual ~FadeAnimation();

	void LoadContent(sf::Drawable* drawItem);
	void UnloadContent();
	void Update(float elapsedTime);
	void Draw(sf::RenderTarget& target);

	/**
	 * I expect the caller to handle the screen clearing and such
	 * this class will not handle that
	 *
	 * @return int
	 */
	int GetAlpha(void);

private:
	// Alpha from 0 - 255
	int alpha;
};

#endif /* FADEANIMATION_H_ */
