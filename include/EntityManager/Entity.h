#include <iostream>
#include <string>
#include <list>
#include <algorithm>

class Component;

class Entity
{
private:
    std::string desc;
    std::string id;
    std::list<Component*> comps; // A list that contains all the components
    bool alive;

public:

    // Constructor
    Entity();
    Entity(const std::string&);

    std::string getDesc();
    void setDesc(const std::string&);

    // Component operations
    void printComps(std::ostream&);
    void addComp(Component*);
  //  void removeComp(Component*);

    //std::list<Component*>::iterator findComp(Component*); // Retrievs an pointer to the component
    // Might need to overload and add aditional finding patterns
};
