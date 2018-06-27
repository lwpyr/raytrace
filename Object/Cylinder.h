//
// Created by liwen on 6/26/18.
//

#include "Object.h"

#ifndef RAY_TRACER_CYLINDER_H
#define RAY_TRACER_CYLINDER_H


class Cylinder : public Object{
public:
    Cylinder()= default;
    Cylinder(Vector3 center, Vector3 axis, double radius, double height);
    Cylinder(Cylinder& s) = default;
    double getCenterDist(const Vector3& );
    virtual Vector3 getNormal(Vector3 point);
    virtual Intersection isIntersected(const Ray3& RAY);
    virtual ~Cylinder()= default;
private:
    Vector3 center;
    Vector3 axis;
    double radius;
    double height;
};


#endif //RAY_TRACER_CYLINDER_H
