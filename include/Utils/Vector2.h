#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include <Engine.h>

#include <cmath>

namespace SuperEngine
{
    template<typename T>
    class Vector2
    {
    public:
        Vector2(): x(0), y(0) { }
        Vector2(T x, T y): x(x), y(y) {  }

        Vector2(const Vector2<T>& v) { *this = v; }

        void operator+=(const Vector2<T>& v)
        {
            x += v.x; y += v.y;
        }

        Vector2<T> operator+(const Vector2<T>& v)
        {
            return Vector2<T>(this->x + v.x, this->y + v.y);
        }

        Vector2<T> operator-(const Vector2<T>& v)
        {
            return Vector2<T>(this->x - v.x, this->y - v.y);
        }

        Vector2<T> operator/(const Vector2<T>& v)
        {
            return Vector2<T>(this->x / v.x, this->y / v.y);
        }

        Vector2<T> operator*(const Vector2<T>& v)
        {
            return Vector2<T>(this->x * v.x, this->y * v.y);
        }

        void operator-=(const Vector2<T>& v)
        {
            x -= v.x; y -= v.y;
        }

        void operator*=(const Vector2<T>& v)
        {
             x *= v.x; y *= v.y;
        }

        void operator/=(const Vector2<T>& v)
        {
            x /= v.x; y /= v.y;
        }

        // equality operator involves double rounding
        bool operator==(const Vector2<T>& v) const
        {
            double accuracy = 0.0001f;

            return (
                (((v.x - accuracy) < x) && (x < (v.x + accuracy))) &&
                (((v.y - accuracy) < y) && (y < (v.y + accuracy)))
            );
        }

        bool operator!=(const Vector2<T>& v) const
        {
            return(!(*this == v));
        }

        // assignment op
        Vector2<T>& operator=(const Vector2<T>& v)
        {
            this->x = v.x;
            this->y = v.y;

            return *this;
        }

        T distance(const Vector2<T>& v)
        {
            // Pythagoras was here, 2k13
            return (T)sqrt((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y));
        }

        // calculate length from the origin
        T length()
        {
            return (T)sqrt(x * x + y * y);
        }


        Vector2<T> normal()
        {
            T vlength = length() == 0 ? 0 : 1 / length();

            T nx = x * vlength;
            T ny = y * vlength;

            return Vector2<T>(nx, ny);
        }

        T x, y;
    };

    typedef Vector2<int> Vector2i;
    typedef Vector2<float> Vector2f;
    typedef Vector2<unsigned int> Vector2u;
    typedef Vector2<double> Vector2d;
};

#endif // _VECTOR2_H_
