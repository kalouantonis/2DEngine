#include "../../Engine.h"

using namespace SuperEngine;

ParticleController* pa;
ParticleController* pb;
ParticleController* pc;
ParticleController* pd;
ParticleController* pe;

bool game_preload()
{
    g_pEngine->setAppTitle("PARTICLE TEST");
    g_pEngine->setFullscreen(false);
    g_pEngine->setScreenWidth(1024);
    g_pEngine->setScreenHeight(768);
    g_pEngine->setColorDepth(32);

    return true;
}

bool game_init()
{
    g_pEngine->setMaximizeProcessor(true);

    pa = new ParticleController();
    pa->loadImage("particle16.tga");
    pa->setPosition(100, 300);
    pa->setDirection(0);
    pa->setMax(500);
    pa->setAlphaRange(100, 255);
    pa->setSpread(30);
    pa->setVelocity(2.0);
    pa->setLength(250);

    pb = new ParticleController();
    pb->loadImage("particle16.tga");
    pb->setPosition(300, 100);
    pb->setDirection(180);
    pb->setScale(0.6);
    pb->setMax(500);
    pb->setAlphaRange(0, 100);
    pb->setSpread(40);
    pb->setColorRange(200, 0, 0, 255, 10, 10);
    pb->setVelocity(2.0);
    pb->setLength(200);

    pc = new ParticleController();
    pc->loadImage("particle16.tga");
    pc->setPosition(250, 525);
    pc->setDirection(0);
    pc->setScale(0.5);
    pc->setMax(2000);
    pc->setAlphaRange(100, 150);
    pc->setSpread(5);
    pc->setColorRange(0, 0, 200, 10, 10, 255);
    pc->setVelocity(0.2);
    pc->setLength(180);

    return true;
}

void game_update(float elapsedTime)
{
    pa->Update();
    pb->Update();

    // update circular controller
    float dir = pc->getDirection() + 0.2f;
    pc->setDirection(dir);
    pc->Update();
}

void game_end()
{
    delete pa;
    delete pb;
    delete pc;
}

void game_render_2d()
{
    pa->Draw();
    pb->Draw();
    pc->Draw();
}
