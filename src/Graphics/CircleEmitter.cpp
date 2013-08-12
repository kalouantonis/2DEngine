#include "Engine.h"

namespace SuperEngine
{
    CircleEmitter::CircleEmitter()
        : IParticleEmitter()
    {
        // Set scale to default 1.0f
        m_partSize = 2;
    }

    CircleEmitter::~CircleEmitter()
    {
        //m_memPool.Destroy();
        m_particles.clear();

        #ifdef _DEBUG
        Logger::getInstance() << INFO << "ParticleController destroyed" << std::endl;
        #endif // _DEBUG

    }

    void CircleEmitter::Add()
    {
        // create a new particle
        Circle p;
        p.position = sf::Vector2f(this->getPosition());

        // add some randomness to the spread, so it looks better
        // this should be opt in though
        double variation = ((rand() % getSpread()) - (getSpread() / 2)) / 100.0f;

        double dir = getDirection() - 90.0f;
        double vx = (cos(dir * RAD) + variation);
        double vy = (sin(dir * RAD) + variation);

        // set velocity, don't worry, i didnt think of this,
        // this is copy pasta

        p.velocity = sf::Vector2f(vx * getVelocity().x, vy * getVelocity().y);

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

    void CircleEmitter::Draw()
    {
        for(m_particleIter i = m_particles.begin(); i != m_particles.end(); ++i)
        {
            i->primitive.setPosition(i->position);

            g_pEngine->getDevice()->draw(i->primitive);
        }
    }

    void CircleEmitter::Update(float elapsedTime)
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
            if(getVecDistance(i->position, getPosition()) > getLength())
            {
                //+ reset particle to origin
                i->position = getPosition();
            }
        }
    }
};
