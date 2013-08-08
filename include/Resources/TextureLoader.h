#ifndef _TEXTURELOADER_H_
#define _TEXTURELOADER_H_

#include <Engine.h>
#include <map>

#include <stdexcept>

namespace SuperEngine
{
    class TextureLoader
    {
    private:
        std::map<std::string, std::unique_ptr<sf::Texture> > m_textureMap;

    public:
        // Store textures in the map as string ID's
        bool load(const std::string& id, const std::string& filename);
        // Find item with ID and remove it, returns false if not found
        // or can't be removed
        bool remove(const std::string& id);

        sf::Texture& get(const std::string& id);
        const sf::Texture& get(const std::string& id) const;
    };
};


#endif
