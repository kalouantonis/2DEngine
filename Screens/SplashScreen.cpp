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


	splashSprite = new sf::Sprite;
	splashSprite->setTexture(splashImage);
	splashSprite->setScale((float) SCREEN_WIDTH / splashImage.getSize().x,
			(float) SCREEN_HEIGHT / splashImage.getSize().y);


	fadeAn.LoadContent(splashSprite);

	//keys.push_back(sf::Keyboard::Return);
	keys.push_back(sf::Keyboard::Space);
}

void SplashScreen::UnloadContent()
{
	fadeAn.UnloadContent();
	GameScreen::UnloadContent();

	delete splashSprite;
}

void SplashScreen::Update(float elapsedTime)
{
	fadeAn.Update(elapsedTime);

	if(input.KeyPressed(keys) || fadeAn.IsAnimationDone())
		ScreenManager::GetInstance().AddScreen(new TitleScreen);
}

void SplashScreen::Draw(sf::RenderTarget& target)
{
	fadeAn.Draw(target);
}


