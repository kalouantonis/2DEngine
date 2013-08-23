#include <Engine.h>

namespace SuperEngine
{
    Tilemap::Tilemap(const std::string& mapdir)
        : tmx::MapLoader(mapdir), m_changedArea(sf::FloatRect(0.f, 0.f, 0.f, 0.f))
    {

    }

    Tilemap::~Tilemap()
    {

    }

    void Tilemap::RotateAll(float m_degrees)
    {
        RotateArea(m_degrees, sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    }

    void Tilemap::RotateArea(float m_degrees, const sf::FloatRect& area)
    {
        m_changedArea = area;

        std::vector<tmx::MapObject*> objects = QueryQuadTree(area);

        for(auto it = objects.begin(); it != objects.end(); ++it)
        {
            (*it)->SetRotation(m_degrees);
        }
    }

    void Tilemap::MoveAll(const sf::Vector2f& offset)
    {
        MoveArea(offset, sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    }

    void Tilemap::MoveAll(float xdir, float ydir)
    {
        MoveArea(xdir, ydir, sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    }

    void Tilemap::MoveArea(const sf::Vector2f& offset, const sf::FloatRect& area)
    {
        m_changedArea = area;

        std::vector<tmx::MapObject*> objects = QueryQuadTree(area);

        for(auto it = objects.begin(); it != objects.end(); ++it)
            (*it)->Move(offset);
    }

    void Tilemap::MoveArea(float xdir, float ydir, const sf::FloatRect& area)
    {
        MoveArea(sf::Vector2f(xdir, ydir), area);
    }

    void Tilemap::SetSizeAll(const sf::Vector2f& size)
    {
        SetSizeInArea(size, sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    }

    void Tilemap::SetSizeAll(float xsize, float ysize)
    {
        SetSizeInArea(xsize, xsize, sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    }

    void Tilemap::SetSizeInArea(const sf::Vector2f& size, const sf::FloatRect& area)
    {
        std::vector<tmx::MapObject*> objects = QueryQuadTree(area);

        for(auto it = objects.begin(); it != objects.end(); ++it)
            (*it)->SetSize(size);
    }

    void Tilemap::SetSizeInArea(float xsize, float ysize, const sf::FloatRect& area)
    {
        SetSizeInArea(sf::Vector2f(xsize, ysize), area);
    }

    void Tilemap::Draw(bool debug)
    {
        MapLoader::Draw(*g_pEngine->getDevice(), debug);
    }

    void Tilemap::Update(float elapsedTime)
    {
        if(m_isAreaChanged())
            UpdateQuadTree(m_changedArea);
    }

    bool Tilemap::m_isAreaChanged()
    {
        return ((m_changedArea.left) || (m_changedArea.width) || (m_changedArea.top) || (m_changedArea.height));
    }

};
