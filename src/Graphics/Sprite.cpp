#include "Engine.h"

namespace SuperEngine
{
    Sprite::Sprite()
    {
        Init();
    }

    bool Sprite::Init()
    {
//this->m_pImage = NULL;
        this->m_imageLoaded = false;
        this->setPosition(0.0f, 0.0f);
        this->setVelocity(0.0f, 0.0f);
        this->setState(1);
        this->setDirection(0);
        this->setCurrentFrame(1);
        this->setTotalFrames(1);
        this->setAnimationDir(1);
        this->setRows(1);

        this->m_animationCols = 1;
        this->m_animationRows = 1;
        this->m_frameSize = Vector2f(1.0f, 1.0f);

        this->m_animstartx = 0;
        m_startframe = 0;
        this->m_animstarty = 0;
        this->m_faceangle = 0;
        this->m_moveangle = 0;
        this->setRotation(0);
        this->setScale(1.0f);

        // Sync with real framerate
        this->m_useFrameTimer = true;
        this->setFrameDelay(1000.0f / g_pEngine->getFPS());

        this->setCollidable(true);
        this->setCollisionMethod(COLLISION_RECT);

        this->setColor(sf::Color::Black);

        this->setVisible(true);

        return true;
    }

    Sprite::~Sprite()
    {

    }

    bool Sprite::genSprite(unsigned int animationCols, unsigned int animationRows)
    {
        if(m_animationCols <= 1 && m_animationRows <= 1)
        {
            this->setColumns(animationCols);
            this->setRows(animationRows);
        }

        m_sprite = sf::Sprite(m_texture);
//        m_sprite.setTexture(m_texture);

        this->m_frameSize.x = (float) m_texture.getSize().x / (float) this->m_animationCols;
        this->m_frameSize.y = (float) m_texture.getSize().y / (float) this->m_animationRows;

        if(m_totalframes == 1)
            m_totalframes = m_animationCols * m_animationRows;

        // Set color to the color of the sprite
        this->setColor(m_sprite.getColor());

        return true;
    }

    bool Sprite::loadImage(const std::string& filename, unsigned int animationCols, unsigned int animationRows, const sf::Color& transcolor)
    {
        sf::Image image;

        if(!image.loadFromFile(filename))
        {
            Logger::getInstance() << ERR << filename << " could not be loaded by image loader. Line: " << __LINE__ << std::endl;
            return false;
        }

        // Set the mask color
        image.createMaskFromColor(transcolor);

        // create texture to hold image
        //m_texture = sf::Texture();
        //m_texture = sf::Texture();
        m_texture.loadFromImage(image);

        if(!this->genSprite(animationCols, animationRows))
            return false;

        m_imageLoaded = true;

        #ifdef _DEBUG
        Logger::getInstance() << INFO << "Image " << filename << "sucessfully loaded" << std::endl;
        #endif // _DEBUG

        return true;
    }

     bool Sprite::setImage(const sf::Texture& image, unsigned int animationCols, unsigned int animationRows)
    {
        m_texture = image;
        // We did not load the image, so we are not responsible for
        // handling its allocation and deletion

        if(!this->genSprite(animationCols, animationRows))
            return false;

        this->m_imageLoaded = false;

        return true;
    }

    void Sprite::m_Transform()
    {
        // Maybe do some origin calculations
        m_sprite.setOrigin(m_frameSize.x / 2, m_frameSize.y / 2);

        // Perform simple image transformations
        m_sprite.setScale(this->m_scale, this->m_scale);
        m_sprite.setRotation(this->getRotation());
        // Don't know if i'll keep this
        m_sprite.setPosition(this->getPosition().x, this->getPosition().y);

        m_sprite.setColor(this->getColor());
    }

    void Sprite::Draw()
    {
        // the base of all animation
        int fx = (this->m_curframe % this->m_animationCols) * m_frameSize.x;
        int fy = (this->m_curframe / this->m_animationCols) * m_frameSize.y;

        m_sprite.setTextureRect(sf::IntRect(fx, fy, m_frameSize.x, m_frameSize.y));

        this->m_Transform();

        // Only draw if sprite is set as visible
        if(getVisible())
            g_pEngine->getDevice()->draw(m_sprite);
        //g_pEngine->getDevice()->draw(m_sprite);
    }

    void Sprite::Move(float elapsedTime)
    {
        // no movement timer -- move at CPU speed
        this->setPosition(this->getPosition().x + (this->getVelocity().x * elapsedTime),
                              this->getPosition().y + (this->getVelocity().y * elapsedTime));
    }

    void Sprite::Animate()
    {
        // update frame based on animation direction
        if(m_useFrameTimer)
        {
            if(m_frametimer.getElapsedTime().asMilliseconds() > m_frameDelay)
            {
                m_frametimer.restart();

                m_curframe += m_animdir;

                // Keep frame withing bounds
                if(m_curframe < (int)m_startframe)
                    m_curframe = m_totalframes - 1;
                else if(m_curframe > m_totalframes - 1)
                    m_curframe = m_startframe;

            }
        }
        else
        {
            // Animate at CPU speed, not recomended
            m_curframe += m_animdir;

            // Keep frame withing bounds
            if(m_curframe < 0)
                m_curframe = m_totalframes - 1;
            else if(m_curframe > m_totalframes - 1)
                m_curframe = 0;
        }
    }
};
