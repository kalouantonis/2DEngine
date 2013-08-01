#include "Engine.h"

#include <cmath>

namespace SuperEngine
{
    ParticleController::ParticleController()
    {
        // set to default
//       m_pImage = NULL;
        m_max = 100;
        m_length = 100;
        m_direction = 0;
        m_alphaMin = 254; m_alphaMax = 255;
        m_minR = 0; m_maxR = 255;
        m_minG = 0; m_maxG = 255;
        m_minB = 0; m_maxB = 255;

        m_spread = 10;
        setVelocity(1.0f, 1.0f);

        // Set scale to default 1.0f
        setScale();

        m_imageLoaded = false;
    }

    bool ParticleController::Init()
    {
        // Assign a new pool with the size of the maximum allowed particles
        // May need to look in to this, because if we have 500000 particles,
        // well, that might be bad :)
        //return m_memPool.Init(sizeof(Sprite), m_max);
        return true;
    }

    bool ParticleController::loadImage(const std::string& filename)
    {
        m_imageLoaded = true;

        if(!m_texture.loadFromFile(filename))
        {
            Logger::getInstance() << ERR << "ParticleController -> image " << filename
                        << " failed to load" << std::endl;
            return false;
        }


        #ifdef _DEBUG
        Logger::getInstance() << DEBUG << "ParticleController -> image loaded successfully" << std::endl;
        #endif // _DEBUG

        return this->Init();

    }

    bool ParticleController::setImage(const sf::Texture& image)
    {
        // I didnt define the image, so its not my problem... deal with it
        m_imageLoaded = false;

        m_texture = image;

        #ifdef _DEBUG
        std::cout << "Image successfully set" << std::endl;
        Logger::getInstance() << DEBUG << "ParticleController -> image successfully set" << std::endl;
        #endif // _DEBUG

        return this->Init();
    }

    ParticleController::~ParticleController()
    {
        // Consider using a reverse iter for de-allocating backwards
        for(m_particleIter i = m_particles.begin(); i != m_particles.end(); i++)
        {
            delete *i;
            //m_memPool.Free(static_cast<void*>(*i));
        }

        //m_memPool.Destroy();
        m_particles.clear();

        #ifdef _DEBUG
        Logger::getInstance() << INFO << "ParticleController destroyed" << std::endl;
        #endif // _DEBUG

    }

    void ParticleController::Add()
    {
        static double RAD = M_PI / 180.0f;
        double vx, vy;

        // create a new particle
        Sprite* p = new Sprite();
        //Sprite* p = static_cast<Sprite*>(m_memPool.Alloc(sizeof(Sprite)));
        p->setImage(m_texture);

        p->setPosition(getPosition().x, getPosition().y);

        // add some randomness to the spread, so it looks better
        // this should be opt in though
        double variation = (rand() % m_spread - (m_spread / 2)) / 100.0f;

        // set velocity, don't worry, i didnt think of this,
        // this is copy pasta
        double dir = m_direction - 90.0f;
        vx = cos(dir * RAD) + variation;
        vy = sin(dir * RAD) + variation;
        p->setVelocity(m_velocity.x * vx, m_velocity.y * vy);

        // set random color based on ranges, unfortunetally,
        // it would take too many resources to randomize this using
        // ambient noise :)
        int r = (rand() % (m_maxR - m_minR)) + m_minR;
        int g = (rand() % (m_maxG - m_minG)) + m_minG;
        int b = (rand() % (m_maxB - m_minB)) + m_minB;
        int a = (rand() % (m_alphaMax - m_alphaMin)) + m_alphaMin;
        p->setColor(r, g, b, a);

        // set the scale
        p->setScale(m_scale);

        // add the particle to our controller
        m_particles.push_back(p);
    }

    void ParticleController::Draw()
    {
        for(m_particleIter i = m_particles.begin(); i != m_particles.end(); i++)
        {
            (*i)->Draw();
        }
    }

    void ParticleController::Update(float elapsedTime)
    {
        // check if a new particle is needed, according to the max allowed
        if((unsigned int)m_particles.size() < m_max)
        {
            // Thread this?

            // pause for a second, lets take thigs slow until we get to know eachother better
            if(!g_pEngine->getMaximizeProcessor())
                sf::sleep(sf::milliseconds(1));

            Add();
        }

        for(m_particleIter i = m_particles.begin(); i != m_particles.end(); i++)
        {
            // update particles position
            (*i)->Move(elapsedTime);

            // Check if the particle has passed the alowed distance from origin
            if((*i)->getPosition().distance(this->m_position) > m_length)
            {
                // reset particle to origin
                (*i)->setX(m_position.x);
                (*i)->setY(m_position.y);
            }
        }
    }

};
