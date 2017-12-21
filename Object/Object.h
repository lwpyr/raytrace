//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_OBJECT_H
#define RAY_TRACER_OBJECT_H

#include "../Core/Ray3.h"
#include "Material/Material.h"
#include "../Intersection.h"

class Object {
public:
    Object() = default;
    virtual ~Object() = default;
    virtual Intersection isIntersected(const Ray3& RAY){
        return Intersection();
    };
    virtual Vector3 getNormal(Vector3 point)=0;
    Material* material;
};

#endif //RAY_TRACER_OBJECT_H
