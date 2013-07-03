/*
 * SplashScreen.cpp
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
	id = SPLASH;
}

SplashScreen::~SplashScreen()
{
	// TODO Auto-generated destructor stub
}

void SplashScreen::LoadContent()
{
	if(!font.loadFromFile("Resources/arial.ttf"))
		std::cerr << "Could not find specified font" << std::endl;

	text.setString("Splash Screen");
	text.setFont(font);

	keys.push_back(sf::Keyboard::Return);
	keys.push_back(sf::Keyboard::Space);
}

void SplashScreen::UnloadContent()
{
	GameScreen::UnloadContent();

}

void SplashScreen::Update()
{
	if(input.KeyPressed(keys))
		ScreenManager::GetInstance().AddScreen(new TitleScreen);
}

void SplashScreen::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}

