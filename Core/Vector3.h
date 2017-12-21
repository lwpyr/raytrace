//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_VECTOR3_H
#define RAY_TRACER_VECTOR3_H

#include <cmath>
#include <iostream>
#define PI 3.1415926
#define MIN(x,y) (x)>(y)?(y):(x);
#define MAX(x,y) (x)>(y)?(x):(y);

class Vector3 {
public:
    // constructor and destructor
    Vector3() = default;
    Vector3(float X, float Y, float Z);
    Vector3(const Vector3& v);
    ~Vector3() = default;

    // vector plus vector
    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;

    // vector times scalar
    Vector3 operator*(const float& n) const;
    friend Vector3 operator*(const float& n, const Vector3& v);

    // vector divide scalar
    Vector3 operator/(const float& n) const;
    friend Vector3 operator/(const float& n, const Vector3& v);

    // vector dot product
    float operator*(const Vector3& v2) const;

    // vector cross product
    Vector3 operator^(const Vector3& v2) const;

    // absolute
    Vector3 abs() const;

    // maximum element
    float max() const;

    // minimum element
    float min() const;

    // sqrt(v.x^2+v.y^2+v.z^2)
    float getLength() const;

    // normalize the length to 1
    Vector3 normalize() const;

    // negate the vector
    Vector3 operator-() const;

    // calculate the distance between 2 vectors(points)
    float getDist(Vector3& v) const;

    // project
    Vector3 project(Vector3& v) const;

    // show
    friend std::ostream& operator<<(std::ostream&out, Vector3 &v);

    // x,y,z
    float x;
    float y;
    float z;
};


#endif //RAY_TRACER_VECTOR3_H
