/*
 * TitleScreen.cpp
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#include "TitleScreen.h"


TitleScreen::TitleScreen()
{
	state = TITLE;
}

TitleScreen::~TitleScreen()
{
	// TODO Auto-generated destructor stub
}

void TitleScreen::LoadContent()
{
	if(!font.loadFromFile("Resources/arial.ttf"))
		std::cerr << "Could not find specified font" << std::endl;

	text.setString("Title Screen");
	text.setFont(font);

	keys.push_back(sf::Keyboard::Return);
	//keys.push_back(sf::Keyboard::Space);
}

void TitleScreen::UnloadContent()
{
	GameScreen::UnloadContent();

}

void TitleScreen::Update(float elapsedTime)
{
	if(input.KeyPressed(keys))
		ScreenManager::GetInstance().AddScreen(new MenuScreen);
}

void TitleScreen::Draw(sf::RenderTarget& target)
{
	GameScreen::Draw(target);
	target.draw(text);
}


