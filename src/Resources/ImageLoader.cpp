#include <Engine.h>

namespace SuperEngine
{
    bool ImageLoader::load(const std::string& id, const std::string& filename)
    {
        std::unique_ptr<sf::Image> image(new sf::Image);

        if(!image->loadFromFile(filename))
        {
            Logger::getInstance() << WARN << "ImageLoader failed to load " << filename << std::endl;
            return false;
        }

        // Make the resource map retain ownership of the pointer now
        m_resourceMap.insert(std::make_pair(id, std::move(image)));

        return true;
    }
};
