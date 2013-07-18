#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include <cmath>

namespace SuperEngine
{
    template<typename something>
    class Vector2
    {
    public:
        Vector2() { }
        Vector2(something x, something y) {  }

        Vector2(const Vector2<something>& v) { *this = v; }

        void operator+=(const Vector2<something>& v)
        {
            x += v.x; y += v.y;
        }

        void operator-=(const Vector2<something>& v)
        {
            x -= v.x; y -= v.y;
        }

        void operator*=(const Vector2<something>& v)
        {
             x *= v.x; y *= v.y;
        }

        void operator/=(const Vector2<something>& v)
        {
            x /= v.x; y /= v.y;
        }

        // equality operator involves double rounding
        bool operator==(const Vector2<something>& v) const
        {
            double accuracy = 0.0001f;

            return (
                (((v.x - accuracy) < x) && (x < (v.x + accuracy))) &&
                (((v.y - accuracy) < y) && (y < (v.y + accuracy)))
            );
        }

        bool operator!=(const Vector2<something>& v) const
        {
            return(!(*this == v));
        }

        // assignment op
        Vector2<something>& operator=(const Vector2<something>& v)
        {
            this->x = v.x;
            this->y = v.y;

            return *this;
        }

        something distance(const Vector2<something>& v)
        {
            // Pythagoras was here, 2k13
            return (something)sqrt((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y));
        }

        // calculate length from the origin
        something length()
        {
            return sqrt(x * x + y * y);
        }


        Vector2<something> normal()
        {
            something vlength = length() == 0 ? 0 : 1 / length();

            something nx = x * vlength;
            something ny = y * vlength;

            return Vector2<something>(nx, ny);
        }

        something x, y;
    };

    typedef Vector2<int> Vector2i;
    typedef Vector2<float> Vector2f;
    typedef Vector2<unsigned int> Vector2u;
    typedef Vector2<double> Vector2d;
};

#endif // _VECTOR2_H_
