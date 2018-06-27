//
// Created by liwen on 17-12-8.
//

#include "DefaultMaterial.h"

DefaultMaterial::DefaultMaterial() {
    trace_reflectivity=0;
    reflectivity = 0;
    refractivity = 0;
    n = 1;
}

Color3 DefaultMaterial::sample(const Ray3& ray,const LightRay3* light, const double distance,const Vector3& normal){
    Color3 resultColor(0,0,0);
    double NdotL= normal*light->getDirection();
    if (NdotL > 0)
        resultColor=resultColor + light->get_color(distance)*NdotL;
    return resultColor+ambient;
}
