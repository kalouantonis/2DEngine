#include "Engine.h"

// Read key states
#define KEY_DOWN(vk) (sf::Keyboard::isKeyPressed(vk) ? 1 : 0)

SuperEngine::Engine* g_pEngine;

bool gameover;

int main()
{
    // Initialize the engine
    g_pEngine = new SuperEngine::Engine();

    // Initialize logger
    SuperEngine::Logger::getInstance().Init("engine.log");

    // Preload any variables here, screen height and such..
    if(!game_preload())
    {
        // Generate error message, i will eventually support pop-up dialogs
        std::cerr << "Game failed to load" << std::endl;
        return -1;
    }

    // Initialize the engine
    if(!g_pEngine->Init(g_pEngine->getScreenWidth(), g_pEngine->getScreenHeight(),
                       g_pEngine->getColorDepth(), g_pEngine->getFullscreen()))
    {
        std::cerr << "Engine initialization failed" << std::endl;
        return 0;
    }

    // main game loop
    gameover = false;

    // Will not use window.isOpen() because we might still need the engine
    // running even if the window closes
    sf::Event event;

    while(!gameover)
    {
        while(g_pEngine->getDevice()->pollEvent(event))
        {
            switch(event.type)
            {
                // Capture a window close event
            case sf::Event::Closed:
                g_pEngine->Shutdown();
                break;
            }
        }
        // TODO: Drawing and rendering both run in threads
        g_pEngine->Update();
    }

    g_pEngine->Close();
    delete g_pEngine;

    return EXIT_SUCCESS;
}
