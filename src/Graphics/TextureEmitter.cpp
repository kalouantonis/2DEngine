#include <Engine.h>

namespace SuperEngine
{
    TextureEmitter::TextureEmitter()
    {
        // Set to normal scale, so no scale
        setScale(1.f);
    }

    TextureEmitter::~TextureEmitter()
    {
        m_particles.clear();
    }

    void TextureEmitter::setImage(sf::Texture& image)
    {
        m_texture = image;
    }

    bool TextureEmitter::loadImage(const std::string& filename, const sf::Color& transcolor)
    {
        // So im not going to use the resource manager because ironically, its sort of wasteful.
        // I load the texture once, and thats it, repeated for n number of particles.
        sf::Image tempImage;

        if(!tempImage.loadFromFile(filename))
        {
            // Warning because running wont fail
            Logger::getInstance() << WARN << "TextureEmitter::loadImage - Failed to load image " << filename << std::endl;

            return false;
        }

        m_texture.loadFromImage(tempImage);

        return true;
    }

    void TextureEmitter::Add()
    {
        Sprite p;

        p.setPosition(getPosition());

        // add some randomness to the spread, so it looks better
        // this should be opt in though
        double variation = ((rand() % getSpread()) - (getSpread() / 2)) / 100.0f;

        double dir = getDirection() - 90.0f;
        double vx = (cos(dir * RAD) + variation);
        double vy = (sin(dir * RAD) + variation);

        p.setVelocity(vx * getVelocity().x, vy * getVelocity().y);

        // Check efficiency of this, is it really worth using the
        // resource manager for this? I'll only use the image once for thousands of images

        p.setImage(m_texture);

        int r = (rand() % (m_maxR - m_minR)) + m_minR;
        int g = (rand() % (m_maxG - m_minG)) + m_minG;
        int b = (rand() % (m_maxB - m_minB)) + m_minB;
        int a = (rand() % (m_alphaMax - m_alphaMin)) + m_alphaMin;

        p.setColor(r, g, b, a);

        m_particles.push_back(p);
    }

    void TextureEmitter::Update(float elapsedTime)
    {
        if((unsigned int)m_particles.size() < m_max)
        {
            if(!g_pEngine->getMaximizeProcessor())
                sf::sleep(sf::milliseconds(1));

            Add();
        }

        for(auto i = m_particles.begin(); i != m_particles.end(); ++i)
        {
            // Delegate work to sprite class
            i->Move(elapsedTime);

            if(getVecDistance(i->getPosition(), this->getPosition()) > getLength())
            {
                i->setPosition(this->getPosition());
            }
        }
    }

    void TextureEmitter::Draw()
    {
        for(auto i = m_particles.begin(); i != m_particles.end(); ++i)
        {
            // Delegate drawing work to sprite
            i->Draw();
        }
    }
};
