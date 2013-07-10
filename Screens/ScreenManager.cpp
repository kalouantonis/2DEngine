/*
 * ScreenManager.cpp
 *
 *  Created on: Jul 2, 2013
 *      Author: slacker
 */

#include "ScreenManager.h"
#include "../Utils/ConvertTypes.h"

ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager instance;

	return instance;
}

ScreenManager::ScreenManager()
{
	curScreen = NULL;
	newScreen = NULL;

	// Default screen height, will be used if no config is found
	ScreenWidth = 800;
	ScreenHeight = 600;
}

ScreenManager::~ScreenManager()
{
	delete curScreen;
}

void ScreenManager::LoadConfig(const char* filename)
{
	file.LoadContent(filename);

	// Load screen width and height from config
	std::string width = file.GetAttrContents("WIDTH");
	std::string height = file.GetAttrContents("HEIGHT");

	if(width.empty() || height.empty())
	{
		std::cerr << "Could not load width and height from: " << filename
					<< "\nWill use 800x600"
					<<std::endl;
		return;
	}

	// Convert the strings to ints, so that you know, i can use them
	StrToInt(ScreenWidth, width);
	StrToInt(ScreenHeight, height);

}

void ScreenManager::Initialize(GameScreen* screen)
{
	curScreen = screen;
}

void ScreenManager::LoadContent()
{
	curScreen->LoadContent();
}

void ScreenManager::UnloadContent()
{
	curScreen->UnloadContent();
}

void ScreenManager::Update(float elapsedTime)
{
	curScreen->Update(elapsedTime);
}

void ScreenManager::Draw(sf::RenderTarget& target)
{
	curScreen->Draw(target);
}

void ScreenManager::AddScreen(GameScreen* screen)
{
	curScreen->UnloadContent();
	delete curScreen;

	curScreen = screen;
	curScreen->LoadContent();
}

GAME_STATE ScreenManager::GetGameState()
{
	return curScreen->GetGameState();
}

void ScreenManager::Reload()
{
	UnloadContent();
	LoadContent();
}

int ScreenManager::GetScreenWidth()
{
	return ScreenWidth;
}

int ScreenManager::GetScreenHeight()
{
	return ScreenHeight;
}

void ScreenManager::SetScreenWidth(int width)
{
	ScreenWidth = width;
	// Will need to reload current screen
	Reload();
}

void ScreenManager::SetScreenHeight(int height)
{
	ScreenHeight = height;

	Reload();
}



