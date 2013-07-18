#ifndef _PARTICLECONTROLLER_H_
#define _PARTICLECONTROLLER_H_

#include "Engine.h"

#include <vector>

namespace SuperEngine
{
    class ParticleController
    {
    private:
        typedef std::vector<Sprite*>::iterator m_particleIter;
        std::vector<Sprite*> m_particles;

        sf::Image* m_pImage;

        Vector2f m_position;
        float m_direction, m_length;
        int m_max;
        int m_alphaMin, m_alphaMax;
        int m_minR, m_minG, m_minB, m_maxR, m_maxG, m_maxB;
        int m_spread;
        Vector2f m_velocity;
        float m_scale;

        bool m_imageLoaded;

    public:
        void setPosition(float x, float y) { m_position.x = x; m_position.y = y; }
        void setPosition(const Vector2f& val) { m_position = val; }
        Vector2f getPosition(void) { return m_position; }

        void setDirection(float angle) { m_direction = angle; }
        float getDirection(void) { return m_direction; }

        void setMax(int num) { m_max = num; }
        void setAlphaRange(int minVal, int maxVal) { m_alphaMin = minVal; m_alphaMax = maxVal;}
        void setColorRange(int rmin, int gmin, int bmin, int rmax, int gmax, int bmax)
        {
            m_minR = rmin; m_minG = gmin; m_minB = bmin;
            m_maxR = rmax; m_maxG = gmax; m_maxB = bmax;
        }

        void setSpread(int val) { m_spread = val; }
        void setLength(float val) { m_length = val; }

        void setVelocity(float x = 0.0f, float y = 0.0f) {m_velocity.x = x; m_velocity.y = y; }
        void setVelocity(const Vector2f& vel) { m_velocity = vel; }

        void setScale(float val = 1.0f) { m_scale = val; }

        ParticleController();
        virtual ~ParticleController();

        bool loadImage(const std::string& filename);
        bool setImage(sf::Image*);
        void Draw();
        void Update();
        void Add();
    };
};

#endif // _PARTICLECONTROLLER_H_
