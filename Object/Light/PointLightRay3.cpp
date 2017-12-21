//
// Created by liwen on 12/21/17.
//

#include "PointLightRay3.h"

Color3 PointLightRay3::get_color(float distance) const{
    return color/(1+distance*distance/200);
}