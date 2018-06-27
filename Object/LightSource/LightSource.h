//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_LIGHTSOURCE_H
#define RAY_TRACER_LIGHTSOURCE_H

#include "../Light/LightRay3.h"
#include "../../Core/Color3.h"
#include "../Object.h"

class LightSource: public Object {
public:
    LightSource() = default;
    explicit LightSource(const Color3& _color):color(_color){}
    virtual ~LightSource() = default;
    virtual LightRay3* traceLight(Vector3 v)=0;
    void setHost(Object * h){
        host = h;
    }
    Color3 color;
    Object * host;
    virtual Intersection isIntersected(const Ray3& RAY){
        if(!RAY.direct)
            return Intersection();
        else
            return host->isIntersected(RAY);
    };
};


#endif //RAY_TRACER_LIGHTSOURCE_H
