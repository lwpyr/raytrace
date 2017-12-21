//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_LIGHTRAY3_H
#define RAY_TRACER_LIGHTRAY3_H

#include "../../Core/Ray3.h"
#include "../../Core/Color3.h"

class LightRay3: public Ray3 {
public:
    LightRay3()= default;
    virtual Color3 get_color(float distance) const;
    LightRay3(Vector3 origin, Vector3 dir, Color3 color);
    LightRay3(Ray3 ray, Color3 color);


protected:
    Color3 color;

};


#endif //RAY_TRACER_LIGHTRAY3_H
