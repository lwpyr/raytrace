//
// Created by liwen on 12/20/17.
//

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H


#include "Object.h"

class Sphere: public Object {
public:
    Sphere()= default;
    Sphere(Vector3 center,double radius);
    Sphere(const Sphere& s) = default;
    virtual Vector3 getNormal(Vector3 point);
    virtual Intersection isIntersected(const Ray3& RAY);
    virtual ~Sphere()= default;
private:
    Vector3 center;
    double radius;
};


#endif //RAY_TRACER_SPHERE_H
