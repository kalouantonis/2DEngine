#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include <TmxMapLoader/MapLoader.h>

#include <Engine.h>

namespace SuperEngine
{
    class Tilemap: public tmx::MapLoader
    {
    private:
        sf::FloatRect m_changedArea;

        bool m_isAreaChanged();

    public:
        Tilemap(const std::string& mapdir);
        ~Tilemap();

        void RotateAll(float m_degrees);
        void RotateArea(float m_degrees, const sf::FloatRect& area);

        void MoveAll(const sf::Vector2f& offset);
        void MoveAll(float xdir, float ydir);
        void MoveArea(const sf::Vector2f& offset, const sf::FloatRect& area);
        void MoveArea(float xdir, float ydir, const sf::FloatRect& area);

        // position from top right corner of screen
        sf::Vector2f getPosition() const;

        bool isCollisionArea(const sf::Vector2f& pos);
        bool isCollisionArea(float x, float y);

        // Remove all tiles
        void ClearScene();
        // Remove tiles in a specified area
        void ClearArea(const sf::FloatRect& area);

        void SetSizeAll(const sf::Vector2f& size);
        void SetSizeAll(float xsize, float ysize);
        void SetSizeInArea(float xsize, float ysize, const sf::FloatRect& area);
        void SetSizeInArea(const sf::Vector2f& size, const sf::FloatRect& area);

        void Draw(bool debug = false);
        void Update(float elapsedTime);
    };
};

#endif // _TILEMAP_H_
