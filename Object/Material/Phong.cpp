//
// Created by liwen on 12/8/17.
//

#include "Phong.h"
#include <algorithm>

Phong::Phong(const Color3 &_diffuse, const Color3 &_specular, double _shininess, double reflect, double refract) {
    diffuse = _diffuse;
    specular = _specular;
    shininess = _shininess;
    reflectivity = reflect;
    refractivity = refract;
}

Color3 Phong::sample(const Ray3 &ray, const LightRay3 *light, const double distance, const Vector3 &normal) {
    Vector3 lightDir = light->getDirection();
    double NdotL = normal*lightDir;
    Vector3 H = (lightDir-ray.getDirection()).normalize();
    double NdotH = normal*H;
    Color3 diffuseTerm = this->diffuse*std::max(NdotL, (double)0);
    Color3 specularTerm = this->specular*(pow(std::max(NdotH, (double)0), this->shininess));
    return light->get_color(distance)*(diffuseTerm+specularTerm);
}