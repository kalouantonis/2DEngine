/*
 * SplashScreen.cpp
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#include "SplashScreen.h"

SplashScreen::SplashScreen()
	: GameScreen()
{
	state = SPLASH;
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::LoadContent()
{
	file.LoadContent("Resources/splash.cfg");


	if(!splashImage.loadFromFile(file.GetAttrContents("SPLASH_IMAGE")))
		std::cout << "Could not load splash image from file" << std::endl;

	splashSprite = new sf::Sprite;
	splashSprite->setTexture(splashImage);
	splashSprite->setScale((float)  ScreenWidth / splashImage.getSize().x,
			(float) ScreenHeight / splashImage.getSize().y);

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
	{
		//UnloadContent();
		ChangeScreen(new TitleScreen);
	}
}

void SplashScreen::Draw(sf::RenderTarget& target)
{
	fadeAn.Draw(target);
	//target.draw(*splashSprite);
}


