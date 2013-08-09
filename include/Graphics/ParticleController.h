#ifndef _PARTICLECONTROLLER_H_
#define _PARTICLECONTROLLER_H_

#include "Engine.h"

#include <vector>
#include <cmath>

const double RAD = M_PI / 180.f;

namespace SuperEngine
{
    class ParticleController
    {
    private:
        struct Particle
        {
            sf::Vector2f velocity;
            sf::Vector2f position;

            sf::CircleShape primitive;
        };

        typedef std::vector<Particle>::iterator m_particleIter;
        std::vector<Particle> m_particles;

        sf::Vector2f m_position;
        float m_direction;

        // How far away from the origin a particle is allowed to move
        float m_length;
        unsigned int m_max;
        unsigned int m_alphaMin, m_alphaMax;
        unsigned int m_minR, m_minG, m_minB, m_maxR, m_maxG, m_maxB;

        // Distance between each particle
        unsigned int m_spread;
        sf::Vector2f m_velocity;

        // Size of circle primitive
        float m_partSize;

        void Add();

    public:
        void setPosition(float x, float y) { m_position.x = x; m_position.y = y; }
        void setPosition(const sf::Vector2f& val) { m_position = val; }
        sf::Vector2f getPosition(void) const { return m_position; }

        void setDirection(float angle) { m_direction = angle; }
        float getDirection(void) const { return m_direction; }

        void setParticleSize(float val) { m_partSize = val; }
        float getParticleSize() const { return m_partSize; }

        void setMax(int num) { m_max = num; }
        void setAlphaRange(unsigned int minVal, unsigned int maxVal) { m_alphaMin = minVal; m_alphaMax = maxVal;}
        void setColorRange(unsigned int rmin, unsigned int gmin, unsigned int bmin,
                           unsigned int rmax, unsigned int gmax, unsigned int bmax)
        {
            m_minR = rmin; m_minG = gmin; m_minB = bmin;
            m_maxR = rmax; m_maxG = gmax; m_maxB = bmax;
        }

        void setSpread(unsigned int val) { m_spread = val; }
        void setLength(float val) { m_length = val; }

        void setVelocity(float x = 0.0f, float y = 0.0f) {m_velocity.x = x; m_velocity.y = y; }
        void setVelocity(const sf::Vector2f& vel) { m_velocity = vel; }

        ParticleController();
        virtual ~ParticleController();

        void Draw();
        void Update(float elapsedTime);
    };
};

#endif // _PARTICLECONTROLLER_H_
