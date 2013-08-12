#include <Engine.h>

using namespace SuperEngine;

bool game_preload()
{
    g_pEngine->setAppTitle("Sprite Test");
    g_pEngine->setColorDepth(32);
    g_pEngine->setScreenHeight(600);
    g_pEngine->setScreenWidth(800);
    g_pEngine->setFPS(30);

    return true;
}

Sprite* sprite;
Sprite* explosion;
Sprite* sprite2;

bool game_init()
{
    sprite = new Sprite();

    sprite->setFrameTimer(true);
//    sprite->setMoveTimer(false);
    sprite->setFrameDelay(16);
    sprite->setPosition(100, 100);
    sprite->setVelocity(100.0f, 0.0f);
    sprite->loadImage("asteroid_sheet.png", 21, 7);
    sprite->setTotalFrames(143);

    sprite2 = new Sprite();
    sprite2->setFrameTimer(true);
//    sprite->setMoveTimer(false);
    sprite2->setFrameDelay(16);
    sprite2->setPosition(100, 250);
    sprite2->setVelocity(150.0f, 0.0f);
    sprite2->loadImage("asteroid_sheet.png", 21, 7);
    sprite2->setTotalFrames(143);


    explosion = new Sprite();

    explosion->setFrameTimer(true);
    explosion->setFrameDelay(16);
//    explosion->setMoveTimer(false);
    explosion->setPosition(400, 400);
    explosion->setVelocity(100.0f, 0.0f);
    explosion->loadImage("explosions.png", 8, 6);
    //explosion->setTotalFrames(46);
    explosion->setScale(2.0f, 2.0f);

    return true;
}

void game_update(float elapsedTime)
{
    static float rotation = 0.1;
    static int alphadir = 1;
    static int alpha = 0;

//    sprite->setColor(sprite->getSprite()->getColor().r,
//                     sprite->getSprite()->getColor().g,
//                     sprite->getSprite()->getColor().b,
//                     alpha);

    alpha += alphadir;

    if(alpha >= 255 || alpha <= 0)
        alphadir *= -1;

    //sprite->setScale(2);
    sprite->setRotation(rotation);

    if(sprite->getPosition().x > g_pEngine->getScreenWidth())
    {
        sprite->setPosition(0 - sprite->getFrameSize().x, sprite->getPosition().y);
    }

    if(explosion->getPosition().x > g_pEngine->getScreenWidth())
    {
        explosion->setPosition(0 - explosion->getFrameSize().x, explosion->getPosition().y);
    }

    sprite2->setRotation(rotation);
    rotation += 0.1;

    if(sprite2->getPosition().x > g_pEngine->getScreenWidth())
    {
        sprite2->setPosition(0 - sprite2->getFrameSize().x, sprite2->getPosition().y);
    }

    if(explosion->getPosition().x > g_pEngine->getScreenWidth())
    {
        explosion->setPosition(0 - explosion->getFrameSize().x, explosion->getPosition().y);
    }

    sprite->Move(elapsedTime);
    sprite2->Move(elapsedTime);
    explosion->Move(elapsedTime);
}

void game_render()
{
    sprite->Animate();
    //g_pEngine->getDevice()->draw(*sprite->getSprite());
    sprite->Draw();

    sprite2->Animate();
    sprite2->Draw();

    explosion->Animate();
    explosion->Draw();
}

void game_end()
{
    delete sprite2;
    delete sprite;
    delete explosion;
}
