#include "Entity.h"

class EntityManager
{
private:
    static std::list<Entity> ents;
    static int entsCount;

public:
    void Add(Entity&);
    void Remove();


};
