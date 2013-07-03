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
	// TODO Auto-generated destructor stub
}

void SplashScreen::LoadContent()
{
	if(!font.loadFromFile("Resources/arial.ttf"))
		std::cerr << "Could not find specified font" << std::endl;

	text = new sf::Text;
	text->setString("Splash Screen");
	text->setFont(font);

	fadeAn.LoadContent(text);

	//keys.push_back(sf::Keyboard::Return);
	keys.push_back(sf::Keyboard::Space);
}

void SplashScreen::UnloadContent()
{
	GameScreen::UnloadContent();

	// Avoids errors after deletion of text below
	fadeAn.UnloadContent();

	// Check for leaks
	delete text;
}

void SplashScreen::Update(float elapsedTime)
{
	fadeAn.Update(elapsedTime);

	if(input.KeyPressed(keys) || fadeAn.IsAnimationDone())
		ScreenManager::GetInstance().AddScreen(new TitleScreen);
}

void SplashScreen::Draw(sf::RenderTarget& target)
{
	target.clear(sf::Color(0, 0, 0, fadeAn.GetAlpha()));
	fadeAn.Draw(target);
}


