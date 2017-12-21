//
// Created by liwen on 12/20/17.
//

#ifndef RAY_TRACER_TRIANGLE_H
#define RAY_TRACER_TRIANGLE_H


#include "../Core/Vector3.h"
#include "Object.h"

class Triangle: public Object {
public:
    Triangle(Vector3 v1, Vector3 v2, Vector3 v3);
    virtual ~Triangle()= default;
    virtual Vector3 getNormal(Vector3 point);
    virtual Intersection isIntersected(const Ray3& RAY);

private:
    // 3 corners
    Vector3 p1;
    Vector3 p2;
    Vector3 p3;

    //
    Vector3 normal;
};


#endif //RAY_TRACER_TRIANGLE_H
