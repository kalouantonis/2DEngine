/*
 * SplashScreen.cpp
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
	state = SPLASH;
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::LoadContent()
{
	if(!splashImage.loadFromFile("Resources/splash.png"))
		std::cout << "Could not load splash image from file" << std::endl;


	/*
	splashSprite.setTexture(splashImage);
	splashSprite.setScale((float) SCREEN_WIDTH / splashImage.getSize().x,
			 (float) SCREEN_HEIGHT / splashImage.getSize().y);
			 */

	splashSprite = new sf::Sprite;
	splashSprite->setTexture(splashImage);
	splashSprite->setScale((float) SCREEN_WIDTH / splashImage.getSize().x,
			(float) SCREEN_HEIGHT / splashImage.getSize().y);


	fadeOutAn.LoadContent(splashSprite);

	//keys.push_back(sf::Keyboard::Return);
	keys.push_back(sf::Keyboard::Space);
}

void SplashScreen::UnloadContent()
{
	fadeOutAn.UnloadContent();
	GameScreen::UnloadContent();

	delete splashSprite;
}

void SplashScreen::Update(float elapsedTime)
{
	fadeOutAn.Update(elapsedTime);

	if(input.KeyPressed(keys) || fadeOutAn.IsAnimationDone())
		ScreenManager::GetInstance().AddScreen(new TitleScreen);
}

void SplashScreen::Draw(sf::RenderTarget& target)
{
	fadeOutAn.Draw(target);
}


