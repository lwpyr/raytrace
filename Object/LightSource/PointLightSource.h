//
// Created by liwen on 12/21/17.
//

#ifndef RAY_TRACER_POINTLIGHTSOURCE_H
#define RAY_TRACER_POINTLIGHTSOURCE_H

#include "LightSource.h"

class PointLightSource: public LightSource {
private:
    Vector3 center;
public:
    PointLightSource(const Vector3& cen, const Color3& c);
    virtual ~PointLightSource() = default;
    virtual LightRay3* traceLight(Vector3 v);
    virtual Vector3 getNormal(Vector3 point);
};


#endif //RAY_TRACER_POINTLIGHTSOURCE_H
