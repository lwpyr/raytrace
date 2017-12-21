//
// Created by liwen on 12/21/17.
//

#ifndef RAY_TRACER_POINTLIGHTRAY3_H
#define RAY_TRACER_POINTLIGHTRAY3_H

#include "LightRay3.h"

class PointLightRay3: public LightRay3{
public:
    virtual Color3 get_color(float distance) const;
    PointLightRay3(Vector3 origin, Vector3 dir, Color3 color):LightRay3(origin, dir, color){}
    PointLightRay3(Ray3 ray, Color3 color):LightRay3(ray, color){}

};


#endif //RAY_TRACER_POINTLIGHTRAY3_H
