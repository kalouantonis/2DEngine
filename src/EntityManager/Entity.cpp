#include "Entity.h"

Entity::Entity()
{
    desc = "";
    alive = true;
}

Entity::Entity(const std::string &d)
{
    desc = d;
    alive = true;
}

std::string Entity::getDesc()
{
    return desc;
}

void Entity::setDesc(const std::string &d)
{
    desc = d;
}


// Component functions

void Entity::printComps(std::ostream &os)
{
    for(std::list<Component *>::iterator it = comps.begin(); it != comps.end(); it++)
    {
        os<<*it<<"\n";
    }
}

void Entity::addComp(Component *c)
{
    comps.push_back(c);
}

/*
std::list<Component*>::iterator Entity::findComp(Component *sought)
{
    return find(comps.begin(), comps.end(), sought); // Return an iterator to the component sought
}

void Entity::removeComp(Component *elem)
{
    std::list<Component*>::iterator it = find(comps.begin(), comps.end(), *elem);
    comps.erase(it);
}
*/

