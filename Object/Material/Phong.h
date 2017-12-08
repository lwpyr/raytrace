//
// Created by liwen on 12/8/17.
//

#ifndef RAY_TRACER_PHONG_H
#define RAY_TRACER_PHONG_H

#include "Material.h"

class Phong: public Material {
public:
    Phong(const Color3& _diffuse,const Color3& _specular, float shininess,float reflect = 0.5, float refract = 0);
    ~Phong() = default;
    virtual Color3 sample(const Ray3& ray,const LightRay3& light, const Vector3& position,const Vector3& normal);

private:
    Color3   diffuse;
    Color3   specular;
    float   shininess;
};


#endif //RAY_TRACER_PHONG_H
