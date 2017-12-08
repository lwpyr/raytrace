//
// Created by liwen on 17-12-8.
//

#ifndef RAY_TRACER_DEFAULTMATERIAL_H
#define RAY_TRACER_DEFAULTMATERIAL_H

#include "Material.h"

class DefaultMaterial: public Material {
public:
    DefaultMaterial();
    virtual ~DefaultMaterial() = default;
    virtual Color3 sample(const Ray3& ray,const LightRay3& light, const Vector3& position,const Vector3& normal);
};


#endif //RAY_TRACER_DEFAULTMATERIAL_H
