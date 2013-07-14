#include "Engine.h"

#include <ctime>
#include <cstdlib>
#include <sstream>

namespace SuperEngine
{
    Engine::Engine()
    {
        // Seed random number generator
        std::srand(std::time(0));
        m_maximizeProcessor = false;

        m_frameCount_core = 0;
        m_frameRate_core = 0;
        m_frameCount_real = 0;
        m_frameRate_real = 0;

        m_Fps = 60;

        m_ambientColor = sf::Color(255, 255, 255, 0);
        m_clearColor = sf::Color(0, 0, 0, 255);

        m_pausemode = false;
        m_versionMajor = VERSION_MAJOR;
        m_versionMinor = VERSION_MINOR;
        m_revision = REVISION;

        m_drawingGl = false;

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

        // Set default OpenGL Clear color
        glClearColor(color.r, color.g, color.b, color.a);
    }

    int Engine::Init(int width, int height, int colordepth, bool fullscreen)
    {
        // Initialize sf::Window
        // TODO: Implement fullscreen

        // TODO: Allow anti-aliazing and other options to be enabled for OpenGL
        m_pDevice = new sf::RenderWindow(sf::VideoMode(width, height, colordepth),
                                   this->getAppTitle());

        m_pDevice->setFramerateLimit(m_Fps);

        // Initialization failed
        if(!m_pDevice)
        {
            #ifdef _DEBUG
            std::cerr << "m_pDevice failed to initialize in Engine::Init" << std::endl;
            #endif // _DEBUG
            return 0;
        }

        m_pDevice->setActive();

        // Would be a good idea to initialize OPENGL
        if(!game_init()) return 0;

        // Set the default background clearing color
        this->setClearColor();
        // Set matrix mode to projection, with the views and the aspects and
        // all the other good stuff
        glMatrixMode(GL_PROJECTION);


        #ifdef _DEBUG
        std::cout << "Engine initialized successfully" << std::endl;
        #endif // _DEBUG

        return 1;
    }

    void Engine::RefreshView()
    {
        // Reset the viewport
        glViewPort(0, 0, this->getScreenWidth(), this->getScreenHeight());

        // Reset OpenGL
        glLoadIdentity();

        // Set default OpenGL perspective
        // TODO: Tweak this
        gluPerspective(90, this->getScreenWidth() / this->getScreenHeight(), 1.0, 500.0);

        // Reset matrix mode
        glMatrixMode(GL_MODELVIEW);
    }

    void Engine::ClearScene()
    {
        //this->m_pDevice->clear(color);
    }

    int Engine::RenderStart()
    {


        // Check for available device
        if(!this->m_pDevice)
        {
            #ifdef _DEBUG
            std::cerr << "Device does not exist in Engine::RenderStart()" << std::endl;
            #endif // _DEBUG
            return 0;
        }
        if(!this->m_pDevice->setActive()) return 0;

        glLoadIdentity();
        // Maybe implement gluLookAt

        if(!m_drawingGl)
            this->StartDrawGL();

        return 1;
    }

    void Engine::StartDrawGL(DrawTypes type)
    {

        glBegin(GL_TRIANGLES);
        m_drawingGl = true;

        #ifdef _DEBUG
        std::cout << "OpenGL Rendering started" << std::endl;
        #endif // _DEBUG
    }

    void Engine::EndDrawGL()
    {
        glEnd();
        m_drawingGl = false;

        #ifdef _DEBUG
        std::cout << "OpenGL Rendering ended" << std::endl;
        #endif // _DEBUG
    }

    int Engine::RenderStop()
    {
        if(!this->m_pDevice)
        {
            #ifdef _DEBUG
            std::cerr << "Device is non existant in Engine::RenderStop()" << std::endl;
            #endif // _DEBUG

            return 0;
        }

        // TODO:
        // Rendering has ended, display changes,
        // might need to change this later
        this->m_pDevice->display();

        // Automatically end GL drawing at the end of the loop,
        // if it has not been deactivated
        if(_drawingGl)
            this->EndDrawGL();

        return 1;
    }

    int Engine::RenderStart_2d()
    {
        // Store all GL states for later loading.
        // They have to be stored for SFML to be able to
        // draw its normal 2D stuff

        // TODO: This is expensive, it pushes all states and i might not
        // require all of them, refactor to push only the required attributes
        this->m_pDevice->pushGLStates();

        // If openGl is drawing, skip drawing 2D items with SFML
        if(this->m_drawingGl)
            return 0;

        return 1;
    }

    int Engine::RenderStop_2d()
    {
        // Restores previous GL states
        this->m_pDevice->popGLStates();

        return 1;
    }

    void Engine::Shutdown()
    {
        gameover = true;
    }

    void Engine::Update()
    {
        static sf::Clock timedUpdate;

        //calculate core framerate
        m_frameCount_core++;
        if(m_coreTimer.getElapsedTime().asMilliseconds() > 999)
        {
            m_frameRate_core = m_frameCount_core;
            m_frameCount_core = 0;

            m_coreTimer.restart();
        }

        // fast update with no timing
        game_update(timedUpdate.getElapsedTime().asSeconds());

        // update with 60FPS timing, so once every 16 milis
        if(timedUpdate.getElapsedTime().asMilliseconds() > (1000.0f / (float)m_Fps))
        {
            if(!this->getMaximizeProcessor())
            {
                sf::Time waitTime = sf::milliseconds(1);

                sf::sleep(waitTime);
            }

            timedUpdate.restart();
        }
        else
        {
            // calculate real framerate
            m_frameCount_real++;
            if(m_realTimer.getElapsedTime().asMilliseconds() > 999)
            {
                m_frameRate_real = m_frameCount_real;
                m_frameCount_real = 0;

                m_realTimer.restart();
            }

            this->ClearScene();

            // begin rendering
            this->RenderStart();

            game_render_3d();

            // Start 2D rendering functions
            if(RenderStart_2d())
            {
                game_render_2d();
                RenderStop_2d();
            }

            // Done rendering
            this->RenderStop();

        }

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
            #endif // _DEBUG
        }

        return 1;
    }

};