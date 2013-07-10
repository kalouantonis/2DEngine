/*
 * MenuScreen.cpp
 *
 *  Created on: 3 Jul 2013
 *      Author: slacker
 */

#include "MenuScreen.h"

MenuScreen::MenuScreen()
	: GameScreen()
{
	state = MENU;
}

MenuScreen::~MenuScreen()
{

}

void MenuScreen::LoadContent()
{
	// TODO: Fix this to grab fonts from a config
	if(!font.loadFromFile("Resources/arial.ttf"))
		std::cerr << "Could not load specified font" << std::endl;

	text.setString("Menu Screen");
	text.setFont(font);

	// Allowed keys to use for switching screens
	keys.push_back(sf::Keyboard::Return);
	//keys.push_back(sf::Keyboard::Space);
}


void MenuScreen::UnloadContent()
{
	GameScreen::UnloadContent();
}

void MenuScreen::Update(float elapsedTime)
{
	if(input.KeyPressed(keys))
		ChangeScreen(new MainScreen);
}

void MenuScreen::Draw(sf::RenderTarget& target)
{
	GameScreen::Draw(target);
	target.draw(text);

}



