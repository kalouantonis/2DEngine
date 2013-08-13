#ifndef _PARTICLECONTROLLER_H_
#define _PARTICLECONTROLLER_H_

#include <Engine.h>

#include <vector>
#include <cmath>

const double RAD = M_PI / 180.f;

namespace SuperEngine
{
    class CircleEmitter: public IParticleEmitter
    {
    private:
        struct Circle
        {
            sf::Vector2f position;
            sf::Vector2f velocity;

            sf::CircleShape primitive;
        };

        typedef std::vector<Circle>::iterator m_particleIter;
        std::vector<Circle> m_particles;

        void Add();

       // Size of circle primitive
        float m_partSize;

    public:
        CircleEmitter();
        ~CircleEmitter();

        void setParticleSize(float val) { m_partSize = val; }
        float getParticleSize() const { return m_partSize; }

        void Draw() final;
        void Update(float elapsedTime) final;
    };
};

#endif // _PARTICLECONTROLLER_H_
