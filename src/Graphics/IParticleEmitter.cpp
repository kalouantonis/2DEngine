#include <Engine.h>

namespace SuperEngine
{
    IParticleEmitter::IParticleEmitter()
        : Drawable()
    {
        m_max = 100;
        m_length = 100;
        m_alphaMin = 254; m_alphaMax = 255;
        m_minR = 0; m_maxR = 255;
        m_minG = 0; m_maxG = 255;
        m_minB = 0; m_maxB = 255;

        m_spread = 10;
    }
};
