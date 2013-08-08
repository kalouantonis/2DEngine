#ifndef _IMAGELOADER_H_
#define _IMAGELOADER_H_

#include <Engine.h>

namespace SuperEngine
{
    class ImageLoader: public IResourceLoader<sf::Image>
    {
    public:
        bool load(const std::string& id, const std::string& filename);
    };
};

#endif // _IMAGELOADER_H_
