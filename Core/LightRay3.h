//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_LIGHTRAY3_H
#define RAY_TRACER_LIGHTRAY3_H

#include "Ray3.h"
#include "Color3.h"

class LightRay3: public Ray3 {
public:
    Color3 color;
    LightRay3(Vector3 origin, Vector3 dir, Color3 color);
    LightRay3(Ray3 ray, Color3 color);
};


#endif //RAY_TRACER_LIGHTRAY3_H
