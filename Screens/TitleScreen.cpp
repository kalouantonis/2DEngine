/*
 * TitleScreen.cpp
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#include "TitleScreen.h"


TitleScreen::TitleScreen()
	: GameScreen()
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

	slideAn.LoadContent(&text);

	keys.push_back(sf::Keyboard::Return);
	//keys.push_back(sf::Keyboard::Space);
}

void TitleScreen::UnloadContent()
{
	slideAn.UnloadContent();

	GameScreen::UnloadContent();

	slideAn.UnloadContent();
}

void TitleScreen::Update(float elapsedTime)
{
	slideAn.Update(elapsedTime);

	if(input.KeyPressed(keys) || slideAn.IsAnimationDone())
	{
		UnloadContent();
		ChangeScreen(new MenuScreen);
	}
}

void TitleScreen::Draw(sf::RenderTarget& target)
{
	slideAn.Draw(target);
}


