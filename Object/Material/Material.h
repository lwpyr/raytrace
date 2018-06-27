//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_MATERIAL_H
#define RAY_TRACER_MATERIAL_H

#include "../Light/LightRay3.h"

class Material {
public:
    Material() = default;
    virtual ~Material() = default;
    virtual Color3 sample(const Ray3& ray,const LightRay3* light, const double distance,const Vector3& normal)=0;
    double reflectivity;
    double trace_reflectivity;
    double refractivity;
    double trace_refractivity;
    double n;
    Color3 ambient;
};


#endif //RAY_TRACER_MATERIAL_H
