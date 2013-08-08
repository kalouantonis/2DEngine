#ifndef _TEXTURELOADER_H_
#define _TEXTURELOADER_H_

#include <Engine.h>

namespace SuperEngine
{
    class TextureLoader: public IResourceLoader<sf::Texture>
    {
    public:
        bool load(const std::string& id, const std::string& filename);
    };
};

#endif // _TEXTURELOADER_H_
