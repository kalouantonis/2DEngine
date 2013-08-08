#include <Engine.h>

namespace SuperEngine
{
    bool TextureLoader::load(const std::string& id, const std::string& filename)
    {
        std::unique_ptr<sf::Texture> texture(new sf::Texture);

        if(!texture->loadFromFile(filename))
        {
            Logger::getInstance() << WARN << "TextureLoader failed to load " << filename << std::endl;
            return false;
        }

        // Make the resource map retain ownership of the pointer now
        m_resourceMap.insert(std::make_pair(id, std::move(texture)));

        return true;
    }
};
