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

	text.setString("Splash Screen");
	text.setFont(font);

	slideAn.LoadContent(&text);

	//keys.push_back(sf::Keyboard::Return);
	keys.push_back(sf::Keyboard::Space);
}

void SplashScreen::UnloadContent()
{
	slideAn.UnloadContent();
	GameScreen::UnloadContent();
}

void SplashScreen::Update(float elapsedTime)
{
	slideAn.Update(elapsedTime);

	if(input.KeyPressed(keys) || slideAn.IsAnimationDone())
		ScreenManager::GetInstance().AddScreen(new TitleScreen);
}

void SplashScreen::Draw(sf::RenderTarget& target)
{
	slideAn.Draw(target);
}


