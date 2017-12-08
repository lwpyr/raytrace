//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_LIGHTSOURCE_H
#define RAY_TRACER_LIGHTSOURCE_H

#include "../../Core/LightRay3.h"
#include "../../Core/Color3.h"
#include "../Object.h"

class LightSource: public Object {
public:
    LightSource() = default;
    explicit LightSource(const Color3& _color):color(_color){}
    virtual ~LightSource() = default;
    virtual LightRay3 traceLight(Vector3& v)=0;
    Color3 color;
};


#endif //RAY_TRACER_LIGHTSOURCE_H
