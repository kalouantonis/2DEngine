#include "Engine.h"

namespace SuperEngine
{
    ParticleController::ParticleController()
    {
        m_max = 100;
        m_length = 100;
        m_direction = 0;
        m_alphaMin = 254; m_alphaMax = 255;
        m_minR = 0; m_maxR = 255;
        m_minG = 0; m_maxG = 255;
        m_minB = 0; m_maxB = 255;

        m_spread = 10;
        setVelocity(10.0f, 10.0f);

        // Set scale to default 1.0f
        m_partSize = 2;
    }

    ParticleController::~ParticleController()
    {
        //m_memPool.Destroy();
        m_particles.clear();

        #ifdef _DEBUG
        Logger::getInstance() << INFO << "ParticleController destroyed" << std::endl;
        #endif // _DEBUG

    }

    void ParticleController::Add()
    {
        // create a new particle
        Particle p;
        p.position = sf::Vector2f(this->getPosition());

        // add some randomness to the spread, so it looks better
        // this should be opt in though
        double variation = ((rand() % m_spread) - (m_spread / 2)) / 100.0f;

        double dir = m_direction - 90.0f;
        double vx = (cos(dir * RAD) + variation);
        double vy = (sin(dir * RAD) + variation);

        // set velocity, don't worry, i didnt think of this,
        // this is copy pasta

        p.velocity = sf::Vector2f(vx * m_velocity.x, vy * m_velocity.y);

        // set random color based on ranges, unfortunetally,
        // it would take too many resources to randomize this using
        // ambient noise :)
        p.primitive = sf::CircleShape(m_partSize);

        int r = (rand() % (m_maxR - m_minR)) + m_minR;
        int g = (rand() % (m_maxG - m_minG)) + m_minG;
        int b = (rand() % (m_maxB - m_minB)) + m_minB;
        int a = (rand() % (m_alphaMax - m_alphaMin)) + m_alphaMin;

        p.primitive.setFillColor(sf::Color(r, g, b, a));

        // add the particle to our controller
        m_particles.push_back(p);
    }

    void ParticleController::Draw()
    {
        for(m_particleIter i = m_particles.begin(); i != m_particles.end(); ++i)
        {
            // (*i)->Draw();
            i->primitive.setPosition(i->position);

            g_pEngine->getDevice()->draw(i->primitive);
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

        for(m_particleIter i = m_particles.begin(); i != m_particles.end(); ++i)
        {
            // update particles position

            i->position.x += i->velocity.x * elapsedTime;
            i->position.y += i->velocity.y * elapsedTime;

            // Check if the particle has passed the alowed distance from origin
            if(getVecDistance(i->position, m_position) > m_length)
            {
                //+ reset particle to origin
                i->position = m_position;
            }
        }
    }
};
