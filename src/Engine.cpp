#include <Engine.h>

#include <cstdlib>
#include <sstream>

namespace SuperEngine
{
    Engine::Engine()
        : m_textureManager()
    {
        // Seed random number generator
        std::srand(std::time(0));

        m_maximizeProcessor = false;

        this->setFPS(60);

        m_ambientColor = sf::Color(255, 255, 255, 0);
        m_clearColor = sf::Color(0, 0, 0, 255);

        m_pausemode = false;
        m_versionMajor = VERSION_MAJOR;
        m_versionMinor = VERSION_MINOR;
        m_revision = REVISION;

        // set default values
        this->setAppTitle("SuperEngine");
        this->setScreenWidth(800);
        this->setScreenHeight(600);
        this->setColorDepth(32);
        this->setFullscreen(false);

        m_pDevice = NULL;
    }

    Engine::~Engine()
    {
        Release();
    }

    const std::string Engine::getVersionText()
    {
        std::ostringstream s;
        s << "SuperEngine v" << m_versionMajor << "." << m_versionMinor
            << "." << m_revision;
        return s.str();
    }

    void Engine::message(const std::string& message, const std::string& title)
    {
        // Create some form of message box, Using wxWidgets would probably be a good idea
        std::cerr << title << " : " << message << std::endl;
    }

    void Engine::fatalerror(const std::string& message, const std::string& title)
    {
        this->message(message, title);
        Shutdown();
    }

    void Engine::setClearColor(const sf::Color& color)
    {
        this->m_clearColor = color;
    }

    int Engine::Init(int width, int height, int colordepth, bool fullscreen)
    {
        // Initialize sf::Window
        // TODO: Implement fullscreen

        m_pDevice = new sf::RenderWindow(sf::VideoMode(width, height, colordepth),
                                   this->getAppTitle());


        // Initialization failed
        if(!m_pDevice)
        {
            #ifdef _DEBUG
            fatalerror("m_pDevice failed to initialize in Engine::Init");
            Logger::getInstance() << ERR << "m_pDevice failed to initialize in Engine::Init" << std::endl;
            #endif // _DEBUG
            return 0;
        }

        m_pDevice->setActive();


        if(!game_init()) return 0;

        this->setClearColor(sf::Color::Black);


        #ifdef _DEBUG
        Logger::getInstance() << getVersionText() << std::endl;
        Logger::getInstance() << INFO << "Engine initialized successfully" << std::endl;
        #endif // _DEBUG

        return 1;
    }

    void Engine::ClearScene()
    {
        this->m_pDevice->clear(this->getClearColor());
    }

    int Engine::RenderStart()
    {
        // Check for available device
        if(!this->m_pDevice)
        {
            #ifdef _DEBUG
            std::cerr << "Device does not exist in Engine::RenderStart()" << std::endl;
            Logger::getInstance() << WARN << "Device does not exist in Engine::RenderStart()" << std::endl;
            #endif // _DEBUG
            return 0;
        }
        if(!this->m_pDevice->setActive()) return 0;

        return 1;
    }

    int Engine::RenderStop()
    {
        if(!this->m_pDevice)
        {
            #ifdef _DEBUG
            std::cerr << "Device is non existant in Engine::RenderStop()" << std::endl;
            Logger::getInstance() << WARN << "Device is non existant in Engine::RenderStop()" << std::endl;
            #endif // _DEBUG

            return 0;
        }

        // TODO:
        // Rendering has ended, display changes,
        // might need to change this later
        this->m_pDevice->display();

        return 1;
    }

    void Engine::Shutdown()
    {
        gameover = true;
    }

    void Engine::Update()
    {
        static sf::Clock timedMove;
        static float timeSinceLastUpdate = 0.f;

        // process events here

        timeSinceLastUpdate += timedMove.restart().asSeconds();
        while(timeSinceLastUpdate > m_timePerFrame)
        {
            // Reduce time since last update, if the PC is slow, the time since last update
            // will loop in the while, reduces lag and visual glitches.
            // If rendering is slow, it may happen that the logic update is called
            // much more frequently than the render function
            timeSinceLastUpdate -= m_timePerFrame;
            // process events here

            // Update time with supposed FPS time
            game_update(m_timePerFrame);
        }


        this->ClearScene();

        // begin rendering
        this->RenderStart();

        game_render();

        // Done rendering
        this->RenderStop();
    }

    void Engine::Close()
    {
        game_end();

        Release();
    }

    int Engine::Release()
    {
        if(m_pDevice)
        {
            m_pDevice->setActive(false);
            m_pDevice->close();

            delete m_pDevice;

            // Just for safe measures :P
            m_pDevice = NULL;

            #ifdef _DEBUG
            std::cout << "Engine closed, m_pDevice deleted" << std::endl;
            Logger::getInstance() << INFO << "Engine closed, m_pDevice deleted" << std::endl;
            #endif // _DEBUG
        }

        m_textureManager.removeAll();

        return 1;
    }

};
