#ifndef _IRESOURCELOADER_H_
#define _IRESOURCELOADER_H_

#include <Engine.h>
#include <map>

#include <stdexcept>

namespace SuperEngine
{
    template<typename T>
    class IResourceLoader
    {
    protected:
        std::map<std::string, std::unique_ptr<T> > m_resourceMap;

    public:
        // Store resources in the map as string ID's
        // I will assume that most loading will involve sfml objects,
        // if that's not the case, then this should be overriden
        bool load(const std::string& id, const std::string& filename)
        {
            if(!exists(id))
            {
                std::unique_ptr<T> resource(new T());

                if(!resource->loadFromFile(filename))
                {
                    Logger::getInstance() << WARN << "ResourceLoader failed to load " << filename << std::endl;
                    return false;
                }

                // Make the resource map retain ownership of the pointer now
                m_resourceMap.insert(std::make_pair(id, std::move(resource)));

                #ifdef _DEBUG
                Logger::getInstance() << DEBUG << "Resource " << filename << " sucessfully loaded" << std::endl;
                #endif // _DEBUG
            }

            return true;

        }

        // Loads the file in to the map, without loading the resource from file
        bool load(const std::string& id)
        {
            if(!exists(id))
            {
                std::unique_ptr<T> resource(new T());

                // Make the resource map retain ownership of the pointer now
                m_resourceMap.insert(std::make_pair(id, std::move(resource)));

                #ifdef _DEBUG
                Logger::getInstance() << DEBUG << "Resource " << id << " sucessfully loaded" << std::endl;
                #endif // _DEBUG
            }

            return true;
        }

        // Useful for loading another parameter along with just the file.
        // Can be used for shaders, or textures. E.g load("id", "texturef", sf::IntRect(0, 0, 32, 32))
        template<typename P>
        bool load(const std::string& id, const std::string& filename, const P& secondParam)
        {
            if(!exists(id))
            {
                std::unique_ptr<T> resource(new T());

                if(!resource->loadFromFile(filename, secondParam))
                {
                    Logger::getInstance() << WARN << "ResourceLoader failed to load " << filename << std::endl;
                    return false;
                }

                // Make the resource map retain ownership of the pointer now
                m_resourceMap.insert(std::make_pair(id, std::move(resource)));

                #ifdef _DEBUG
                Logger::getInstance() << DEBUG << "Resource " << filename << " sucessfully loaded" << std::endl;
                #endif // _DEBUG
            }

            return true;
        }

        // Find item with ID and remove it, returns false if not found
        // or can't be removed
        bool remove(const std::string& id)
        {
            auto found = m_resourceMap.find(id);

            if(found == m_resourceMap.end())
            {
                #ifdef _DEBUG
                Logger::getInstance() << WARN <<"Texture removal id: " << id << " failed" << std::endl;
                #endif // _DEBUG

                return false;
            }

            m_resourceMap.erase(found);

            return true;
        }

        void removeAll()
        {
            m_resourceMap.clear();

            #ifdef _DEBUG
            Logger::getInstance() <<  DEBUG << "All resources cleared from cache" << std::endl;
            #endif
        }

        // Checks if item exists
        bool exists(const std::string& id) const
        {
            auto found = m_resourceMap.find(id);

            if(found == m_resourceMap.end())
                return false;

            return true;
        }

        T& get(const std::string& id)
        {
            // Well, since C++11 is what all the cool kids are using, ill go with it :)
            auto found = m_resourceMap.find(id);

            // No item found, end() iterator is returned
            if(found == m_resourceMap.end())
            {
                throw std::logic_error("Could not get texture id: " + id + " from map");
                Logger::getInstance() << WARN << "Could not get texture id: " + id << " from map" << std::endl;
            }

            return *(found->second);
        }

        const T& get(const std::string& id) const
        {
            return get(id);
        }
    };

    typedef IResourceLoader<sf::Image> ImageLoader;
    typedef IResourceLoader<sf::Font> FontLoader;
    typedef IResourceLoader<sf::SoundBuffer> SoundBufferLoader;
};


#endif
