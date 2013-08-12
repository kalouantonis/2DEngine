#ifndef _TEXTUREEMITTER_H_
#define _TEXTUREEMITTER_H_

#include <Engine.h>

namespace SuperEngine
{
    class TextureEmitter: public IParticleEmitter
    {
    private:
        std::vector<Sprite> m_particles;

        void Add() final;

        float m_scale;

        sf::Texture m_texture;

    public:
        TextureEmitter();
        ~TextureEmitter();

        void setScale(float scale) { m_scale = scale; }
        float getScale() { return m_scale; }

        void setImage(sf::Texture& image);
        // Maybe later on i can allow ID loading from the resource manager, but right now, the
        // user is responsible for managing that. Thats right user, get off your lazy ass and
        // do some work.
        bool loadImage(const std::string& filename, const sf::Color& transcolor = sf::Color(255, 0, 255));

        void Draw() final;
        void Update(float elapsedTime) final;
    };
};

#endif // _TEXTUREEMITTER_H_
