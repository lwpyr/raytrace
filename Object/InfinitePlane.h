//
// Created by liwen on 12/8/17.
//

#ifndef RAY_TRACER_INFINITEPLANE_H
#define RAY_TRACER_INFINITEPLANE_H

#include "Object.h"

class InfinitePlane: public Object {
private:
    Vector3 refPoint;
    Vector3 normal;
public:
    InfinitePlane(const Vector3& _refPoint, const Vector3& _normal);
    virtual ~InfinitePlane() = default;
    virtual Intersection isIntersected(const Ray3& RAY);
    virtual Vector3 getNormal(Vector3 point);
};


#endif //RAY_TRACER_INFINITEPLANE_H
