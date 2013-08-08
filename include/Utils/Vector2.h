#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include <Engine.h>
#include <cmath>

// Just a bunch of helper functions
namespace SuperEngine
{
    template<typename T>
    T getVecDistance(sf::Vector2<T> v1, sf::Vector2<T> v2)
    {
        // Pythagoras was here 2k13
        return (T)sqrt((v2.x - v1.x) * (v2.x - v1.x) + (v2.y - v1.y) * (v2.y - v1.y));
    }

    // Get length from origin
    template<typename T>
    T getVecLength(sf::Vector2<T> v)
    {
        return (T)sqrt((v.x * v.x) + (v.y * v.y));
    }
};

#endif // _VECTOR2_H_
