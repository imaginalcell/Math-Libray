#pragma once
#include <cmath>
#include <cassert>
#include <cfloat>
#define EPSILON 0.0001f

struct Vector2
{
    float x, y;

    Vector2() {}
    Vector2(float a_x, float a_y)
        : x(a_x), y(a_y) {}

    float magnitude() const { return sqrtf(x*x + y*y); }

    static Vector2 fromAngle(float a)
    {
        return{ cosf(a), sinf(a) };
    }
};

// Direction Between Vectors:
    //(A-B).normal()
// Distance Between Vectors:
    //(A-B).magnitude()

inline Vector2 operator+(const Vector2  &lhs, const Vector2 &rhs)
{
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}
inline Vector2 operator+=(Vector2 &lhs, const Vector2 &rhs)
{
	return Vector2(lhs.x += rhs.x, lhs.y += rhs.y);
}
inline Vector2 operator-(const Vector2  &lhs, const Vector2 &rhs)
{
    return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}
inline Vector2 operator-=(Vector2 &lhs, const Vector2 &rhs)
{
	return Vector2(lhs.x -= rhs.x, lhs.y -= rhs.y);
}

inline Vector2 operator/(const Vector2 &lhs, float rhs)
{
    return Vector2(lhs.x / rhs, lhs.y / rhs);
}
inline Vector2 operator/=(Vector2 &lhs, float rhs)
{
	return Vector2(lhs.x /= rhs, lhs.y /= rhs);
}
inline Vector2 operator*(const Vector2 &lhs, float rhs)
{
    return Vector2(lhs.x * rhs, lhs.y * rhs);
}
inline Vector2 operator*=(Vector2 &lhs, float rhs)
{
	return Vector2(lhs.x *= rhs, lhs.y *= rhs);
}

inline bool operator==(const Vector2 &lhs, const Vector2 &rhs)
{
    // return lhs.x == rhs.x && lhs.y == rhs.y;
    return
    rhs.x - FLT_EPSILON < lhs.x && lhs.x < rhs.x + FLT_EPSILON &&
    rhs.y - FLT_EPSILON < lhs.y && lhs.y < rhs.y + FLT_EPSILON;

    //return fabsf(rhs.x - lhs.x) < FLT_EPSILON &&
    //       fabsf(rhs.y - lhs.y) < FLT_EPSILON;
}
inline bool operator!=(const Vector2 &lhs, const Vector2 &rhs)
{
	return;
}
inline bool operator<(const Vector2 &lhs, const Vector2 &rhs)
{

}
inline bool operator <=(const Vector2 &lhs, const Vector2 &rhs)
{

}

inline Vector2 normal(Vector2 &a)
{
    //assert(magnitude() != 0 && "Divide by Zero");
    return a / a.magnitude();
}
// Dot production tells us how much one vector extends
// in the direction of another vector
inline float dot(const Vector2 &lhs, const Vector2 &rhs)
{
	return lhs.x * rhs.x + rhs.y * lhs.y;
}

inline Vector2 perp(const Vector2  &a)
{
	return Vector2(-a.y, a.x);
}