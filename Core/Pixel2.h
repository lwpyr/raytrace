//
// Created by liwen on 17-12-7.
//

#ifndef RAY_TRACER_PIXEL2_H
#define RAY_TRACER_PIXEL2_H

#include "Color3.h"

class Pixel2 {
public:
    Pixel2() = default;
    ~Pixel2() = default;
    void operator+(Color3 lightColor);
    void average();
private:
    unsigned int ray_count = 0;
    Color3 color = Color3(0,0,0);
};


#endif //RAY_TRACER_PIXEL2_H
