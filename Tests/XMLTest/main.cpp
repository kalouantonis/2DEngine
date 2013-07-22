#include "../Engine/Engine.h"

using namespace SuperEngine;

bool game_preload()
{
    XMLoader xml;

    if(xml.LoadContent("engine.xml"))
    {
        g_pEngine->setScreenWidth(XMLoader::StrToInt(xml.getAttrFromElem("width", "screen")));
        g_pEngine->setScreenHeight(XMLoader::StrToInt(xml.getAttrFromElem("height", "screen")));
        g_pEngine->setColorDepth(XMLoader::StrToInt(xml.getAttrFromElem("colordepth", "screen")));

        g_pEngine->getLogger() << INFO << "Screen params successfully set!" << std::endl;
    }



    return true;
}

bool game_init()
{
    return true;
}

void game_update(float elapsedTime)
{

}

void game_render_2d()
{

}

void game_end()
{

}
