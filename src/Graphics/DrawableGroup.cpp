#include <Engine.h>
#include <math.h>

namespace SuperEngine
{
    bool DrawableGroup::Contains(const Drawable* sought)
    {
        auto it = std::find(this->begin(), this->end(), sought);

        if(it != this->end())
            return true;

        return false;
    }

    Drawable* DrawableGroup::remove(const Drawable* sought)
    {
        auto it = std::find(this->begin(), this->end(), sought);

        if(it == this->end())
            return NULL;


        Drawable* retval = *it;

        // Remove from list
        erase(it);

        return retval;
    }

    Drawable* DrawableGroup::remove(iterator it)
    {
        Drawable* retval = *it;

        erase(it);

        return retval;
    }

    void DrawableGroup::Draw()
    {
        for(auto it = begin(); it != end(); ++it)
            (*it)->Draw();
    }

    void DrawableGroup::Update(float elapsedTime)
    {
        for(auto it = begin(); it != end(); ++it)
            (*it)->Update(elapsedTime);
    }

    DrawableGroup drawablecollide(Drawable* drawable, DrawableGroup* group,
                                           bool kill, bool(*collided)(Drawable*, Drawable*))
    {
        DrawableGroup collidedDrawables;

        for(auto it = group->begin(); it != group->end(); ++it)
        {
            if(collided != 0)
            {
                if(collided(drawable, (*it)))
                {
                    collidedDrawables.push_back(*it);
                }
            }
            else if(drawable->getCollisionMethod() != COLLISION_NONE &&
                    (*it)->getCollisionMethod() != COLLISION_NONE)
            {
                if(drawable->getCollisionMethod() == COLLISION_RECT)
                {
                    if((abs(drawable->getX() - (*it)->getX()) * 2 < (drawable->getSize().x + (*it)->getSize().x)) &&
                       (abs(drawable->getY() - (*it)->getY()) * 2 < (drawable->getSize().y + (*it)->getSize().y)))
                    {
                        // Bounding box collision has occured
                        collidedDrawables.push_back(*it);

                        if(kill)
                            group->remove(it);
                    }
                }
                else if(drawable->getCollisionMethod() == COLLISION_DIST)
                {
                    // distance based collision
                }
            }
        }

        return collidedDrawables;
    }
};
