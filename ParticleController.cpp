#include "Engine.h"

#include <cmath>

namespace SuperEngine
{
    ParticleController::ParticleController()
    {
        // set to default
        m_pImage = NULL;
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

    bool ParticleController::loadImage(const std::string& filename)
    {
        m_pImage = new sf::Image();

        if(!m_pImage->loadFromFile(filename))
        {
            #ifdef _DEBUG
            std::cerr << "Image " << filename << " failed to load" << std::endl;
            #endif // _DEBUG
            return false;
        }

        m_imageLoaded = true;

        #ifdef _DEBUG
        std::cout << "Image loaded successfully" << std::endl;
        #endif // _DEBUG

        return true;
    }

    bool ParticleController::setImage(sf::Image* image)
    {
        // I didnt define the image, so its not my problem... deal with it
        m_imageLoaded = false;

        m_pImage = image;


        #ifdef _DEBUG
        std::cout << "Image successfully set" << std::endl;
        #endif // _DEBUG

        return true;
    }

    ParticleController::~ParticleController()
    {
        if(m_imageLoaded)
            delete m_pImage;

        // destroy particles. Remeber we want to de-allocate in reverse order
        // correct me if im wrong

        // Consider using a reverse iter for de-allocating backwards
        for(m_particleIter i = m_particles.begin(); i != m_particles.end(); i++)
        {
            delete *i;
        }

        m_particles.clear();
    }

    void ParticleController::Add()
    {
        static double RAD = M_PI / 180.0f;
        double vx, vy;

        // create a new particle
        Sprite* p = new Sprite();
        p->setImage(m_pImage);
        p->setPosition(getPosition().x, getPosition().y);

        // add some randomness to the spread, so it looks better
        // this should be opt in though
        double variation = (rand() % m_spread - (m_spread / 2)) / 100.0f;

        // set velocity, don't worry, i didnt think of this,
        // this is copy pasta
        double dir = m_direction - 90.0f;
        vx = cos(dir * RAD) + variation;
        vy = sin(dir * RAD) + variation;
        p->setVelocity(vx, vy);

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
            (*i)->Draw();
    }

    void ParticleController::Update()
    {
        // check if a new particle is needed, according to the max allowed
        if((int)m_particles.size() < m_max)
        {
            // pause for a second, dont want to do this too quickly
            sf::sleep(sf::milliseconds(1));
            Add();
        }

        for(m_particleIter i = m_particles.begin(); i != m_particles.end(); i++)
        {
            // update particles position
            (*i)->Move();

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
