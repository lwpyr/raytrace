//
// Created by liwen on 6/27/18.
//

#ifndef RAY_TRACER_SQUARE_H
#define RAY_TRACER_SQUARE_H

#include "Object.h"

class Square : public Object {
private:
    Vector3 refPoint;
    Vector3 normal;
    Vector3 side1;
    Vector3 side2;
    double side1L;
    double side2L;
public:
    Square(const Vector3& _refPoint, const Vector3 & _normal, const Vector3& _side1, const Vector3& _side2, double _side1L, double _side2L);
    virtual ~Square() = default;
    virtual Intersection isIntersected(const Ray3& RAY);
    virtual Vector3 getNormal(Vector3 point);
};


#endif //RAY_TRACER_SQUARE_H
