//
// Created by liwen on 17-12-8.
//

#include "DefaultMaterial.h"

DefaultMaterial::DefaultMaterial() {
    reflectivity = 0.5;
    refractivity = 0;
    n = 1;
}

Color3 DefaultMaterial::sample(const Ray3& ray,const LightRay3& light, const Vector3& position,const Vector3& normal){
    Color3 resultColor(0,0,0);
    float NdotL= normal*light.getDirection();
    if (NdotL > 0)
        resultColor=resultColor + light.color*NdotL;
    return resultColor;
}
