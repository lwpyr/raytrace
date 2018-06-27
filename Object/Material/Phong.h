//
// Created by liwen on 12/8/17.
//

#ifndef RAY_TRACER_PHONG_H
#define RAY_TRACER_PHONG_H

#include "Material.h"

class Phong: public Material {
public:
    Phong(const Color3& _diffuse,const Color3& _specular, double shininess,double reflect = 0.4, double refract = 0);
    ~Phong() = default;
    virtual Color3 sample(const Ray3& ray,const LightRay3* light, const double distance,const Vector3& normal);

private:
    Color3   diffuse;
    Color3   specular;
    double   shininess;
};


#endif //RAY_TRACER_PHONG_H
