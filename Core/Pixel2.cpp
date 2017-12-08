//
// Created by liwen on 17-12-7.
//

#include "Pixel2.h"

void Pixel2::operator+(Color3 lightColor){
    color += lightColor;
    ray_count += 1;
}

void Pixel2::average() {
    color/=ray_count;
    color.saturate();
}
