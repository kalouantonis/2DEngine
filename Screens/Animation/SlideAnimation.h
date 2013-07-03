/*
 * SlideAnimation.h
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#ifndef SLIDEANIMATION_H_
#define SLIDEANIMATION_H_

#include "Animation.h"

class SlideAnimation: public Animation
{
public:
	SlideAnimation();

	void Update(float elapsedTime);

	virtual ~SlideAnimation();

private:
	float slideSpeed;
};

#endif /* SLIDEANIMATION_H_ */
