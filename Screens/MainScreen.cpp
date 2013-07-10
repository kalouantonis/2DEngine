/*
 * MainScreen.cpp
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#include "MainScreen.h"

MainScreen::MainScreen()
	: GameScreen()
{
	state = PLAY;
}

MainScreen::~MainScreen()
{
}

void MainScreen::LoadContent()
{
	// TODO: Fix this to grab fonts from a config
	if(!font.loadFromFile("Resources/arial.ttf"))
		std::cerr << "Could not load specified font" << std::endl;

	text.setString("Main Screen");
	text.setFont(font);

	// Allowed keys to use for switching screens
	keys.push_back(sf::Keyboard::Return);
	keys.push_back(sf::Keyboard::Space);
}


void MainScreen::UnloadContent()
{
	GameScreen::UnloadContent();
}

void MainScreen::Update(float elapsedTime)
{
}

void MainScreen::Draw(sf::RenderTarget& target)
{
	GameScreen::Draw(target);
	target.draw(text);

}



