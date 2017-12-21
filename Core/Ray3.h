//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_RAY3_H
#define RAY_TRACER_RAY3_H

#include "Vector3.h"

class Ray3
{
public:
    Vector3 origin;
    Vector3 direction;

    // constructor and destructor
    Ray3() = default;
    Ray3(const Vector3& o, const Vector3& d);
    ~Ray3() = default;

    // set ray origin
    void setOrigin(const Vector3& o);

    // set ray direction
    void setDirection(const Vector3& d);

    // reverse
    Ray3 operator-();

    // utils
    Vector3 getOrigin() const;
    Vector3 getDirection() const;
    Vector3 getPoint(const double& t) const;

    float max_distance = 100000000;

};


#endif //RAY_TRACER_RAY3_H
