#include "Engine.h"

#define GET_ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))

namespace SuperEngine
{
    enum CollisionType
    {
        COLLISION_NONE,
        COLLISION_RECT,
        COLLISION_DIST
    };

    class Sprite: public Drawable
    {
    private:

        bool m_visible;
        bool m_alive;

        int m_lifeTimeLength;
        sf::Clock m_lifeTimeTimer;
        //int spriteType;

        int m_state;

        sf::Color m_color;

    protected:
        sf::Sprite m_sprite;

        bool m_useFrameTimer;
        // Delay before moving and frame animation is performed in milli-seconds
        int m_frameDelay;

        sf::Clock m_frametimer;

        sf::Vector2f m_frameSize;

        int m_animationCols;
        int m_animationRows;

        bool m_collidable;
        enum CollisionType m_collisionMethod;

        int m_curframe, m_totalframes, m_animdir;
        float m_faceangle, m_moveangle;
        int m_animstartx, m_animstarty;

        sf::Vector2f m_scale;
        // Frame at which animation will start from
        unsigned int m_startframe;

        void m_Transform();

        bool genSprite(const sf::Texture& texture, unsigned int animationCols, unsigned int animationRows);

    public:

        // Image size
        sf::Vector2f getFrameSize() const { return m_frameSize; }
        void setFrameSize(const sf::Vector2f& val) { m_frameSize = val; }
        void setFrameSize(float x, float y) { m_frameSize.x = x; m_frameSize.y = y; }

        bool getVisible() const { return m_visible; }
        void setVisible(bool val) { m_visible = val; }

        bool isAlive() const { return m_alive; }
        void setAlive(bool val) { m_alive = val; }

        int getState() const { return m_state; }
        void setState(int val) { m_state = val; }

        int getColumns() const { return m_animationCols; }
        void setColumns(int val) { m_animationCols = val; }
        int getRows() const { return m_animationRows; }
        void setRows(int val) { m_animationRows = val; }

        int getCurrentFrame() const { return m_curframe; }
        void setCurrentFrame(int val) { m_curframe = val; }

        int getFrameStart() const { return m_startframe; }
        void setFrameStart(unsigned int val) { m_startframe = val; }

        int getTotalFrames() const { return m_totalframes; }
        void setTotalFrames(int val) { m_totalframes = val; }

        int getAnimationDir() const { return m_animdir; }
        void setAnimationDir(int val) { m_animdir = val; }

        sf::Vector2f getScale() const { return m_scale; }
        void setScale(float x, float y) { m_scale = sf::Vector2f(x, y); }
        void setScale(float val) { setScale(val, val); }
        void setScale(sf::Vector2f val) { m_scale = val; }

        void setColor(const sf::Color& color) { m_color = color; }
        void setColor(float r, float g, float b, float a) { m_color = sf::Color(r, g, b, a); }
        sf::Color getColor() const { return m_color; }


        bool isCollidable() const { return m_collidable; }
        void setCollidable(bool value) { m_collidable = value; }

        CollisionType getCollisionMethod() const { return m_collisionMethod; }
        void setCollisionMethod(CollisionType type) { m_collisionMethod = type; }

        // Timers
        bool isFrameTimer() const { return m_useFrameTimer; }
        void setFrameTimer(bool val) { m_useFrameTimer = true; }

        // Timer Delay
        void setFrameDelay(int val)  { m_frameDelay = val; }
        int getFrameDelay() const { return m_frameDelay; }

        // Debugging
        const sf::Sprite* getSprite() const { return &m_sprite; }

        // Main methods
        Sprite();
        virtual ~Sprite();

        bool Init();

        bool loadImage(const std::string& filename, unsigned int animationCols = 1, unsigned int animationRows = 1,
                       const sf::Color& transcolor = sf::Color(255, 0, 255));
        bool setImage(const sf::Texture&, unsigned int animationCols = 1, unsigned int animationRows = 1);

        void Update(float elapsedTime) final;
        void Animate();
        void Draw() final;
    };
};
