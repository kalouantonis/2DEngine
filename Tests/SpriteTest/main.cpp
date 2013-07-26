#include "../../Engine.h"

using namespace SuperEngine;

bool game_preload()
{
    g_pEngine->setAppTitle("Sprite Test");
    g_pEngine->setColorDepth(32);
    g_pEngine->setScreenHeight(600);
    g_pEngine->setScreenWidth(800);
    g_pEngine->setFPS(60);

    return true;
}

Sprite* sprite;

bool game_init()
{
    sprite = new Sprite();

    sprite->setPosition(100, 100);
    sprite->setVelocity(5.0f, 0.0f);
    sprite->setColumns(21);
    sprite->setRows(7);
    sprite->setFrameTimer(false);
    sprite->setTotalFrames(143);
    sprite->loadImage("asteroid_sheet.png", 21, 7);

    return true;
}

void game_update(float elapsedTime)
{
    static float rotation = 1;
    static int alphadir = 1;
    static int alpha = 0;

    //sprite->setColor(sprite->getSprite()->getColor().r,
     //                sprite->getSprite()->getColor().g,
      //               sprite->getSprite()->getColor().b,
        //             alpha);

    alpha += alphadir;

    if(alpha >= 255 || alpha <= 0)
        alphadir *= -1;

    sprite->setScale(2, 2);
    sprite->setRotation(rotation);
    rotation += 1;

    if(sprite->getPosition().x > g_pEngine->getScreenWidth())
        sprite->setPosition(0 - sprite->getFrameSize().x, sprite->getPosition().y);
    else if(sprite->getPosition().x + sprite->getFrameSize().x < 0)
        sprite->setPosition(g_pEngine->getScreenWidth(), sprite->getPosition().y);

    sprite->Move();
}

void game_render()
{
    sprite->Animate();
    //g_pEngine->getDevice()->draw(*sprite->getSprite());
    sprite->Draw();
}

void game_end()
{
    delete sprite;
}
