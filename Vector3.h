#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <cmath>

namespace SuperEngine
{
    template <typename T>
    class Vector3
    {
    public:
        Vector3(): x(0), y(0), z(0) { }
        Vector3(T x, T y, T z):x(x), y(y), z(z) { }

        // Copy constructor
        Vector3(const Vector3& v)
        {
            *this = v;
        }

        void operator+=(const Vector3<T>& v)
        {
            x += v.x; y += v.y; z += v.z;
        }

        void operator-=(const Vector3<T>& v)
        {
            x -= v.x; y -= v.y; z -= v.z;
        }

        void operator*=(const Vector3<T>& v)
        {
             x *= v.x; y *= v.y; z *= v.z;
        }

        void operator/=(const Vector3<T>& v)
        {
            x /= v.x; y /= v.y; z /= v.z;
        }

        Vector3<T> operator+(const Vector3<T>& v)
        {
            return Vector2<T>(this->x + v.x, this->y + v.y, this->z + v.z);
        }

        Vector3<T> operator-(const Vector3<T>& v)
        {
            return Vector2<T>(this->x - v.x, this->y - v.y, this->z - v.z);
        }

        Vector3<T> operator/(const Vector3<T>& v)
        {
            return Vector2<T>(this->x / v.x, this->y / v.y, this->z / v.z);
        }

        Vector3<T> operator*(const Vector3<T>& v)
        {
            return Vector2<T>(this->x * v.x, this->y * v.y, this->z * v.z);
        }


        // equality operator involves double rounding
        bool operator==(const Vector3<T>& v) const
        {
            double accuracy = 0.0001f;

            return (
                (((v.x - accuracy) < x) && (x < (v.x + accuracy))) &&
                (((v.y - accuracy) < y) && (y < (v.y + accuracy)) &&
                (((v.z - accuracy) < z) && (z < (v.z + accuracy))))
            );
        }

        bool operator!=(const Vector3<T>& v) const
        {
            return(!(*this == v));
        }

        // assignment op
        Vector3<T>& operator=(const Vector3<T>& v)
        {
            this->x = v.x;
            this->y = v.y;
            this->z = v.z;

            return *this;
        }

        T distance(const Vector3<T>& v)
        {
            // Pythagoras was here, 2k13
            return (T)sqrt((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y) + (v.z + z) * (v.z + z));
        }

        // calculate length from the origin
        T length()
        {
            return (T)sqrt(x * x + y * y + z * z);
        }


        Vector3<T> normal()
        {
            // Check this, pretty sure its completelly wrong
            T vlength = length() == 0 ? 0 : 1 / length();

            T nx = x * vlength;
            T ny = y * vlength;
            T nz = z * vlength;

            return Vector3<T>(nx, ny, nz);
        }

        T x, y, z;
    };

    typedef Vector3<float> Vector3f;
    typedef Vector3<double> Vector3d;
    typedef Vector3<int> Vector3i;
    typedef Vector3<unsigned int> Vector3u;
};

#endif // _VECTOR3_H_
