#include <Engine.h>

namespace SuperEngine
{
    bool TextureLoader::load(const std::string& id, const std::string& filename)
    {
        std::unique_ptr<sf::Texture> texture(new sf::Texture);

        if(!texture->loadFromFile(filename))
        {
            std::cerr << "Loading texture from file " << filename << " failed" << std::endl;
            Logger::getInstance() << ERR << "Loading texture from file " << filename << " failed" << std::endl;

            return false;
        }

        // Move the unique_ptr to be contained withing the map
        m_textureMap.insert(std::make_pair(id, std::move(texture)));

        #ifdef _DEBUG
        Logger::getInstance() << DEBUG << "Loading texture from file " << filename << " succeeded" << std::endl;
        #endif // _DEBUG

        return true;
    }

    bool TextureLoader::remove(const std::string& id)
    {
        auto found = m_textureMap.find(id);

        if(found == m_textureMap.end())
        {
            #ifdef _DEBUG
            Logger::getInstance() << WARN <<"Texture removal id: " << id << " failed" << std::endl;
            #endif // _DEBUG

            return false;
        }

        m_textureMap.erase(found);

        return true;
    }

    sf::Texture& TextureLoader::get(const std::string& id)
    {
        // Well, since C++11 is the new cool kid thing, ill go with it :)
        auto found = m_textureMap.find(id);

        // No item found, end() iterator is returned
        if(found == m_textureMap.end())
        {
            throw std::runtime_error("Could not get texture id: " + id + " from map");
            Logger::getInstance() << WARN << "Could not get texture id: " + id << " from map" << std::endl;
        }

        return *(found->second);
    }

    const sf::Texture& TextureLoader::get(const std::string& id) const
    {
        return get(id);
    }
}
