#ifndef _DRAWABLE_H_
#define _DRAWABLE_H_

#include <Engine.h>

namespace SuperEngine
{
    class Drawable
    {
    private:
        sf::Vector2f m_position, m_velocity;
        float m_direction;
        float m_rotation;

    public:
        Drawable();
        virtual ~Drawable();

        sf::Vector2f getPosition() { return m_position; }
        void setPosition(const sf::Vector2f& vec) { m_position = vec; }
        void setPosition(float x, float y) { m_position.x = x; m_position.y = y; }

        //position on screen
        double getX() const { return m_position.x; }
        double getY() const { return m_position.y; }
        void setX(float x) { m_position.x = x; }
        void setY(float y) { m_position.y = y; }

        void setDirection(float angle) { m_direction = angle; }
        float getDirection(void) const { return m_direction; }

        void setVelocity(float x = 0.0f, float y = 0.0f) {m_velocity.x = x; m_velocity.y = y; }
        void setVelocity(const sf::Vector2f& vel) { m_velocity = vel; }
        sf::Vector2f getVelocity() { return m_velocity; }

        void setRotation(float rot) { m_rotation = rot; }
        float getRotation() { return m_rotation; }

        virtual void Draw() = 0;
    };
};

#endif // _DRAWABLE_H_
