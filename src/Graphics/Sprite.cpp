#include "Engine.h"

namespace SuperEngine
{
    Sprite::Sprite()
        : Drawable()
    {
        Init();
    }

    bool Sprite::Init()
    {
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
        this->m_frameSize = sf::Vector2f(1.0f, 1.0f);

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

    bool Sprite::genSprite(const sf::Texture& texture, unsigned int animationCols, unsigned int animationRows)
    {
        if(m_animationCols <= 1 && m_animationRows <= 1)
        {
            this->setColumns(animationCols);
            this->setRows(animationRows);
        }

        m_sprite = sf::Sprite(texture);

        this->m_frameSize.x = (float) texture.getSize().x / (float) this->m_animationCols;
        this->m_frameSize.y = (float) texture.getSize().y / (float) this->m_animationRows;

        if(m_totalframes == 1)
            m_totalframes = m_animationCols * m_animationRows;

        // Set color to the color of the sprite
        this->setColor(m_sprite.getColor());

        return true;
    }

    bool Sprite::loadImage(const std::string& filename, unsigned int animationCols, unsigned int animationRows, const sf::Color& transcolor)
    {
        // using filenames as id's, for now anyway

        // Create a temp image with colormask
        if(!g_pEngine->getTextureManager().exists(filename))
        {
            sf::Image tempImage;

            if(!tempImage.loadFromFile(filename))
            {
                Logger::getInstance() << WARN << "Sprite::loadImage - Failed to load image " << filename << std::endl;

                return false;
            }

            g_pEngine->getTextureManager().load(filename, tempImage);
        }

        // Get the texture from storage
        sf::Texture& texture = g_pEngine->getTextureManager().get(filename);

        if(!this->genSprite(texture, animationCols, animationRows))
            return false;

        return true;
    }

    bool Sprite::setImage(const sf::Texture& image, unsigned int animationCols, unsigned int animationRows)
    {
        // We did not load the image, so we are not responsible for
        // handling its allocation and deletion
        if(!this->genSprite(image, animationCols, animationRows))
            return false;

        return true;
    }


    void Sprite::m_Transform()
    {
        // Maybe do some origin calculations
        m_sprite.setOrigin(m_frameSize.x / 2, m_frameSize.y / 2);

        // Perform simple image transformations
        m_sprite.setScale(this->m_scale);
        m_sprite.setRotation(this->getRotation());
        // Don't know if i'll keep this
        m_sprite.setPosition(this->getPosition());

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

    void Sprite::Update(float elapsedTime)
    {
        // no movement timer -- move at CPU speed
//        this->setPosition(this->getPosition().x + (this->getVelocity().x * elapsedTime),
//                              this->getPosition().y + (this->getVelocity().y * elapsedTime));
        this->setPosition(this->getPosition() + (this->getVelocity() * elapsedTime));
    }

    void Sprite::Animate()
    {
        // TODO (slacker#9#): Allow automatic animation


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
