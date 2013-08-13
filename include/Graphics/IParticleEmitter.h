#ifndef _PARTICLEEMITTER_H_
#define _PARTICLEEMITTER_H_

namespace SuperEngine
{
    class IParticleEmitter: public Drawable
    {
    private:

        // How far away from the origin a particle is allowed to move
        float m_length;

        // Distance between each particle
        unsigned int m_spread;

        virtual void Add() = 0;

    protected:
        // Cant be bothered to write setters and getters for these
        unsigned int m_max;
        unsigned int m_alphaMin, m_alphaMax;
        unsigned int m_minR, m_minG, m_minB, m_maxR, m_maxG, m_maxB;


    public:

        void setMax(int num) { m_max = num; }
        void setAlphaRange(unsigned int minVal, unsigned int maxVal) { m_alphaMin = minVal; m_alphaMax = maxVal;}
        void setColorRange(unsigned int rmin, unsigned int gmin, unsigned int bmin,
                           unsigned int rmax, unsigned int gmax, unsigned int bmax)
        {
            m_minR = rmin; m_minG = gmin; m_minB = bmin;
            m_maxR = rmax; m_maxG = gmax; m_maxB = bmax;
        }

        void setSpread(unsigned int val) { m_spread = val; }
        unsigned int getSpread() { return m_spread; }
        void setLength(float val) { m_length = val; }
        unsigned int getLength() { return m_length; }


        IParticleEmitter();
        virtual ~IParticleEmitter() {}

        virtual void Draw() = 0;
        virtual void Update(float elapsedTime) = 0;
    };
};

#endif // _PARTICLEEMITTER_H_
