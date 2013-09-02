#ifndef _DRAWABLEGROUP_H_
#define _DRAWABLEGROUP_H_

#include <Engine.h>

// c types
#include <cstddef>
#include <list>

namespace SuperEngine
{

    class DrawableGroup: public std::list<Drawable*>
    {
    private:

    public:
        // Default constructor
        DrawableGroup(): std::list<Drawable*>() { }

        // Constructor that creates group using size and type
        // Must be explicitly invoked
        explicit DrawableGroup(size_type n, Drawable* val)
            : std::list<Drawable*>(n, val)
        { }

//        // Add a drawable
//        void Add(Drawable* drawable)
//        {
//            // Group has reached maximum size
//            if(m_avail == m_limit)
//                m_grow();
//            m_unchecked_append(drawable);
//        }

        // Remove a drawable from group and return it to caller
        Drawable* remove(const Drawable* sought);
        Drawable* remove(iterator it);

        // Checks if group contains drawable
        bool Contains(const Drawable* sought);

        // Call update method on contained Drawables
        virtual void Update(float elapsedTime);

         // draw all drawables contained in here
        virtual void Draw();

        // Destructor
        ~DrawableGroup() {}
    };

    DrawableGroup drawablecollide(Drawable*, DrawableGroup*, bool kill = true,
                                           bool(*collided)(Drawable*, Drawable*) = 0);
};

#endif // _DRAWABLEGROUP_H_
