//
// Created by liwen on 12/21/17.
//

#include "PointLightSource.h"
#include "../Light/PointLightRay3.h"

PointLightSource::PointLightSource(const Vector3 &cen, const Color3& c) {
    center = cen;
    color = c;
}

LightRay3* PointLightSource::traceLight(Vector3 v) {
    //max_distance = (center-v).getLength();
    //PointLightRay3* p = new PointLightRay3(v,center-v,color);
    LightRay3* p = new LightRay3(v,center-v,color);
    p->max_distance = (center-v).getLength();
    return p;
    //return LightRay3(v,center-v,color);
}


Vector3 PointLightSource::getNormal(Vector3 point) {
    return Vector3(0,0,0);
}