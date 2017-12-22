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
    virtual Color3 sample(const Ray3& ray,const LightRay3* light, const float distance,const Vector3& normal)=0;
    float reflectivity;
    float trace_reflectivity;
    float refractivity;
    float n;
    Color3 ambient;
    void set_trace_ref(float f){trace_reflectivity = f;}
};


#endif //RAY_TRACER_MATERIAL_H
