#include <Engine.h>

using namespace SuperEngine;

TextureEmitter* pa;
CircleEmitter* pb;
CircleEmitter* pc;

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

    pa = new TextureEmitter();
    pa->loadImage("particle16.tga");
    pa->setPosition(100, 300);
    pa->setDirection(0);
    pa->setMax(5000);
    //pa->setParticleSize(1.5);
    pa->setScale(0.2f);
    pa->setAlphaRange(100, 255);
    pa->setSpread(30);
    pa->setVelocity(50.f, 50.f);
    pa->setLength(250);

    pb = new CircleEmitter();
    //pb->loadImage("particle16.tga");
    pb->setPosition(300, 100);
    pb->setDirection(180);
    pb->setParticleSize(2);
    pb->setMax(5000);
    pb->setAlphaRange(0, 100);
    pb->setSpread(40);
    pb->setColorRange(200, 0, 0, 255, 10, 10);
    pb->setVelocity(50.f, 50.0f);
    pb->setLength(200);

    pc = new CircleEmitter();
    //pc->loadImage("particle16.tga");
    pc->setPosition(250, 525);
    pc->setDirection(0);
    pc->setParticleSize(1.5);
    pc->setMax(5000);
    pc->setAlphaRange(100, 150);
    pc->setSpread(5);
    pc->setColorRange(0, 0, 200, 10, 10, 255);
    pc->setVelocity(50.f, 50.f);
    pc->setLength(180);

    return true;
}

void game_update(float elapsedTime)
{
    pa->Update(elapsedTime);
    pb->Update(elapsedTime);

    // update circular controller
    float dir = pc->getDirection() + 0.2f;
    pc->setDirection(dir);
    pc->Update(elapsedTime);
}

void game_end()
{
    delete pa;
    delete pb;
    delete pc;
}

void game_render()
{
    pa->Draw();
    pb->Draw();
    pc->Draw();
}
