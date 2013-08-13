#ifndef _TEXTURELOADER_H_
#define _TEXTURELOADER_H_

#include <Engine.h>

namespace SuperEngine
{
    class TextureLoader: public IResourceLoader<sf::Texture>
    {
    public:
        // Dont remeber how to do this correctly, so annoying...
        bool load(const std::string& id, const std::string& filename)
        {
            return IResourceLoader<sf::Texture>::load(id, filename);
        }

        bool load(const std::string& id)
        {
            return IResourceLoader<sf::Texture>::load(id);
        }

        template<typename P>
        bool load(const std::string& id,  const std::string& filename, const P& secondParam)
        {
            return IResourceLoader<sf::Texture>::load<P>(id, filename, secondParam);
        }

        bool load(const std::string& id, const sf::Image& image)
        {
            if(!exists(id))
            {
                std::unique_ptr<sf::Texture> texture(new sf::Texture());

                if(!texture->loadFromImage(image))
                {
                    Logger::getInstance() << WARN << "TextureLoader failed to load image: " << id << std::endl;
                    return false;
                }

                m_resourceMap.insert(std::make_pair(id, std::move(texture)));

                #ifdef _DEBUG
                Logger::getInstance() << DEBUG << "Image " << id << " sucessfully loaded in to texture" << std::endl;
                #endif // _DEBUG
            }

            return true;
        }
    };
};

#endif // _TEXTURELOADER_H_
