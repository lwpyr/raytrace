//
// Created by liwen on 12/8/17.
//

#ifndef RAY_TRACER_SUNLIGHT_H
#define RAY_TRACER_SUNLIGHT_H

#include "LightSource.h"

class SunLight: public LightSource {
private:
    Vector3 direction;
public:
    SunLight(const Vector3& dir, const Color3& c);
    virtual ~SunLight() = default;
    virtual LightRay3* traceLight(Vector3 v);
    virtual Vector3 getNormal(Vector3 point);
};


#endif //RAY_TRACER_SUNLIGHT_H
