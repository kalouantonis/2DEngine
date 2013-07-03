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

	void Update(float elapsedTime);
	void Draw(sf::RenderTarget& target);

private:
	float alpha;
	float fadeSpeed;
};

#endif /* FADEANIMATION_H_ */
