#include <Engine.h>

using namespace SuperEngine;

bool game_preload()
{
    return true;
}

DrawableGroup group;

bool game_init()
{
    Sprite* s = new Sprite();
    s->loadImage("asteroid_sheet.png", 21, 7);

    CircleEmitter* emitter = new CircleEmitter();
    emitter->setPosition(300, 100);
    emitter->setDirection(180);
    emitter->setParticleSize(2);
    emitter->setMax(5000);
    emitter->setAlphaRange(0, 100);
    emitter->setSpread(40);
    emitter->setColorRange(200, 0, 0, 255, 10, 10);
    emitter->setVelocity(50.f, 50.0f);
    emitter->setLength(200);

    group.push_back(s);
    group.push_back(emitter);

    return true;
}

void game_update(float elapsedTime)
{
    group.Update(elapsedTime);
}

void game_render()
{
    group.Draw();
}

void game_end()
{
    for(auto it = group.begin(); it != group.end(); ++it)
    {
        // Remove from list grab value
        Drawable* val = group.remove(it);
        delete val;
    }
}
