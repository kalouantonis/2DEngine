#include <Engine.h>

namespace SuperEngine
{
    Drawable::Drawable()
        : m_position(0.f, 0.f), m_velocity(0.f, 0.f),
        m_direction(0.f), m_rotation(0.f)
    {
    }

    Drawable::~Drawable()
    {

    }
};
