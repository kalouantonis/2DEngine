#include <Engine.h>

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
};
