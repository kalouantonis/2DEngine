#include "Engine.h"

namespace SuperEngine
{
    Sprite::Sprite()
    {
        this->m_pImage = NULL;
        this->m_imageLoaded = false;
        this->setPosition(0.0f, 0.0f);
        this->setVelocity(0.0f, 0.0f);
        this->setState(1);
        this->setDirection(0);
        this->setCurrentFrame(1);
        this->setTotalFrames(1);
        this->setAnimationDir(1);
        this->m_animationCols = 1;
        this->m_useFrameTimer = true;
        this->setRows(1);

        this->m_animationCols = 1;
        this->m_animationRows = 1;
        this->m_frameSize = Vector2f(1.0f, 1.0f);

        this->setFrameTimer(0);
        this->m_animstartx = 0;
        this->m_animstarty = 0;
        this->m_faceangle = 0;
        this->m_moveangle = 0;
        this->setRotation(0);
        this->setScale(1.0f);

        // Tweak this to perfection
        this->setFrameDelay(16);
        this->setMoveDelay(16);

        // Should probably grab from game engine FPS, but i cant be sure
        // its initialized in the constructor
        //this->setMoveTimer(16);
        this->m_useMoveTimer = true;
        this->setCollidable(true);
        this->setCollisionMethod(COLLISION_RECT);

        this->setColor(sf::Color::Black);

        this->setVisible(true);
    }

    Sprite::~Sprite()
    {
        // If we loaded the image, if not, well
        // its not my problem.
        //I'm not going to lose sleep over it.
        if(m_imageLoaded)
            delete m_pImage;
    }

    bool Sprite::genSprite()
    {
        if(!this->m_texture.loadFromImage(*m_pImage))
        {
            std::cerr << "Image could not be loaded in to a texture, could be corrupt" << std::endl;
            return false;
        }

        m_sprite.setTexture(m_texture);

        this->m_frameSize.x = (float) m_pImage->getSize().x / (float) this->m_animationCols;
        this->m_frameSize.y = (float) m_pImage->getSize().y / (float) this->m_animationRows;

        // Set color to the color of the sprite
        this->setColor(m_sprite.getColor());

        return true;
    }

    bool Sprite::loadImage(const std::string& filename, int animationCols, int animationRows, const sf::Color& transcolor)
    {
        this->setColumns(animationCols);
        this->setRows(animationRows);

        // Need to actually implement color transparency, but i dont know how
        // to do it in SFML yet
        if(m_imageLoaded && m_pImage != NULL) delete m_pImage;

        // Create texture and load image
        m_pImage = new sf::Image();

        if(!m_pImage->loadFromFile(filename))
        {
            std::cerr << filename << " could not be loaded by image loader" << std::endl;
            return false;
        }

        // Set the mask color
        m_pImage->createMaskFromColor(transcolor);

        if(!this->genSprite())
            return false;

        m_imageLoaded = true;

        #ifdef _DEBUG
        std::cout << "Image " << filename << " successfully loaded." << std::endl;
        #endif // _DEBUG

        return true;
    }

     bool Sprite::setImage(sf::Image* image, int animationCols, int animationRows)
    {
        this->m_pImage = image;
        // We did not load the image, so we are not responsible for
        // handling its allocation and deletion

        if(!this->genSprite())
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

    void Sprite::Move()
    {
        if(m_useMoveTimer)
        {
            if(m_movetimer.getElapsedTime().asMilliseconds() > m_moveDelay)
            {
                m_movetimer.restart();

                // Move sprite by velocity amount
                this->setPosition(this->getPosition().x + this->getVelocity().x,
                                  this->getPosition().y + this->getVelocity().y);

            }
        }
        else
        {
            // no movement timer -- move at CPU speed
            this->setPosition(this->getPosition().x + this->getVelocity().x,
                                  this->getPosition().y + this->getVelocity().y);
        }
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
                if(m_curframe < 0)
                    m_curframe = m_totalframes - 1;
                else if(m_curframe > m_totalframes - 1)
                    m_curframe = 0;
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
