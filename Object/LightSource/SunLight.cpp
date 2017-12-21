//
// Created by liwen on 12/8/17.
//

#include "SunLight.h"

SunLight::SunLight(const Vector3 &dir, const Color3& c) {
    direction = dir.normalize();
    color = c;
}

LightRay3* SunLight::traceLight(Vector3 v) {
    LightRay3* p = new LightRay3(v,-direction,color);
    return p;
}

Vector3 SunLight::getNormal(Vector3 point) {
    return Vector3(0,0,0);
}