//
// Created by liwen on 6/25/18.
//

#ifndef RAY_TRACER_CIRCLE_H
#define RAY_TRACER_CIRCLE_H

#include "Object.h"

class Circle : public Object{
public:
    Circle() = default;
    Circle(Vector3 _center, double radius, Vector3 _normal): center(_center), radius(radius), normal(_normal){}
    virtual Vector3 getNormal(Vector3 point);
    virtual Intersection isIntersected(const Ray3& RAY);

private:
    Vector3 center;
    double radius;

    Vector3 normal;
};


#endif //RAY_TRACER_CIRCLE_H
