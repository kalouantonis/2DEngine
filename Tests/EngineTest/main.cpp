#include <iostream>
#include "../Engine/Engine.h"

static sf::RectangleShape r;

sf::Color color;

bool game_preload()
{
    g_pEngine->setAppTitle("Test");
    g_pEngine->setScreenHeight(600);
    g_pEngine->setScreenWidth(800);
    g_pEngine->setColorDepth(32);
    g_pEngine->setFullscreen(false);
    g_pEngine->setFPS(60);

    return true;
}

bool game_init()
{
     r.setPosition(100, 100);
    r.setFillColor(sf::Color(255, 255, 255));
    r.setSize(sf::Vector2f(20, 20));
    color = sf::Color::White;


    return true;
}

int moveDir = 1;

void game_update(float elapsedTime)
{
    static float moveSpeed = 100.0f;

    color.a += 1;
    r.setFillColor(color);

    if(r.getPosition().x + r.getSize().x > g_pEngine->getScreenWidth() ||
        r.getPosition().x < 0)
    {
        moveDir *= -1;
        moveSpeed += 1;
    }

    r.move(moveSpeed * elapsedTime * moveDir, 0);
}

void game_render_2d()
{

    g_pEngine->getDevice()->draw(r);
}


//void game_render_3d()
//{
    // This wont be done directly!
    //g_pEngine->StartGL(TRIANGLE);
    //g_pEngine->EndGL();
//}

void game_end() {}
